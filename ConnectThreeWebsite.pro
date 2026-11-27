include(../RibiLibraries/BoostAll.pri)
include(../RibiLibraries/Wt.pri)
include(../RibiLibraries/WebApplication.pri)

# Was: include(../RibiLibraries/GeneralConsole.pri)
include($$PWD/ribi_classes/CppAbout/CppAbout.pri)
include($$PWD/ribi_classes/CppFileIo/CppFileIo.pri)
include($$PWD/ribi_classes/CppHelp/CppHelp.pri)
include($$PWD/ribi_classes/CppMenuDialog/CppMenuDialog.pri)
include($$PWD/ribi_classes/CppTrace/CppTrace.pri)
# Was: include(../RibiLibraries/GeneralWeb.pri)
DEFINES += BOOST_SIGNALS_NO_DEPRECATION_WARNING
include($$PWD/ribi_classes/CppWtAboutDialog/CppWtAboutDialog.pri)
include($$PWD/ribi_classes/CppWtAutoConfig/CppWtAutoConfig.pri)

#Specific
include($$PWD/ribi_classes/CppCanvas/CppCanvas.pri)
include(ConnectThree.pri)
include(ConnectThreeWidget.pri)
include(../DotMatrix/DotMatrix.pri)
include($$PWD/ribi_classes/CppTextCanvas/CppTextCanvas.pri)

#Specific
include(WtConnectThreeWidget.pri)

include(ConnectThreeWebsite.pri)

SOURCES += wtmain.cpp

# QResources give this error
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
