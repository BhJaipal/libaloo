#!/bin/bash
sudo apt remove aloo -y
sudo apt autoremove -y
rm -f dist/deb.deb
if [ -d "/etc/aloo" ]; then
	sudo rm -rf /etc/aloo
fi
