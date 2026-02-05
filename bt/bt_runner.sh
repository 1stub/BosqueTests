#!/bin/bash

# Make sure these directories are correctly set!
cwd=$(pwd)
#bosque=$cwd/../../../Downloads/BosqueCore_JUST_AFTER_GCPAPER
bosque=$cwd/../../BosqueCore
cpp=$bosque/bin/src/cmd/analyzecpp.js

build=dev
cppout=$cwd/cppout
src=$1

common=$cppout/gc/src/runtime/common.h

if [[ $# -eq 0 ]]; then
    echo "No source file provided!"
    exit 1
fi

if [[ $2 == "release" ]]; then 
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

# Setup to be running with asserts off and packed metadata
# FS is input field separator (so nothing here), RS defines a line
# (record field separator)
commontmp=$(mktemp)
awk -v rmv="//#define BSQ_GC_CHECK_ENABLED\n//#define VERBOSE_HEADER" 'BEGIN { RS = ""; FS = "" } {
    gsub(/#define BSQ_GC_CHECK_ENABLED\n#define VERBOSE_HEADER/, rmv)
    print
}' "$common" > "$commontmp"
mv "$commontmp" "$common"

cd $cppout
make clean
make BUILD=$build
time ./output/memex
