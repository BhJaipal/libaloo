#!/bin/bash
python3.10 setup.py
./build.sh
cp bin/aloo dist/x86_64-deb/bin/aloo
cp bin/aloo-cli dist/x86_64-deb/bin/aloo-cli
cp cli/build.sh dist/x86_64-deb/etc/aloo/build.sh
cp cli/run.sh dist/x86_64-deb/etc/aloo/run.sh
cp cli/clean.sh dist/x86_64-deb/etc/aloo/clean.sh
cp -r cli/sample dist/x86_64-deb/etc/aloo/sample
cp -r lib/libaloo.a dist/x86_64-deb/lib/libaloo.a
cp -r include dist/x86_64-deb/usr/include/aloo
cp -r cli/aloo.schema.json dist/x86_64-deb/etc/aloo/aloo.schema.json
sudo dpkg-deb --root-owner-group --build dist/x86_64-deb

sudo dpkg -i dist/x86_64-deb.deb
sudo apt install -f
