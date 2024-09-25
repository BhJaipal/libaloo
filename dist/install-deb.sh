#!/bin/bash
if [ -d "dist/deb/bin" ]; then
	rm -rf dist/deb/bin
fi
mkdir -p dist/deb/bin

if [ -d "dist/deb/etc/aloo" ]; then
	rm -rf dist/deb/etc/aloo
fi
mkdir -p dist/deb/etc/aloo

if [ -d "dist/deb/usr/include" ]; then
	rm -rf dist/deb/usr/include
fi
mkdir -p dist/deb/usr/include/aloo

cp build.sh dist/deb/etc/aloo/build.sh
cp -r include dist/deb/usr/include
mv dist/deb/usr/include/include dist/deb/usr/include/aloo
cp -r include dist/deb/etc/aloo/include
cp -r src dist/deb/etc/aloo/src
cp -r cli dist/deb/etc/aloo/cli
cp -r test dist/deb/etc/aloo/test
cp -r setup.py dist/deb/etc/aloo/setup.py
cp -r CMakeLists.txt dist/deb/etc/aloo/CMakeLists.txt

if [ $1 ]; then
	sudo dpkg-deb --root-owner-group --build dist/deb dist/libaloo-v$1.deb
	sudo dpkg -i dist/libaloo-v$1.deb
else
	echo "Enter version: "
	read version
	sudo dpkg-deb --root-owner-group --build dist/deb dist/libaloo-v${version}.deb
	sudo dpkg -i dist/libaloo-v${version}.deb
fi
sudo apt install -f

if [ -d dist/deb/etc/aloo ]; then
	rm -rf dist/deb/etc/aloo
fi

if [ -d dist/deb/usr/include ]; then
	rm -rf dist/deb/usr/include
fi

if [ -d dist/deb/bin ]; then
	rm -rf dist/deb/bin
fi
