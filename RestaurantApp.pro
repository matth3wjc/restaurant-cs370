QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Database_Classes/DataBaseManagerObject.cpp \
    Database_Classes/Floormap.cpp \
    Database_Classes/Pair.cpp \
    Database_Classes/Party.cpp \
    Database_Classes/Table.cpp \
    Database_Classes/Waitlist.cpp \
    Database_Classes/databasemanagerarrayq.cpp \
    Widgets/PartyLayoutWidget/PartyLayoutWidget.cpp \
    Windows/AddPartyDialog/AddPartyDialog.cpp \
    Windows/MainWindow/MainWindow.cpp \
    Widgets/TableButton/TableButton.cpp \
    main.cpp

HEADERS += \
    Database_Classes/DataBaseManagerObject.hpp \
    Database_Classes/Floormap.hpp \
    Database_Classes/Pair.hpp \
    Database_Classes/Party.hpp \
    Database_Classes/Table.hpp \
    Database_Classes/Waitlist.hpp \
    Database_Classes/databasemanagerarrayq.h \
    Party.h \
    Widgets/PartyLayoutWidget/PartyLayoutWidget.h \
    Windows/AddPartyDialog/AddPartyDialog.h \
    Windows/MainWindow/MainWindow.h \
    Widgets/TableButton/TableButton.h

FORMS += \
    Windows/AddPartyDialog/AddPartyDialog.ui \
    Windows/MainWindow/MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
