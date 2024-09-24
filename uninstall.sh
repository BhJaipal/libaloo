#!/bin/bash
sudo apt remove aloo -y
rm -f dist/deb.deb
if [ -d "/etc/aloo" ]; then
	sudo rm -rf /etc/aloo
fi
sudo apt autoremove -y
