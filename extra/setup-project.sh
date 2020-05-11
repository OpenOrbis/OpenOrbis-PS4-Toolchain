#!/bin/sh

PROJDIR=$(basename $(pwd))
MAINCPP=./$PROJDIR/main.cpp

echo $PROJDIR;

# Creates the project and intermediate directories
mkdir -p ./$PROJDIR/x64/Debug

# Copies the Makefile from hello_world sample
cp $OO_PS4_TOOLCHAIN/samples/hello_world/Makefile ./Makefile

# Creates a main.cpp file
echo "#include <stdio.h>\n" > $MAINCPP
echo "int main()" >> $MAINCPP
echo "{" >> $MAINCPP
echo "\t// Your code here..." >> $MAINCPP
echo "\treturn 0;" >> $MAINCPP
echo "}" >> $MAINCPP
