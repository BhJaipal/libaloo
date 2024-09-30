Name: aloo
Version: 0.1.1
Release: 1
Summary: Aloo library
License: MIT
Requires: libgtk-4-dev, libsqlite3-dev, libjsoncpp25, libjsoncpp-dev, python3, python3-pip, lua5.4, luarocks
%global aloo_arch all

%define aloo_version 0.1.1
%define aloo_release 1

%description
This a Gtk4 based library written in C to make things easier

# %install

# %files
# %dir /etc/aloo
# %dir /usr/share/pkgconfig
# %file /etc/aloo.conf
# %file /usr/share/pkgconfig/aloo.pc

%post
cd /etc/aloo
python3 setup.py
sudo pip3 list | grep "cmake "
if [[ ! $? ]]; then
	sudo pip3 install cmake
fi
mkdir /etc/aloo/{bin,lib}
cmake -B /etc/aloo/build -DCMAKE_BUILD_TYPE=Release
cd /etc/aloo/build
make
cd ..
mv /etc/aloo/bin/aloo /bin
mv /etc/aloo/bin/aloo-cli /bin
mv /etc/aloo/cli/build.sh /etc/aloo
mv /etc/aloo/cli/run.sh /etc/aloo
mv /etc/aloo/cli/clean.sh /etc/aloo
mv /etc/aloo/cli/aloo.schema.json /etc/aloo
mv /etc/aloo/cli/sample /etc/aloo
mv /etc/aloo/lib/libaloo.a /lib
rm -rf /etc/aloo/{build,src,include,lib,test,CMakeLists.txt,cli,setup.py}
