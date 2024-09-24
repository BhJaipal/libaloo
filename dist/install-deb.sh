#!/bin/bash
if [ ! -d "dist/amd64-deb/etc" ]; then
	mkdir -p dist/amd64-deb/etc
fi
if [ -d "dist/amd64-deb/etc/aloo" ]; then
	rm -rf dist/amd64-deb/etc/aloo
	mkdir -p dist/amd64-deb/etc/aloo
fi
if [ ! -d "dist/amd64-deb/usr" ]; then
	mkdir -p dist/amd64-deb/usr
fi
if [ ! -d "dist/amd64-deb/usr/include" ]; then
	mkdir -p dist/amd64-deb/usr/include
fi
if [ -d "dist/amd64-deb/usr/include/aloo" ]; then
	rm -rf dist/amd64-deb/usr/include/aloo
fi
cp build.sh dist/amd64-deb/etc/aloo/build.sh
cp -r include dist/amd64-deb/usr/include
mv dist/amd64-deb/usr/include/include dist/amd64-deb/usr/include/aloo
cp -r src dist/amd64-deb/etc/aloo/src
cp -r cli dist/amd64-deb/etc/aloo/cli
cp -r test dist/amd64-deb/etc/aloo/test
cp -r setup.py dist/amd64-deb/etc/aloo/setup.py
cp -r CMakeLists.txt dist/amd64-deb/etc/aloo/CMakeLists.txt
echo "Enter version: "
read version
sudo dpkg-deb --root-owner-group --build dist/amd64-deb dist/libaloo-v${version}.deb

sudo dpkg -i dist/libaloo-v${version}.deb
sudo apt install -f
