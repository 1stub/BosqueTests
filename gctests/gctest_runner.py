import os
import sys

cwd = os.getcwd()
bosque = "{cwd}/../../BosqueCore"
cpp = "{bosque}/bin/src/cmd/analyzecpp.js"

src = "server.bsq"
cppout = "{cwd}/cppout"
common= "{cppout}/gc/src/runtime/common.h"

build = "dev"

if(sys.argv[2] == "release")
    build = "release"

function cleanup() {
    if [ -d $cppout ]; then 
        echo "Deleting old cppout files!"
        rm -rf $cppout 
    fi
}

cleanup

node $cpp $src