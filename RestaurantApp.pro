QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Windows/AddPartyDialog/AddPartyDialog.cpp \
    Windows/MainWindow/MainWindow.cpp \
    Widgets/PartyLayoutWidget/PartyLayoutWidget.cpp \
    Widgets/TableButton/TableButton.cpp \
    main.cpp

HEADERS += \
    Party.h \
    Windows/AddPartyDialog/AddPartyDialog.h \
    Windows/MainWindow/MainWindow.h \
    Widgets/PartyLayoutWidget/PartyLayoutWidget.h \
    Widgets/TableButton/TableButton.h

FORMS += \
    Windows/AddPartyDialog/AddPartyDialog.ui \
    Windows/MainWindow/MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
