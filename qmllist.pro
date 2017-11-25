QT       += core gui quick

TARGET = qmllist
TEMPLATE = app

SOURCES += main.cpp \
    worker.cpp \
    simplelistmodel.cpp

HEADERS  +=\
    worker.h \
    dataobject.h \
    simplelistmodel.h

RESOURCES += \
    resources.qrc
