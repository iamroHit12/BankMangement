QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    deposit.cpp \
    login.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp \
    transfer.cpp \
    userlist.cpp \
    usertransactions.cpp \
    withdraw.cpp

HEADERS += \
    admin.h \
    deposit.h \
    login.h \
    mainpage.h \
    mainwindow.h \
    transaction.h \
    transfer.h \
    userlist.h \
    usertransactions.h \
    withdraw.h

FORMS += \
    admin.ui \
    deposit.ui \
    login.ui \
    mainpage.ui \
    mainwindow.ui \
    transfer.ui \
    userlist.ui \
    usertransactions.ui \
    withdraw.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
