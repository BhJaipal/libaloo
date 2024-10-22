#!/bin/bash
sudo rm -rf /etc/aloo/samples
sudo apt remove aloo -y
sudo apt autoremove -y
rm -f dist/deb.deb
