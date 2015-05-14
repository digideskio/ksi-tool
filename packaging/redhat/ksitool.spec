#
# GUARDTIME CONFIDENTIAL
#
# Copyright (C) [2015] Guardtime, Inc
# All Rights Reserved
#
# NOTICE:  All information contained herein is, and remains, the
# property of Guardtime Inc and its suppliers, if any.
# The intellectual and technical concepts contained herein are
# proprietary to Guardtime Inc and its suppliers and may be
# covered by U.S. and Foreign Patents and patents in process,
# and are protected by trade secret or copyright law.
# Dissemination of this information or reproduction of this
# material is strictly forbidden unless prior written permission
# is obtained from Guardtime Inc.
# "Guardtime" and "KSI" are trademarks or registered trademarks of
# Guardtime Inc.
#


%define	name	ksitool

%define upstream_release 0


Summary: Command-line access to Guardtime Keyless Signature services
Name: %{name}
Version: %(cat VERSION)
Release: STABLE 
License: Apache 2.0
Group: Applications/Security
Source:  http://download.guardtime.com/%{name}-%{version}.tar.gz
URL: http://www.guardtime.com/
Vendor: Guardtime AS
Packager: Guardtime AS <info@guardtime.com>
Distribution: Guardtime utilities
BuildRoot: %{_tmppath}/%{name}-%{version}-build

Requires: openssl
Requires: curl
Requires: libksi >= 3.2
Requires: libksi < 3.3
BuildRequires: openssl-devel
BuildRequires: curl-devel
BuildRequires: libksi-devel >= 3.2
BuildRequires: libksi-devel < 3.3 

%description
Guardtime signing and verification tool. Execute 
%{name} -h to view brief usage instructions.

%prep
%setup -q -n %{name}-%{version}

%build
%configure
make

%install
rm -rf %{buildroot}
make install DESTDIR=%{buildroot}


%files
%defattr (-,root,root)

%{_bindir}/%{name}*
%{_mandir}/man1/ksitool.1*

%changelog