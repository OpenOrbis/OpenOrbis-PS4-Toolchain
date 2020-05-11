#!/bin/sh

cd $OO_PS4_TOOLCHAIN/bin/linux

# Make all binaries executable
chmod +x ./create-eboot
chmod +x ./create-lib
chmod +x ./readelf