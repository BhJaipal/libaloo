#!/bin/bash
if [ -d build ]; then
	rm -rf build
	rm -rf bin
	rm -rf lib
fi
./build.sh
if [ ! $1 ]; then
	echo -e "Version not specified as argument"
	exit 1
fi
if [ -d "output" ]; then
	rm -rf output
fi

cmake -B build -DCMAKE_BUILD_TYPE=Release
cd build
make
cd ..

mkdir -p usr/{include,bin}
mkdir -p etc
echo "PKG_CONFIG_PATH=/usr/share/pkgconfig/aloo.pc\n" >etc/aloo.conf

mv lib usr/lib
mv scripts/src etc/aloo
mv include usr/include/aloo
mv etc/aloo/__init__.py usr/bin/aloo
mv etc/aloo/aloocli.py usr/bin/aloocli
chmod +x usr/bin/*

mkdir -p usr/share/pkgconfig
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
arch=("$(arch)")
url="https://github.com/BhJaipal/libaloo"
license=('MIT')
depends=(gtk4 sqlite python python-pip)
makedepends=(git)
provides=(libaloo)
conflicts=(libaloo)" >PKGBUILD
	makepkg
fi
