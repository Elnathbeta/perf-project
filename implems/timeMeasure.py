#!/usr/bin/python3
#coding=utf-8
# Launch a program multiple times and output compute the average execution time to a file
import sys
import time
import subprocess

NUMBEROFEXECUTIONS = 10

if len(sys.argv) < 5:
	sys.stderr.write("Usage: {} OUTPUTFILE PROGRAM ARGS...\n".format(sys.argv[0]))
	sys.exit(1)

outputFile = sys.argv[1]
toExecute = sys.argv[2:]

times = []
for _ in range(NUMBEROFEXECUTIONS):
	start = time.time()
	subprocess.run(toExecute)
	end = time.time()
	times.append(end-start)

with open(outputFile, "a") as output:
	output.write("{}, {}\n".format(' '.join(toExecute), sum(times)/ len(times)))
