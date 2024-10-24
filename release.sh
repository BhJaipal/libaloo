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

mkdir -p usr/share/pkgconfig
mkdir usr/include
mv include usr/include/aloo
mv lib usr/lib
mv bin usr/bin
rm -r bin/test-1.exe

echo "Name: aloo
Version: $1
Description: This a Gtk4 based library written in C to make things easier
Depends: libgtk-4-dev, libsqlite3-dev, python3, python3-pip
CFlags: -I/usr/include/aloo
Libs: -laloo" >usr/share/pkgconfig/aloo.pc

rm -r {*.github,*.vscode,include,lib,test,styles,scripts,assets,build,aloo-edit,dist,docs,*.png,CMakeLists.txt,build.sh,Doxyfile,LICENSE,Readme.md,*.log,*.sh,src,*.html}

if [ $(which dpkg-deb) ]; then
	mkdir DEBIAN
	echo "Package: aloo
Version: $1
Section: utils
Priority: optional
Architecture: all
Maintainer: Jaipal <jaipalbhanwariya001@gmail.com>
Description: This a library based on Gtk4 written in C to make things easier
Depends: libgtk-4-dev, libsqlite3-dev, python3, python3-pip" >DEBIAN/control
	sudo dpkg-deb --root-owner-group --build . libaloo-v$1.deb
elif [ $(which rpm) && $(which dnf) ]; then
	mkdir SPECS
	echo "Name: aloo
Version: $1
Release: 1
Summary: Aloo library
License: MIT
Requires: libgtk-4-dev, libsqlite3-dev, python3, python3-pip
%global aloo_arch all

%define aloo_version $1
%define aloo_release 1

%description
This a Gtk4 based library written in C to make things easier" >SPECS/libaloo.spec
	rpmbuild -bs SPECS/libaloo.spec
else
	echo "pkgname=libaloo
pkgver=$1
pkgrel=1
pkgdesc="This a Gtk4 based library written in C to make things easier"
arch=("x86_64")
url="https://github.com/BhJaipal/libaloo"
license=('MIT')
depends=(gtk4 sqlite python python-pip)
makedepends=(git)
provides=(libaloo)
conflicts=(libaloo)" >PKGBUILD
	makepkg
fi
