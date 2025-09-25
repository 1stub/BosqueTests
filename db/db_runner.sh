#!/bin/bash

# Make sure these directories are correctly set!
cwd=$(pwd)
bosque=$cwd/../../BosqueCore
cpp=$bosque/bin/src/cmd/analyzecpp.js

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
}

cleanup

node $cpp $src

cd $cppout
make clean
make BUILD=release
./output/memex