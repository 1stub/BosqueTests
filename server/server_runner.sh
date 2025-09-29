#!/bin/bash

#######################################
# Syntax: 
#     ./server_runner.sh server.bsq BUILD_TYPE TEST_TYPE
#
# i.e.
#     ./server_runner.sh server.bsq release mixed
#     ./server_runner.sh server.bsq dev db
#

# Make sure your directory is correctly set!
cwd=$(pwd)
bosque=$cwd/../../BosqueCore
cpp=$bosque/bin/src/cmd/analyzecpp.js

src=server.bsq
cppout=$cwd/cppout

build=dev
type=mixed

server=$(<$cwd/server.cpp)
headers=$(<$cwd/headers.hpp)

if [[ $2 == "release" ]]; then 
    build=release
fi

if [[ $# == 3 ]]; then
    type=$3
fi

function cleanup() {
    if [ -d $cppout ]; then 
        echo "Deleting old cppout files!"
        rm -rf $cppout 
    fi
}

cleanup

node $cpp $src

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
make BUILD=$build
./output/memex