#!/bin/bash
if [ ! -d "dist/rpm/bin" ]; then
	mkdir -p dist/rpm/bin
fi

if [ -d "dist/rpm/etc/aloo" ]; then
	rm -rf dist/rpm/etc/aloo
fi
mkdir -p dist/rpm/etc/aloo

if [ -d "dist/rpm/usr/include" ]; then
	rm -rf dist/rpm/usr/include
fi
mkdir -p dist/rpm/usr/include/aloo

cp build.sh dist/rpm/etc/aloo/build.sh
cp -r include dist/rpm/usr/include
mv dist/rpm/usr/include/include dist/rpm/usr/include/aloo
cp -r include dist/rpm/etc/aloo/include
cp -r src dist/rpm/etc/aloo/src
cp -r cli dist/rpm/etc/aloo/cli
cp -r test dist/rpm/etc/aloo/test
cp -r setup.py dist/rpm/etc/aloo/setup.py
cp -r CMakeLists.txt dist/rpm/etc/aloo/CMakeLists.txt

if [ $1 ]; then
	cd dist
	sudo rpmbuild -bb rpm/libaloo.spec # output_file=./dist/libaloo-v$1.rpm
	# sudo rpm -i dist/libaloo-v$1.rpm
else
	cd dist
	echo "Enter version: "
	read version
	sudo rpmbuild -bb rpm/libaloo.spec # libaloo-v${version}.rpm
	# sudo rpm -i dist/libaloo-v${version}.rpm
fi

if [ -d dist/rpm/etc/aloo ]; then
	rm -rf dist/rpm/etc/aloo
fi

if [ -d dist/rpm/usr/include ]; then
	rm -rf dist/rpm/usr/include
fi
