#!/bin/bash

if [ ! -d "build/" ]; then
	mkdir build
fi
cmake -B build -DCMAKE_BUILD_TYPE=Release
cd build
make
ln --relative -s scripts/src/__init__.py bin/aloo.py

if [ ! $(which tree) ]; then
	sudo apt install tree
fi

mv -r dist/deb/DEBIAN .
mkdir -p usr/include
mv -r include usr/include/aloo
mv -r dist/deb/usr/share usr/share
mv -r dist/deb/etc etc
mv -r lib usr/lib
mv -r bin usr/bin
rm -r {*.github,*.vscode,include,lib,test,styles,scripts,assets,build,aloo-edit,dist,docs,*.png,CMakeLists.txt,build.sh,Doxyfile,LICENSE,Readme.md,*.log,*.sh,src,*.html}
rm -r etc/aloo
rm -r bin/test-1.exe
tree
