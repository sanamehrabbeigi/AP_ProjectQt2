#-------------------------------------------------
#
# Project created by QtCreator 2019-06-30T18:16:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AP_Project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Source.cpp \
        addnorthvilladiag.cpp \
        addpicture.cpp \
        addrentdocument.cpp \
        addsalediag.cpp \
        addsouthvilladiag.cpp \
        apartment.cpp \
        global.cpp \
        house.cpp \
        logindialog.cpp \
        main.cpp \
        mainwindow.cpp \
        managerpanel.cpp \
        normaluserpanel.cpp \
        rent.cpp \
        sale.cpp \
        showmanagerdiag.cpp \
        showpicture.cpp \
        signupdialog.cpp \
        startandend.cpp \
        user.cpp \
        villa.cpp

HEADERS += \
        addnorthvilladiag.h \
        addpicture.h \
        addrentdocument.h \
        addsalediag.h \
        addsouthvilladiag.h \
        apartment.h \
        global.h \
        house.h \
        logindialog.h \
        mainwindow.h \
        managerpanel.h \
        normaluserpanel.h \
        rent.h \
        sale.h \
        showmanagerdiag.h \
        showpicture.h \
        signupdialog.h \
        startandend.h \
        user.h \
        villa.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
