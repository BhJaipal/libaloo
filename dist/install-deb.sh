#!/bin/bash
# python3.10 setup.py
./build.sh
cp bin/aloo dist/deb/bin/aloo
cp bin/aloo-cli dist/deb/bin/aloo-cli
cp cli/build.sh dist/deb/etc/aloo/build.sh
cp cli/run.sh dist/deb/etc/aloo/run.sh
cp cli/clean.sh dist/deb/etc/aloo/clean.sh
cp -r cli/sample dist/deb/etc/aloo/sample
sudo dpkg-deb --root-owner-group --build dist/deb
echo "Do you want to install Aloo? (y/n)"

read answer
if [ $answer = "y" ]; then
	sudo dpkg -i dist/deb.deb
	sudo apt install -f
fi
