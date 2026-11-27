include($$PWD/ribi_libraries/BoostAll.pri)
include($$PWD/ribi_libraries/Wt.pri)
include($$PWD/ribi_libraries/WebApplication.pri)

include($$PWD/ribi_classes/CppAbout/CppAbout.pri)
include($$PWD/ribi_classes/CppFileIo/CppFileIo.pri)
include($$PWD/ribi_classes/CppHelp/CppHelp.pri)
include($$PWD/ribi_classes/CppMenuDialog/CppMenuDialog.pri)
include($$PWD/ribi_classes/CppTrace/CppTrace.pri)
DEFINES += BOOST_SIGNALS_NO_DEPRECATION_WARNING
include($$PWD/ribi_classes/CppWtAboutDialog/CppWtAboutDialog.pri)
include($$PWD/ribi_classes/CppWtAutoConfig/CppWtAutoConfig.pri)

#Specific
include($$PWD/ribi_classes/CppCanvas/CppCanvas.pri)
include(ConnectThree.pri)
include(ConnectThreeWidget.pri)
include($$PWD/dot_matrix/DotMatrix.pri)
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
