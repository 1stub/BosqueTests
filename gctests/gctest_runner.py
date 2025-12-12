#!/usr/bin/env python3

import os
import sys
import subprocess
import shutil

MAIN_NS = "namespace Main {"
INCLUDE_HDR = "#include \"emit.hpp\""
INCLUDE_HDR_RPL = INCLUDE_HDR + '\n' + "void* garray[15] = {};\n"
EMAIN = "__CoreCpp::Bool main() noexcept  {"
EMAIN_RPL = EMAIN + '\n' + "GlobalDataStorage::g_global_data.initialize(sizeof(garray), (void**)garray); gtl_info.disable_stack_refs_for_tests = true; gtl_info.enable_global_rescan = true;"

def cleanup(dir):
    if os.path.exists(dir):
        print("Deleting old cppout files!")
        shutil.rmtree(dir)

def insertTestCode(dir, code):
    emitpath = os.path.join(dir, "emit.cpp")
    emit = open(emitpath, 'r').read()
    emit = emit.replace(MAIN_NS,  MAIN_NS + '\n' + code)
    emit = emit.replace(INCLUDE_HDR, INCLUDE_HDR_RPL)
    emit = emit.replace(EMAIN, EMAIN_RPL)
    open(emitpath, 'w').write(emit)

def main():
    # Make sure these directories are correctly set!
    cwd = os.getcwd()
    bosque = os.path.join(cwd, "..", "..", "BosqueCore")
    cpp = os.path.join(bosque, "bin", "src", "cmd", "analyzecpp.js")
    
    cppout = os.path.join(cwd, "cppout")

    if len(sys.argv) < 2:
        print("No source file provided!")
        sys.exit(1)

    src = sys.argv[1]

    tests = None
    if src.__contains__('basic'):
        tests = open('tree_basic.cpp', 'r').read()
    elif src.__contains__('wide'):
        tests = open('tree_wide.cpp', 'r').read()
    else:
        print(f"Unknown input program! Not tree_basic/wide.bsq... arvg[1] = {src}")
        sys.exit(1)

    cleanup(cppout)

    try:
        subprocess.run(["node", cpp, src], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running node command: {e}")
        sys.exit(1)
    except FileNotFoundError:
        print("Error: 'node' command not found.")
        sys.exit(1)

    original_dir = os.getcwd()
    try:
        os.chdir(cppout)

        insertTestCode(cppout, tests)

        subprocess.run(["make", "clean"], check=False)
        subprocess.run(["make"], check=True)
        
        memex_path = os.path.join("output", "memex")
        if not os.path.exists(memex_path):
            print(f"Error: Executable not found at {memex_path}")
            sys.exit(1)
        
        subprocess.run([memex_path], check=True)
        
    except subprocess.CalledProcessError as e:
        print(f"Error during make process: {e}")
        sys.exit(1)
    finally:
        os.chdir(original_dir)

if __name__ == "__main__":
    main()