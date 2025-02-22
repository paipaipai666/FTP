QT += core gui widgets

CONFIG += c++17

win32-msvc*:QMAKE_CXXFLAGS += /utf-8
# QMAKE_LFLAGS += "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\""

SOURCES += \
    src/main.cpp\
    src/FTP.cpp\
    src/transhelper.cpp\

HEADERS += \
    src/FTP.h\
    src/transhelper.h\

FORMS += $$PWD/src/FTP.ui

LIBS += -lWs2_32

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
