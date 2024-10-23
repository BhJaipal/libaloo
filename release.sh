#!/bin/bash

if [ ! -d "build/" ]; then
	mkdir build
fi
cmake -B build -DCMAKE_BUILD_TYPE=Release
cd build
make
cd ..
mv scripts/src/__init__.py bin/aloo.py

mkdir -p etc/aloo
echo "PKG_CONFIG_PATH=/usr/share/pkgconfig/aloo.pc\n" >etc/aloo/aloo.conf
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

mkdir -p usr/share/pkgconfig
mkdir usr/include
mv include usr/include/aloo
mv lib usr/lib
mv bin usr/bin
rm -r bin/test-1.exe

echo "Name: aloo
Version: $1
Description: This a Gtk4 based library written in C to make things easier
Depends: libgtk-4-dev, libsqlite3-dev, python3, python3-pip, make
CFlags: -I/usr/include/aloo
Libs: -laloo" >usr/share/pkgconfig/aloo.pc

rm -r *.github
rm -r *.vscode
rm -r include
rm -r lib
rm -r test
rm -r styles
rm -r scripts
rm -r assets
rm -r build
rm -r aloo-edit
rm -r dist
rm -r docs
rm -r *.png
rm -r CMakeLists.txt
rm -r build.sh
rm -r Doxyfile
rm -r LICENSE
rm -r Readme.md
rm -r *.log
rm -r *.sh
rm -r src
rm -r *.html
sudo dpkg-deb --root-owner-group --build . libaloo-v$1.deb
