include(../common_top.pri)

MOC_DIR = .moc
SRC_PREFIX = ../../src/themeapplet
STUB_PREFIX = ../stubs

INCLUDEPATH = \
        $$STUB_PREFIX \
	$$SRC_PREFIX \
	$$INCLUDEPATH

CONFIG += \
	gui \
	meegotouch \
	debug \
	plugin \
	duicontrolpanel \
	silent 

QT += \
    testlib \
    gui \
    dbus 

TEMPLATE = app
DEFINES += UNIT_TEST
TARGET = ut_themedialog
target.path = /usr/lib/$$TEST_PKG_NAME

load(meegotouch_defines)
DEFINES += \
    MEEGO_THEMEDIR=\\\"\"$$M_THEME_DIR\"\\\"

HEADERS += \
    $$STUB_PREFIX/mdesktopentry.h \
    ../../src/debug.h \
    ut_themedialog.h \
    $$SRC_PREFIX/themebusinesslogic.h \
    $$SRC_PREFIX/themedescriptor.h \
    $$SRC_PREFIX/themedialog.h 

SOURCES += \
    $$STUB_PREFIX/mdesktopentry.cpp \
    ../../src/debug.cpp \
    ut_themedialog.cpp \
    $$SRC_PREFIX/themebusinesslogic.cpp \
    $$SRC_PREFIX/themedescriptor.cpp \
    $$SRC_PREFIX/themedialog.cpp 

INSTALLS += target
