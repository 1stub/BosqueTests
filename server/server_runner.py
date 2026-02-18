#!/usr/bin/env python3

import os
import sys
import subprocess
import shutil
import re
import operator as op
from typing import Optional

N_THREADS     = "/*N_THREADS*/"
MODE          = "/*MODE*/";
WORKLIST_SIZE = "/*WORKLIST_SIZE*/"
HEADER        = '#include "emit.hpp"'

#######################################
# i.e.
#     python3 server_runner.py test=mixed wrksz=180 nthds=2
#     python3 server_runner.py test=db
#

def cleanup(dir):
    if os.path.exists(dir):
        print("Deleting old cppout files!")
        shutil.rmtree(dir)

def replace(dir, code, headers, mode, wrksz, nthds):
	emitpath = os.path.join(dir, "emit.cpp")
	emit = open(emitpath, 'r').read()

	emit = re.sub(r'__CoreCpp::[a-zA-Z]+ main\(\) noexcept  {[^}]*}', code, emit, 0)
	emit = emit.replace(HEADER, headers)
	emit = emit.replace(MODE,'"' + mode + '"')
	emit = emit.replace(WORKLIST_SIZE, str(wrksz))
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
	src = os.path.join(cwd, "server.bsq")	
	testtype = "mixed"
	worklist_size = 600
	n_thds = 1

	# Cleanup any leftover cpp code 
	cleanup(cppout)

	nargs = len(sys.argv)
	if nargs > 4:
		print(f"Found {nargs} args when max is 3!")
		sys.exit(1)

	if parse := parse_argv("test="):
		testtype = parse

	if parse := parse_argv("wrksz="):
		worklist_size = parse

	if parse := parse_argv("nthds="):
		n_thds = parse

	assert(int(n_thds) > 0)

	print(f"""Running server benchmark in mode {testtype} with a worklist of size {worklist_size} and doing so on {n_thds} threads""")

	try:
		subprocess.run(["node", cpp, src], check=True)
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
		replace(cppout, test_code, headers_code, testtype, worklist_size, n_thds)

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
