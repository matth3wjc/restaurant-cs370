//
// Created by Admin on 10/20/2020.
//

#ifndef WAITLIST_HPP
#define WAITLIST_HPP
#include <iostream>
#include <vector>
#include "DataBaseManagerArray.hpp"

class DataBaseManagerObject;
class Party;

class Waitlist {
public:
    Waitlist();
    virtual DataBaseManagerObject *objectNode() {return new Party;}
    bool addParty(std::string name, int id, int size);
    bool removeParty(int id);

private:
    std::vector<Party*> ListOfParties(){
        return (std::vector<Party *>*) _listOfDataObjects;
    }

};




#endif //TABLE_PARTY_WAITLIST_WAITLIST_HPP

// pair