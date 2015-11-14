include(../RibiLibraries/DesktopApplication.pri)

include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralDesktop.pri)

#Specific, console
include(../RibiClasses/CppConnectThree/CppConnectThree.pri)
include(../RibiClasses/CppConnectThreeWidget/CppConnectThreeWidget.pri)

#Specific, desktop
include(../RibiClasses/CppQtConnectThreeWidget/CppQtConnectThreeWidget.pri)

include(ConnectThreeDesktop.pri)

SOURCES += qtmain.cpp


