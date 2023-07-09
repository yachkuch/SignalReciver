QT       += core gui charts network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database.cpp \
    main.cpp \
    mainwindow.cpp \
    network.cpp \
    widgetabout.cpp \
    widgetchart.cpp

HEADERS += \
    database.h \
    mainwindow.h \
    network.h \
    widgetabout.h \
    widgetchart.h

FORMS += \
    mainwindow.ui \
    widgetabout.ui \
    widgetchart.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
