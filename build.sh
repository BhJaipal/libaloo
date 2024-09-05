#!/bin/bash

if [ $1 = "clean" ]; then
	rm -rf build
elif [ $1 = "test" ]; then
	cd build && ctest -C Release && cd ..
elif [ ! $1 ]; then
	if [ ! -d "build/" ]; then
		mkdir build
	fi

	cmake -B build -DCMAKE_BUILD_TYPE=Release
	cd build
	make
fi
