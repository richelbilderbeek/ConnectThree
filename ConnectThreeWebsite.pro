include(../RibiLibraries/BoostAll.pri)
include(../RibiLibraries/Wt.pri)
include(../RibiLibraries/WebApplication.pri)

include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralWeb.pri)

#Specific
include(../RibiClasses/CppCanvas/CppCanvas.pri)
include(../RibiClasses/CppConnectThree/CppConnectThree.pri)
include(../RibiClasses/CppConnectThreeWidget/CppConnectThreeWidget.pri)
include(../RibiClasses/CppDotMatrix/CppDotMatrix.pri)
include(../RibiClasses/CppTextCanvas/CppTextCanvas.pri)

#Specific
include(../RibiClasses/CppWtConnectThreeWidget/CppWtConnectThreeWidget.pri)

include(ConnectThreeWebsite.pri)

SOURCES += wtmain.cpp

# QResources give this error
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
