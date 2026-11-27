CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14

QMAKE_CXXFLAGS += -Wall -Wextra -Werror -std=c++14


CONFIG += debug_and_release

QT += core gui widgets

CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}

# Was: include(../RibiLibraries/GeneralConsole.pri)
include($$PWD/ribi_classes/CppAbout/CppAbout.pri)
include($$PWD/ribi_classes/CppFileIo/CppFileIo.pri)
include($$PWD/ribi_classes/CppHelp/CppHelp.pri)
include($$PWD/ribi_classes/CppMenuDialog/CppMenuDialog.pri)
include($$PWD/ribi_classes/CppTrace/CppTrace.pri)
# Was: include(../RibiLibraries/GeneralDesktop.pri)
include($$PWD/ribi_classes/CppQtAboutDialog/CppQtAboutDialog.pri)
include($$PWD/ribi_classes/CppQtHideAndShowDialog/CppQtHideAndShowDialog.pri)

include(ConnectThree.pri)
include(ConnectThreeWidget.pri)
include(QtConnectThreeWidget.pri)

include(ConnectThreeDesktop.pri)

SOURCES += qtmain.cpp

# QResources give this error
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
