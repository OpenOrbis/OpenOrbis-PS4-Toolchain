#!/usr/bin/python
import sys, os, json
from os import listdir
from os.path import isfile, join

makefile = open("build/Makefile", "w")

makefileProgramList = ''
makefileRuleList = ''

# Scan the directory for source files
librarySourceFiles = [f for f in listdir('./build/') if isfile(join('./build/', f))]

for sourceFile in librarySourceFiles:
	# Add a program in the makefile for every .c found
	if sourceFile[-2:] == '.c':
		programName = sourceFile[:-2]
		# Add to program list for 'all'
		makefileProgramList += programName + " "

		# Add rule for this program
		makefileRuleList += programName + ": " + sourceFile + "\n"
		makefileRuleList += "\tgcc -ffreestanding -nostdlib -fno-builtin -fPIC -c " + sourceFile + " -o " + programName + ".o\n"
		makefileRuleList += "\tgcc -shared -ffreestanding -nostdlib -fno-builtin " + programName + ".o -o " + programName + ".so\n"
		makefileRuleList += "\n\n"

makefileSource = "all: " + makefileProgramList + "\n\n"
makefileSource += makefileRuleList

makefile.write(makefileSource)
