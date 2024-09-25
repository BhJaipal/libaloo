Name: aloo
Version: 1.1
Release: 1
Summary: Aloo library
License: MIT
Requires: libgtk-4-dev, libsqlite3-dev, libjsoncpp25, libjsoncpp-dev, python3, python3-pip
%global aloo_arch all

%define aloo_version 0.1.1
%define aloo_release 1

%install
%define __spec_install_post /bin/aloo-postinst
%description

%files
%defattr(-rw,root,root)
%dir /etc/aloo
%dir /usr/share/pkgconfig
%file etc/aloo.conf
%file usr/share/pkgconfig/aloo.pc
