#-------------------------------------------------
#
# Project created by QtCreator 2015-02-06T21:11:31
#
#-------------------------------------------------

CONFIG += debug_and_release
QT       += core gui
unix:QMAKE_CXXFLAGS += -std=c++11
win32:LIBS += -lwinmm
win32:DEFINES += __WINDOWS_MM__

unix:DEFINES += __UNIX_JACK__ \
                __LINUX_ALSA__

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = toaster
TEMPLATE = app

CONFIG(debug, debug|release) {
    DESTDIR = $$OUT_PWD/debug
} else {
    DESTDIR = $$OUT_PWD/release
}


INCLUDEPATH += $$PWD/../ToasterWidgets \
               $$PWD/../RtMidi \
               $$PWD/../Shared

SOURCES += main.cpp\
        ToasterWindow.cpp \
    SysExBase.cpp \
    Midi.cpp \
    SysExMsgDispatcher.cpp \
    StompMidi.cpp \
    MainFrame.cpp \
    Stomp.cpp \
    AmpMidi.cpp \
    RigMidi.cpp \
    EqMidi.cpp \
    InputMidi.cpp \
    CabMidi.cpp \
    DelayMidi.cpp \
    ReverbMidi.cpp \
    GlobalMidi.cpp \
    Amp.cpp \
    Cab.cpp \
    Delay.cpp \
    Eq.cpp \
    Global.cpp \
    Input.cpp \
    Rig.cpp \
    Reverb.cpp \
    DebugMidi.cpp \
    NRPNBase.cpp \
    StompCtxMenu.cpp \
    SettingsDialog.cpp \
    Settings.cpp \
    VolumeTables.cpp \
    ProfileMidi.cpp \
    Profile.cpp \
    ExtParamMidi.cpp \
    ExtParam.cpp \
    StompControlStackedWidget.cpp \
    MainControlFrame.cpp

HEADERS  += ToasterWindow.h \
    SysExBase.h \
    Midi.h \
    SysExMsgDispatcher.h \
    StompMidi.h \
    MainFrame.h \
    Stomp.h \
    AmpMidi.h \
    RigMidi.h \
    EqMidi.h \
    InputMidi.h \
    CabMidi.h \
    DelayMidi.h \
    ReverbMidi.h \
    GlobalMidi.h \
    Amp.h \
    Cab.h \
    Delay.h \
    Eq.h \
    Global.h \
    Input.h \
    Rig.h \
    Reverb.h \
    DebugMidi.h \
    NRPNBase.h \
    StompCtxMenu.h \
    SettingsDialog.h \
    Settings.h \
    VolumeTables.h \
    ProfileMidi.h \
    Profile.h \
    ExtParamMidi.h \
    ExtParam.h \
    StompControlStackedWidget.h \
    MainControlFrame.h

FORMS    += \
    ToasterWindow.ui \
    MainFrame.ui \
    SettingsDialog.ui \
    StompControlStackedWidget.ui \
    MainControlFrame.ui

RESOURCES += \
    resources.qrc



DEPENDPATH += $$PWD/../ToasterWidgets \
              $$PWD/../RtMidi

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-Toaster-Desktop_Qt_5_4_1_MSVC2013_64bit/RtMidi/release/ -lRtMidi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-Toaster-Desktop_Qt_5_4_1_MSVC2013_64bit/RtMidi/debug/ -lRtMidi
else:unix: CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-Toaster-Desktop/RtMidi/release -lRtMidi
else:unix: CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-Toaster-Desktop/RtMidi/debug -lRtMidi

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-Toaster-Desktop_Qt_5_4_1_MSVC2013_64bit/ToasterWidgets/release/ -lqtoasterwidgetsplugin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-Toaster-Desktop_Qt_5_4_1_MSVC2013_64bit/ToasterWidgets/debug/ -lqtoasterwidgetsplugind
else:unix: CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-Toaster-Desktop/ToasterWidgets/release -lqtoasterwidgetsplugin
else:unix: CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-Toaster-Desktop/ToasterWidgets/debug -lqtoasterwidgetsplugin

unix:LIBS += -lasound -ljack
