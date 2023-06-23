#!/bin/bash

# Build modules
cd libc/
make clean && make
cp libc.prx ../libc.prx

cd ../libSceFios2
make clean && make
cp libSceFios2.prx ../libSceFios2.prx

cd ../right
make clean && make
cp right.sprx ../right.sprx

# Copy into samples
cd ..
for d in ../../samples/*/
	do
		checkdir=$(basename $d)
		echo $checkdir
		if [[ "$checkdir" == "_common" ]] ||
		[[ "$checkdir" == "fork_process" ]] ||
		[[ "$checkdir" == "library_example" ]] ||
		[[ $checkdir == "mira_jailbreak" ]] ||
		[[ $checkdir == "substitute_example" ]]; then
			continue
		fi
		mkdir -p $d/sce_module
		mkdir -p $d/sce_sys/about
		cp libc.prx $d/sce_module/libc.prx
		cp libSceFios2.prx $d/sce_module/libSceFios2.prx
		cp right.sprx $d/sce_sys/about/right.sprx
	done
