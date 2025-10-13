#!/bin/bash

# Make sure these directories are correctly set!
cwd=$(pwd)
bosque=$cwd/../../BosqueCore
bsqir=$bosque/src/bsqir
cbsqir=$cwd/bsqir
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

    if [ -d $cbsqir ]; then 
        echo "Deleting old bsqir files!"
        rm -rf $cbsqir
    fi
}

cleanup

cp -R $bsqir $cwd

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

cd $cppout
make clean
make
./output/memex