#!/usr/bin/env python3

import os
import sys
import subprocess
import shutil
import re
import operator as op
from typing import Optional

N_ITERATIONS = "/*N_ITERATIONS*/"
HEADER       = '#include "emit.hpp"'
MKFLAGS      = "CFLAGS_OPT.release=-O2 -march=x86-64-v3"

#######################################
# i.e.
#     python3 oppass_runner.py itrs=10000
#     python3 oppass_runner.py 
#

def cleanup(dir):
    if os.path.exists(dir):
        print("Deleting old cppout files!")
        shutil.rmtree(dir)

def replace(dir, makefiledir, code, headers, itrs):
	emitpath = os.path.join(dir, "emit.cpp")
	emit = open(emitpath, 'r').read()

	emit = re.sub(r'__CoreCpp::[a-zA-Z]+ main\(\) noexcept  {[^}]*}', code, emit, 0)
	emit = emit.replace(HEADER, headers)
	emit = emit.replace(N_ITERATIONS, str(itrs))

	# For whatever reason some of the tree construction in oppass tricks gcc into 
	# thinking there is infinite recursion, so disable it
	mkrplmt = "CFLAGS_OPT.release=-O2 -march=x86-64-v3 -Wno-infinite-recursion -Wno-array-bounds"
	mksrc = open(makefiledir, 'r').read()
	mksrc = mksrc.replace(MKFLAGS, mkrplmt)

	open(makefiledir, 'w').write(mksrc)
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
	src = os.path.join(cwd, "oppass.bsq")	
	bsqirs = os.path.join(cwd, "bsqir")
	makefile = os.path.join(cppout, "makefile")
	itrs = 10000
	
	# Cleanup any leftover cpp code 
	cleanup(cppout)
	# cleanup(bsqirs)

	nargs = len(sys.argv)
	if nargs > 2:
		print(f"Found {nargs} args when max is 1!")
		sys.exit(1)

	if parse := parse_argv("itrs="):
		itrs = parse

	print(f"""Running oppass benchmark for {itrs} iterations on 1 thread""")

    # Generate necessary bsqir files
	print("Loading *.bsq files from bsqir directory: ") 
	bsqir_files = []
	for dirpaths, dirnames, filenames in os.walk(bsqirs):
		for filename in filenames:
			if not filename.endswith(".bsq"):
				continue
			path = os.path.join(dirpaths, filename)
			print(path)
			bsqir_files.append(path)
			
	if bsqir_files.count == 0:
		raise ValueError("Error: No *.bsq files found in bsqir directory")

	try:
		subprocess.run(["node", cpp, src, *bsqir_files], check=True)
	except subprocess.CalledProcessError as e:
		print(f"Error running node command: {e}")
		sys.exit(1)
	except FileNotFoundError:
		print("Error: 'node' command not found.")
		sys.exit(1)

	try:	
		# Not realy sure why but we need to include headers at top of emit.cpp	
		headers = "headers.hpp"
		test = "server.cpp"

		headers_path = os.path.join(cwd, headers)
		test_path = os.path.join(cwd, test)
		
		headers_code = open(headers_path, 'r').read()
		test_code = open(test_path, 'r').read()

		os.chdir(cppout)
		replace(cppout, makefile, test_code, headers_code, itrs)

		# Our default build will be release with memstats on
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
