QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Database_Classes/DataBaseManagerObject.cpp \
    Database_Classes/Pair.cpp \
    Database_Classes/PartyDMA.cpp \
    Database_Classes/PartyDMO.cpp \
    Database_Classes/TableDMA.cpp \
    Database_Classes/TableDMO.cpp \
    Database_Classes/databasemanagerarrayq.cpp \
    Updaters/Updater.cpp \
    Widgets/PartyLayoutWidget/PartyLayoutWidget.cpp \
    Windows/AddPartyDialog/AddPartyDialog.cpp \
    Windows/EditPartyDialog/EditPartyDialog.cpp \
    Windows/SeatPartyDialog/SeatPartyDialog.cpp \
    Windows/MainWindow/MainWindow.cpp \
    Widgets/TableButton/TableButton.cpp \
    globalFunctions.cpp \
    main.cpp

HEADERS += \
    Database_Classes/DataBaseManagerObject.hpp \
    Database_Classes/Pair.hpp \
    Database_Classes/PartyDMA.hpp \
    Database_Classes/PartyDMO.hpp \
    Database_Classes/TableDMA.hpp \
    Database_Classes/TableDMO.hpp \
    Database_Classes/databasemanagerarrayq.h \
    Party.h \
    TableStatusEnum.h \
    Updaters/Updater.h \
    Widgets/PartyLayoutWidget/PartyLayoutWidget.h \
    Windows/AddPartyDialog/AddPartyDialog.h \
    Windows/EditPartyDialog/EditPartyDialog.h \
    Windows/SeatPartyDialog/SeatPartyDialog.h \
    Windows/MainWindow/MainWindow.h \
    Widgets/TableButton/TableButton.h \
    globalFunctions.h

FORMS += \
    Windows/AddPartyDialog/AddPartyDialog.ui \
    Windows/EditPartyDialog/EditPartyDialog.ui \
    Windows/SeatPartyDialog/SeatPartyDialog.ui \
    Windows/MainWindow/MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    JSON_examples/waitlist2.txt \
    Widgets/PartyLayoutWidget/README.txt

