#!/bin/bash
if [ -d "dist/all-deb/bin" ]; then
	rm -rf dist/all-deb/bin
fi
mkdir -p dist/all-deb/bin

if [ -d "dist/all-deb/etc/aloo" ]; then
	rm -rf dist/all-deb/etc/aloo
fi
mkdir -p dist/all-deb/etc/aloo

if [ -d "dist/all-deb/usr/include" ]; then
	rm -rf dist/all-deb/usr/include
fi
mkdir -p dist/all-deb/usr/include/aloo

cp build.sh dist/all-deb/etc/aloo/build.sh
cp -r include dist/all-deb/usr/include
mv dist/all-deb/usr/include/include dist/all-deb/usr/include/aloo
cp -r include dist/all-deb/etc/aloo/include
cp -r src dist/all-deb/etc/aloo/src
cp -r cli dist/all-deb/etc/aloo/cli
cp -r test dist/all-deb/etc/aloo/test
cp -r setup.py dist/all-deb/etc/aloo/setup.py
cp -r CMakeLists.txt dist/all-deb/etc/aloo/CMakeLists.txt

if [ $1 ]; then
	sudo dpkg-deb --root-owner-group --build dist/all-deb dist/libaloo-v$1.deb
	sudo dpkg -i dist/libaloo-v$1.deb
else
	echo "Enter version: "
	read version
	sudo dpkg-deb --root-owner-group --build dist/all-deb dist/libaloo-v${version}.deb
	sudo dpkg -i dist/libaloo-v${version}.deb
fi

sudo apt install -f

rm -rf dist/all-deb/etc/aloo
rm -rf dist/all-deb/usr/include
rm -rf dist/all-deb/bin
