#!/usr/bin/env python3

import os
import sys
import subprocess
import shutil
import re

N_THREADS = "/*N_THREADS*/"
MODE      = "/*MODE*/";    
HEADER    = '#include "emit.hpp"'

#######################################
# Syntax: 
#     python3 server_runner.py BUILD_TYPE TEST_TYPE NUM_THREADS
#
# i.e.
#     python3 server_runner.py mixed 2
#     python3 server_runner.py db
#

def cleanup(dir):
    if os.path.exists(dir):
        print("Deleting old cppout files!")
        shutil.rmtree(dir)

def replace(dir, code, headers, mode, nthds):
	emitpath = os.path.join(dir, "emit.cpp")
	emit = open(emitpath, 'r').read()

	emit = re.sub(r'__CoreCpp::[a-zA-Z]+ main\(\) noexcept  {[^}]*}', code, emit, 0)
	emit = emit.replace(HEADER, headers)
	emit = emit.replace(N_THREADS, str(nthds))
	emit = emit.replace(MODE,'"' + mode + '"')

	open(emitpath, 'w').write(emit)

def main():
	# Make sure these directories are correctly set!
	cwd = os.getcwd()
	bosque = os.path.join(cwd, "..", "..", "BosqueCore")
	cpp = os.path.join(bosque, "bin", "src", "cmd", "analyzecpp.js")
	cppout = os.path.join(cwd, "cppout")
	src = os.path.join(cwd, "server.bsq")	
	testtype = "mixed"
	n_thds = 1

	# Cleanup any leftover cpp code 
	cleanup(cppout)

	nargs = len(sys.argv)
	if nargs > 3:
		print(f"Found {nargs} args when max is 2!")
		sys.exit(1)

	if nargs == 3:
		n_thds = sys.argv[2]
		nargs -= 1

	if nargs == 2:
		testtype = sys.argv[1]

	assert(int(n_thds) > 0)

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
		replace(cppout, test_code, headers_code, testtype, n_thds)

		# For now default is release, may want to allow for dev or a no
		# memstats mode?
		subprocess.run(["make", "clean"], check=False)
		subprocess.run(["make", "BUILD=release"], check=True)
        
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
