#!/bin/bash
./build.sh
if [ ! $(./build.sh test) ]; then
	echo -e "Tests failed"
	exit 1
fi
if [ ! $1 ]; then
	echo -e "Version not specified as argument"
	exit 1
fi
mkdir -p output/usr/{include,bin}
cp -r lib output/usr/lib
cp -r scripts/src output/etc
mv output/etc/__init__.py output/usr/bin/aloo.py
cp -r include output/usr/include/aloo
echo "PKG_CONFIG_PATH=/usr/share/pkgconfig/aloo.pc" >output/etc/aloo.conf
mkdir -p output/usr/share/pkgconfig
echo "Name: aloo
Version: $1
Description: This a Gtk4 based library written in C to make things easier
Depends: libgtk-4-dev, libsqlite3-dev, python3, python3-pip
CFlags: -I/usr/include/aloo
Libs: -laloo" >output/usr/share/pkgconfig/aloo.pc

if [ $(which dpkg-deb) ]; then
	cd output
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
	mv libaloo-v$1.deb ..
	cd ..

elif [ $(which rpm) && $(which dnf) ]; then
	cd output
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
	cd ..

else
	cd output
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
	mv libaloo-v$1-1-$(arch).pkg.tar.zst
	cd ..
fi