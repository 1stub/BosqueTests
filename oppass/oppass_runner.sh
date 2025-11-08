#!/bin/bash

# Make sure these directories are correctly set!
cwd=$(pwd)
bosque=$cwd/../../BosqueCore
bsqir=$bosque/src/bsqir
cbsqir=$cwd/bsqir
cpp=$bosque/bin/src/cmd/analyzecpp.js

mini=$cwd/mini_irs.bsq

server=$(<$cwd/server.cpp)
headers=$(<$cwd/headers.hpp)

cppout=$cwd/cppout
src=$1

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
# (we should really understand this awk code a bit better)
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

testtmp=$(mktemp)
awk -v type="$type" '{sub("REPLACEME", type)}1' "$cppout/emit.cpp" > "$testtmp" && mv "$testtmp" "$cppout/emit.cpp"

cd $cppout
make clean
make
./output/memex