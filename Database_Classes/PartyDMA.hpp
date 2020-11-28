//
// Created by Admin on 10/20/2020.
//

#ifndef PartyDMA_HPP
#define PartyDMA_HPP

#include <iostream>
#include <vector>
#include "databasemanagerarrayq.h"
#include "PartyDMO.hpp"

//class DataBaseManagerObject;
//class Party;

class PartyDMA : public DataBaseManagerArrayQ{  //added inhertience
public:
    PartyDMA();
    DataBaseManagerObject *dataBaseManagerObject() {return new PartyDMO;}
    bool addParty(std::string name, int id, int size);
    bool removeParty(int id);
    std::vector<PartyDMO*> *listOfParties() {return (std::vector<PartyDMO *> *) _listOfDataObjects;};

private:

};




#endif
