#!/bin/sh
#From http://richelbilderbeek.nl/CppQtCrosscompileToWindowsExample15.htm
myqmake="i686-w64-mingw32.static-qmake-qt5"
myqmake="i686-pc-mingw32-qmake"
myqmake="../RibiLibraries/mxe/usr/i686-pc-mingw32/qt5/bin/qmake"


$myqmake GameConnectThreeConsole.pro
make

$myqmake GameConnectThreeDesktop.pro
make

$myqmake GameConnectThreeWebsite.pro
make
