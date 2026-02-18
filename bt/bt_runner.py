#!/usr/bin/env python3

import os
import sys
import subprocess
import shutil
import re
import operator as op
from typing import Optional

TREE_DEPTH = "/*TREE_DEPTH*/"
N_THREADS  = "/*N_THREADS*/"

def cleanup(dir):
    if os.path.exists(dir):
        print("Deleting old cppout files!")
        shutil.rmtree(dir)

def replace(dir, code, depth, nthds):
	emitpath = os.path.join(dir, "emit.cpp")
	emit = open(emitpath, 'r').read()

	emit = re.sub(r'__CoreCpp::[a-zA-Z]+ main\(\) noexcept  {[^}]*}', code, emit, 0)
	emit = emit.replace(TREE_DEPTH, str(depth))
	emit = emit.replace(N_THREADS, str(nthds))
	
	open(emitpath, 'w').write(emit)

def parse_argv(trgt) -> Optional[str]:
	for arg in sys.argv:
		if not op.contains(arg, trgt):
			continue

		return arg.removeprefix(trgt)

	return None 

def main():
	# Make sure these directories are correctly set!
	cwd = os.getcwd()
	bosque = os.path.join(cwd, "..", "..", "BosqueCore")
	cpp = os.path.join(bosque, "bin", "src", "cmd", "analyzecpp.js")
	cppout = os.path.join(cwd, "cppout")
	src = os.path.join(cwd, "bt.bsq")
	tree_depth = 21
	n_thds = 1

	# Cleanup any leftover cpp code 
	cleanup(cppout)

	nargs = len(sys.argv)
	if nargs > 3:
		print(f"Found {nargs} args when max is 2!")
		sys.exit(1)

	if parse := parse_argv("depth="):
		tree_depth = parse
	
	if parse := parse_argv("nthds="):
		n_thds = parse

	assert(int(n_thds) > 0)

	print(f"Running bt with a max tree depth of {tree_depth} on {n_thds} threads!\n")

	try:
		subprocess.run(["node", cpp, src], check=True)
	except subprocess.CalledProcessError as e:
		print(f"Error running node command: {e}")
		sys.exit(1)
	except FileNotFoundError:
		print("Error: 'node' command not found.")
		sys.exit(1)

	try:
		test = "thread.cpp"
		test_path = os.path.join(cwd, test)
		testcode = open(test_path, 'r').read()

		os.chdir(cppout)
		replace(cppout, testcode, tree_depth, n_thds)

		# We always run release build with memstats ON
		subprocess.run(["make", "clean"], check=False)
		subprocess.run(["make", "BUILD=release", "OPTIONS=-DMEM_STATS"], check=True)
        
		memex_path = os.path.join("output", "memex")
		if not os.path.exists(memex_path):
			print(f"Error: Executable not found at {memex_path}")
			sys.exit(1)
 
		subprocess.run([memex_path], check=True)

	except subprocess.CalledProcessError as e:
		print(f"Error during make process: {e}")
		sys.exit(1)
	finally:
		os.chdir(cwd)

if __name__ == "__main__":
	main()
