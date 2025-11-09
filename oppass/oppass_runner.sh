#!/bin/bash

# Make sure these directories are correctly set!
cwd=$(pwd)
bosque=$cwd/../../BosqueCore
bsqir=$bosque/src/bsqir
cbsqir=$cwd/bsqir
cpp=$bosque/bin/src/cmd/analyzecpp.js

cppout=$cwd/cppout
common=$cppout/gc/src/runtime/common.h
makefile=$cppout/makefile

mini=$cwd/mini_irs.bsq

build=dev

server=$(<$cwd/server.cpp)
headers=$(<$cwd/headers.hpp)

src=$1

# Default run as monolith
iterations=1

if [[ $2 == "release" ]]; then 
    build=release
fi

if [[ $# == 3 ]]; then
    iterations=$3
fi

if [[ $# -eq 0 ]]; then
    echo "No source file provided!"
    exit 1
fi

function cleanup() {
    if [ -d $cppout ]; then 
        echo "Deleting old cppout files!"
        rm -rf $cppout 
    fi

    if [ -d $cbsqir ]; then 
        echo "Deleting old bsqir files!"
        rm -rf $cbsqir
    fi
}

cleanup

cp -R $bsqir $cwd
cp $mini $cbsqir

echo "Loading .bsq files from bsqir directory:"
bsqir_files=()
while IFS= read -r -d '' file; do
    echo "  - $file"
    bsqir_files+=("$file")
done < <(find bsqir -name "*.bsq" -type f -print0)

if [[ ${#bsqir_files[@]} -eq 0 ]]; then
    echo "Error: No .bsq files found in bsqir directory" >&2
    exit 1
fi

node $cpp $src ${bsqir_files[@]}

# Append necessary server headers
tmp=$(mktemp)
awk -v headers="$headers" '{sub("#include \"emit.hpp\"", headers)}1' "$cppout/emit.cpp" > "$tmp"
mv "$tmp" "$cppout/emit.cpp"

# Replace main with custom code 
srctmp=$(mktemp)
awk -v src="$server" '
    /__CoreCpp::[^ ]+ main\(\) noexcept  {/ {
        print src
        skip = 1
        next
    }
    skip && /^    }$/ {
        skip = 0
        next
    }
    !skip { print }
' "$cppout/emit.cpp" > "$srctmp" && mv "$srctmp" "$cppout/emit.cpp"

# Setup to be running with asserts off and packed metadata
# FS is input field separator (so nothing here), RS defines a line
# (record field separator)
commontmp=$(mktemp)
awk -v rmv="//#define BSQ_GC_CHECK_ENABLED\n//#define VERBOSE_HEADER" 'BEGIN { RS = ""; FS = "" } {
    gsub(/#define BSQ_GC_CHECK_ENABLED\n#define VERBOSE_HEADER/, rmv)
    print
}' "$common" > "$commontmp"
mv "$commontmp" "$common"


# Add iteration count
cpptmp=$(mktemp)
awk -v its="$iterations" '{sub("ITERATIONS", its)}1' "$cppout/emit.cpp" > "$cpptmp" 
mv "$cpptmp" "$cppout/emit.cpp"

# Release triggers incorrect infinite loop and array bounds errors so ignore them
mkrplmt="CFLAGS_OPT.release=-O2 -march=x86-64-v3 -Wno-infinite-recursion -Wno-array-bounds"
if [[ $build -eq "release" ]]; then 
    makefiletmp=$(mktemp)
    awk -v mkrp="$mkrplmt" '{sub("CFLAGS_OPT.release=-O2 -march=x86-64-v3", mkrp)}1' "$makefile" > "$makefiletmp"
    mv "$makefiletmp" "$makefile"
fi

cd $cppout
make clean
make BUILD=$build
./output/memex