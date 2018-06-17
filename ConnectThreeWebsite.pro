include(../RibiLibraries/BoostAll.pri)
include(../RibiLibraries/Wt.pri)
include(../RibiLibraries/WebApplication.pri)

include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralWeb.pri)

#Specific
include(../RibiClasses/CppCanvas/CppCanvas.pri)
include(ConnectThree.pri)
include(ConnectThreeWidget.pri)
include(../DotMatrix/DotMatrix.pri)
include(../RibiClasses/CppTextCanvas/CppTextCanvas.pri)

#Specific
include(WtConnectThreeWidget.pri)

include(ConnectThreeWebsite.pri)

SOURCES += wtmain.cpp

# Fix error: unrecognized option '--push-state--no-as-needed'
QMAKE_LFLAGS += -fuse-ld=gold

# QResources give this error
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
