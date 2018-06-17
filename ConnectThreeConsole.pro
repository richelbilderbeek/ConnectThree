include(../RibiLibraries/ConsoleApplicationNoWeffcpp.pri)
include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/GeneralConsole.pri)

#Specific, console
include(ConnectThree.pri)
include(ConnectThreeWidget.pri)

include(ConnectThreeConsole.pri)

SOURCES += main.cpp

# Fix error: unrecognized option '--push-state--no-as-needed'
QMAKE_LFLAGS += -fuse-ld=gold

# QResources give this error
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
