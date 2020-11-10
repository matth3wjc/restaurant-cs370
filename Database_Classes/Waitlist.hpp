//
// Created by Admin on 10/20/2020.
//

#ifndef WAITLIST_HPP
#define WAITLIST_HPP
#include <iostream>
#include <vector>
#include "databasemanagerarrayq.h"
#include "Party.hpp"

//class DataBaseManagerObject;
//class Party;

class Waitlist : public DataBaseManagerArrayQ{  //added inhertience
public:
    Waitlist();
    DataBaseManagerObject *dataBaseManagerObject() {return new PartyDMO;}
    bool addParty(std::string name, int id, int size);
    bool removeParty(int id);

private:
    std::vector<PartyDMO*> *ListOfParties(){
        return (std::vector<PartyDMO *> *) _listOfDataObjects;
    }

};




#endif //TABLE_PARTY_WAITLIST_WAITLIST_HPP

// pair
