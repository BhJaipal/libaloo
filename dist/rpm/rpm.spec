%define _enable_debug 0
%define __spec_install_post /usr/bin/aloo-postinst

%define aloo_version 0.1.2
%define aloo_release 1

%global aloo_arch all

%prep
%setup -q -n aloo

%build
%configure --prefix=/usr
%make

%install
%__spec_install_post
%install -D -m 0644 etc/aloo.conf /etc/aloo.conf
%install -D -m 0755 etc/aloo /etc/aloo
%install -D -m 0644 usr/share/pkgconfig/aloo.pc /usr/share/pkgconfig/aloo.pc

%files
%defattr(-rw,root,root)
%doc README
%dir /etc/aloo
%dir /usr/share/pkgconfig
%file etc/aloo.conf
%file usr/share/pkgconfig/aloo.pc

%depends libgtk-4-dev, libsqlite3-dev, libjsoncpp25, libjsoncpp-dev, python3, python3-pip

%changelog
* Tue Sep 25 2024 aloo <jaipalbhanwariya001@gmail.com> 0.1.2
- RPM Initial release.
