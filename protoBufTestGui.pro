#-------------------------------------------------
#
# Project created by QtCreator 2013-06-15T20:18:09
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = protoBufTestGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        message.pb.cc \
        cTcpThreadRead.cpp \
        cTcpSocket.cpp

HEADERS += mainwindow.h \
        cTcpThreadRead.h \
        cTcpSocket.h \
        message.pb.h \
    	dataType.h

#win32:
LIBS += -lprotobuf

DEPENDPATH += .

INCLUDEPATH += . \
               google\
               include

#FORMS += mainwindow.ui


# RESOURCES += textedit.qrc
# build_all:!build_pass {
#     CONFIG -= build_all
#     CONFIG += release
# }

OTHER_FILES += ./amessage.proto

 # install
 #target.path = $$[QT_INSTALL_DEMOS]/textedit
 #sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro *.html *.doc images
 #sources.path = $$[QT_INSTALL_DEMOS]/textedit
 #INSTALLS += target sources

 #symbian: include($$QT_SOURCE_TREE/demos/symbianpkgrules.pri)

