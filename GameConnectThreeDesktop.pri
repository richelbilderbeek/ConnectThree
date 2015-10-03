include(../ConnectThree/GameConnectThreeConsole.pri)

SOURCES += \
    ../ConnectThree/qtshowwinnerdialog.cpp \
    ../ConnectThree/qtselectplayerwidget.cpp \
    ../ConnectThree/qtconnectthreeresources.cpp \
    ../ConnectThree/qtconnectthreemenudialog.cpp \
    ../ConnectThree/qtconnectthreegamedialog.cpp
#    ../ConnectThree/qtconnectthreecanvas.cpp

HEADERS  += \
    ../ConnectThree/qtshowwinnerdialog.h \
    ../ConnectThree/qtselectplayerwidget.h \
    ../ConnectThree/qtconnectthreeresources.h \
    ../ConnectThree/qtconnectthreemenudialog.h \
    ../ConnectThree/qtconnectthreegamedialog.h
#    ../ConnectThree/qtconnectthreecanvas.h

FORMS += \
    ../ConnectThree/qtshowwinnerdialog.ui \
    ../ConnectThree/qtconnectthreemenudialog.ui \
    ../ConnectThree/qtconnectthreegamedialog.ui
