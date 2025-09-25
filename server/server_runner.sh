#!/bin/bash

# Make sure your directory is correctly set!
cwd=$(pwd)
bosque=$cwd/../../BosqueCore
cpp=$bosque/bin/src/cmd/analyzecpp.js

src=server.bsq
cppout=$cwd/cppout

build=dev

if [[ $1 -eq "release" ]]; then 
    build=release
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
make BUILD=$build
./output/memex