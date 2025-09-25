#!/bin/bash

# Make sure your directory is correctly set!
cwd=$(pwd)
bosque=$cwd/../../BosqueCore
cpp=$bosque/bin/src/cmd/analyzecpp.js

src=$1
cppout=$cwd/cppout

if [[ $# -eq 0 ]]; then
    echo "No input file provided!"
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
make
./output/memex

cleanup