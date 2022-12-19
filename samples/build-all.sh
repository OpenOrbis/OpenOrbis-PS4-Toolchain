#!/bin/bash

MAKEFILE="Makefile"

for dir in ./*
do
    echo "[+] Current directory $dir"
    if [[ "$dir" == "./trophies" ]]; then
        continue
    fi
    if [[ -f "$dir/$MAKEFILE" ]]; then
        cd $dir
        make clean || exit 1
        make all -j$(nproc) || exit 1
        cd ..
    fi
done
