#-------------------------------------------------
#
# Project created by QtCreator 2017-03-03T09:10:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = soft_reg_code_maker_qt
TEMPLATE = app


SOURCES += main.cpp\
        softregdialog.cpp \
    frmmessagebox.cpp \
    iconhelper.cpp \
    global.cpp

HEADERS  += softregdialog.h \
    frmmessagebox.h \
    iconhelper.h \
    myhelper.h \
    global.h

FORMS    += softregdialog.ui \
    frmmessagebox.ui

RESOURCES += \
    resource.qrc

RC_FILE = myapp.rc
