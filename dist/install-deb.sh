#!/bin/bash
cp build.sh dist/amd64-deb/etc/aloo/build.sh
cp -r include dist/amd64-deb/usr/include/aloo
cp -r src dist/amd64-deb/etc/aloo/src
cp -r cli dist/amd64-deb/etc/aloo/cli
cp -r setup.py dist/amd64-deb/etc/aloo/setup.py
cp -r CMakeLists.txt dist/amd64-deb/etc/aloo/CMakeLists.txt
sudo dpkg-deb --root-owner-group --build dist/amd64-deb

sudo dpkg -i dist/amd64-deb.deb
sudo apt install -f
