//
// Created by Admin on 10/20/2020.
//

#ifndef TABLE_PARTY_WAITLIST_PARTY_HPP
#define TABLE_PARTY_WAITLIST_PARTY_HPP
#include <iostream>
#include "DataBaseManagerObject.hpp"


class DataBaseManagerObject;

class PartyDMO : public DataBaseManagerObject{ //changed name to avoid redefintio
public:
    PartyDMO();
    std::string _name();
    int _size();
    int _id();

// private: temporary change, add accesors and make private again
    std::string name; //<key, value>
    int size, id;
    bool cachedName, cachedId, cachedSize;
};


#endif //TABLE_PARTY_WAITLIST_PARTY_HPP
