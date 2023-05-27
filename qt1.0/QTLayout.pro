QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AdminAccount.cpp \
    BankSystem.cpp \
    Code.cpp \
    SavingAccount.cpp \
    bktime.cpp \
    clerk.cpp \
    dialogclerk.cpp \
    dialogclerkclose.cpp \
    dialogclerkopen.cpp \
    dialoguser.cpp \
    dialoguseradd.cpp \
    dialoguserdeposit.cpp \
    dialogusertransfer.cpp \
    dialoguserwithdraw.cpp \
    friends.cpp \
    main.cpp \
    mainwindow.cpp \
    users.cpp

HEADERS += \
    AdminAccount.h \
    BankSystem.h \
    Code.h \
    SavingAccount.h \
    bktime.h \
    clerk.h \
    dialogclerk.h \
    dialogclerkclose.h \
    dialogclerkopen.h \
    dialoguser.h \
    dialoguseradd.h \
    dialoguserdeposit.h \
    dialogusertransfer.h \
    dialoguserwithdraw.h \
    friends.h \
    mainwindow.h \
    users.h

FORMS += \
    dialogclerk.ui \
    dialogclerkclose.ui \
    dialogclerkopen.ui \
    dialoguser.ui \
    dialoguseradd.ui \
    dialoguserdeposit.ui \
    dialogusertransfer.ui \
    dialoguserwithdraw.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
