# Most specific first
include(ConnectThreeDesktop.pri)
include(ConnectThreeDesktopTest.pri)

include($$PWD/ribi_libraries/BoostAll.pri)

include($$PWD/ribi_classes/CppAbout/CppAbout.pri)
include($$PWD/ribi_classes/CppFileIo/CppFileIo.pri)
include($$PWD/ribi_classes/CppHelp/CppHelp.pri)
include($$PWD/ribi_classes/CppMenuDialog/CppMenuDialog.pri)
include($$PWD/ribi_classes/CppQtAboutDialog/CppQtAboutDialog.pri)
include($$PWD/ribi_classes/CppQtHideAndShowDialog/CppQtHideAndShowDialog.pri)

# Specific, console
include($$PWD/dot_matrix/DotMatrix.pri)
include(../ConnectThree/CppConnectThree.pri)
include(../ConnectThree/CppConnectThreeWidget.pri)
include($$PWD/ribi_classes/CppTribool/CppTribool.pri)

# Specific, desktop
include(../ConnectThree/QtConnectThreeWidget.pri)

SOURCES += qtmain_test.cpp

# QResources give this error
QMAKE_CXXFLAGS += -Wno-unused-variable

# Debug and release settings
CONFIG += debug_and_release
CONFIG(release, debug|release) {

  DEFINES += NDEBUG

  # gprof
  QMAKE_CXXFLAGS += -pg
  QMAKE_LFLAGS += -pg
}

CONFIG(debug, debug|release) {

  # gcov
  QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
  LIBS += -lgcov

  # helgrind, for helgrind and memcheck
  QMAKE_LFLAGS += -pthread -Wl,--no-as-needed

  # UBSAN
  QMAKE_CXXFLAGS += -fsanitize=undefined
  QMAKE_LFLAGS += -fsanitize=undefined
  LIBS += -lubsan
}


CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

# High warning level, warnings are errors
# Qt goes bad with -Weffc++
QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic
QMAKE_CXXFLAGS += -Werror

# Qt5
QT += core gui widgets

# QTest
QT += testlib

# Fixes
#/usr/include/boost/math/constants/constants.hpp:277: error: unable to find numeric literal operator 'operator""Q'
#   BOOST_DEFINE_MATH_CONSTANT(half, 5.000000000000000000000000000000000000e-01, "5.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e-01")
#   ^
QMAKE_CXXFLAGS += -fext-numeric-literals
