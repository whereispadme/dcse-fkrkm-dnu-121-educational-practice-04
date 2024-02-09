QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../../main/main/Ball.cpp \
    ../../../main/main/Figure.cpp \
    ../../../main/main/Frustum.cpp \
    ../../../main/main/Polyhedron.cpp \
    ../../../main/main/RegularTrianglePyramid.cpp \
    ../../../main/main/Round.cpp \
    ballform.cpp \
    frustumform.cpp \
    main.cpp \
    mainwindow.cpp \
    regulartrianglepyramidform.cpp

HEADERS += \
    ../../../main/main/Ball.h \
    ../../../main/main/Figure.h \
    ../../../main/main/Frustum.h \
    ../../../main/main/Polyhedron.h \
    ../../../main/main/RegularTrianglePyramid.h \
    ../../../main/main/Round.h \
    ballform.h \
    frustumform.h \
    mainwindow.h \
    regulartrianglepyramidform.h

FORMS += \
    ballform.ui \
    frustumform.ui \
    mainwindow.ui \
    regulartrianglepyramidform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
