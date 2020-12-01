#ifndef PARTYUPDATERMAIN_H
#define PARTYUPDATERMAIN_H

#include<iostream>
#include"Updater.h"


class PartyUpdatermain: public Updater {
   public:

    PartyUpdatermain();
    void updateName(int id, QString newName);
    void updateSize(int id, int newSize);
    void updateNameAndSize(int id, QString newName, int newSize);
    void addParty(QString newName, int newSize);
    void deleteParty(int id);
    void sitParty(int id, int tableNum);
};

#endif // PARTYUPDATERMAIN_H
