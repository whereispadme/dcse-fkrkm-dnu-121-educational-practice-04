QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    inputdatatodb.cpp \
    main.cpp \
    mainwindow.cpp \
    person.cpp \
    requestform.cpp

HEADERS += \
    inputdatatodb.h \
    mainwindow.h \
    person.h \
    requestform.h

FORMS += \
    inputdatatodb.ui \
    mainwindow.ui \
    requestform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
