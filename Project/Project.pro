QT       += core gui
QT       += network
QT       += multimedia
QT       += axcontainer
QT       += multimedia
#LIBS += $$PWD/../Python/env/Lib/site-packages -lpython3

#LIBS += "C:\Program Files\Python311\libs" -lpython3.11

#DEPENDPATH += /usr/local/python3.7/include/python3.7m

#INCLUDEPATH += $$PWD/../Python/env/Lib/site-packages

#INCLUDEPATH += $$PWD/../Python/env/Include

#INCLUDEPATH += /usr/local/python3.7/lib/python3.7/site-packages/numpy/core/include

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    event.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    pkumap.cpp \
    fileio.cpp \
    config.cpp \
    selection.cpp \
    countdowntimer.cpp

HEADERS += \
    event.h \
    mainwindow.h \
    menu.h \
    pkumap.h \
    schedule.h \
    fileio.h \
    config.h \
    selection.h \
    countdowntimer.h

FORMS += \
    mainwindow.ui \
    menu.ui \
    pkumap.ui \
    config.ui \
    countdowntimer.ui \
    intro.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resource/nodes.csv \
    map.jpg \
    nodes.csv \
    UserInfo.json \
    bell.mp3 \
    events.csv \
    icon.jpg \
    activities.json \
    course.json

RESOURCES += \
    background.qrc \
    icon.qrc \
    bell.qrc
