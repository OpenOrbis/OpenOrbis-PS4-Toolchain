#!/bin/bash
for d in ./*/ ; do (cd "$d" && make clean && make); done
