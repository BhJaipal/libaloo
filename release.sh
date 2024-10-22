#!/bin/bash

if [ ! -d "build/" ]; then
	mkdir build
fi
cmake -B build -DCMAKE_BUILD_TYPE=Release
cd build
make
mv scripts/src/__init__.py bin/aloo.py

if [ ! $(which tree) ]; then
	sudo apt install tree
fi

mv -r dist/deb/etc etc
mkdir etc/aloo
mv scripts/src/main.c etc/aloo/main.c
mv scripts/src/test.c etc/aloo/test.c
mv scripts/src/main.server.c etc/aloo/main.server.c
mv scripts/src/main.server.h etc/aloo/main.server.h
mv scripts/src/CMakeLists.txt etc/aloo/CMakeLists.txt
mkdir DEBIAN

echo "Package: aloo
Version: $1
Section: utils
Priority: optional
Architecture: all
Maintainer: Jaipal <jaipalbhanwariya001@gmail.com>
Description: This a library based on Gtk4 written in C to make things easier
Depends: libgtk-4-dev, libsqlite3-dev, python3, python3-pip, make
" >DEBIAN/control

mkdir -p usr/include
mv -r include usr/include/aloo
mv -r dist/deb/usr/share usr/share
rm usr/share/pkgconfig/aloo.pc

echo "Name: aloo
Version: $1
Description: This a Gtk4 based library written in C to make things easier
Depends: libgtk-4-dev, libsqlite3-dev, python3, python3-pip, make
CFlags: -I/usr/include/aloo
Libs: -laloo" >usr/share/pkgconfig/aloo.pc

mv -r lib usr/lib
mv -r bin usr/bin
rm -r {*.github,*.vscode,include,lib,test,styles,scripts,assets,build,aloo-edit,dist,docs,*.png,CMakeLists.txt,build.sh,Doxyfile,LICENSE,Readme.md,*.log,*.sh,src,*.html}
rm -r etc/aloo
rm -r bin/test-1.exe
sudo dpkg-deb --root-owner-group --build . libaloo-$1.deb
tree
