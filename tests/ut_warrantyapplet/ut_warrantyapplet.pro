include(../common_top.pri)

MOC_DIR = .moc
SRC_PREFIX = ../../src/warrantyapplet
STUB_PREFIX = ../stubs

INCLUDEPATH = \
        $$STUB_PREFIX \
        $$SRC_PREFIX \
        $$INCLUDEPATH

QT += \
    testlib \
    dbus 

TEMPLATE = app

DEFINES += \
	UNIT_TEST 

TARGET = ut_warrantyapplet
target.path = /usr/lib/$$TEST_PKG_NAME

CONFIG += \
	gui \
	meegotouch \
	plugin \
	duicontrolpanel \
	silent 

#
# If we will use the QmSystem library we shall stub it here. 
#
contains(DEFINES, HAVE_QMSYSTEM) {
    CONFIG += qmsystem2
}


HEADERS += \
    ../../src/debug.h \
    ut_warrantyapplet.h \
    $$STUB_PREFIX/MLabel \
    $$SRC_PREFIX/warrantyapplet.h \
    $$SRC_PREFIX/warrantybrief.h \
    $$SRC_PREFIX/warrantybusinesslogic.h \
    $$SRC_PREFIX/warrantywidget.h

SOURCES += \
    ../../src/debug.cpp \
    ut_warrantyapplet.cpp \
    $$STUB_PREFIX/mlabel_stub.cpp \
    $$SRC_PREFIX/warrantyapplet.cpp \
    $$SRC_PREFIX/warrantybrief.cpp \
    $$SRC_PREFIX/warrantybusinesslogic.cpp \
    $$SRC_PREFIX/warrantywidget.cpp 

INSTALLS += target
