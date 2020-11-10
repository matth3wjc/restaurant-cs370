//
// Created by Admin on 10/20/2020.
//

#ifndef TABLE_PARTY_WAITLIST_PARTY_HPP
#define TABLE_PARTY_WAITLIST_PARTY_HPP
#include <iostream>
#include "Pair.hpp"


class DataBaseManagerObject;

class Party {
public:
    Party();
    std::string _name();
    int _size();
    int _id();

private:
    std::string name; //<key, value>
    int size, id;
    bool cachedName, cachedId, cachedSize;
};


#endif //TABLE_PARTY_WAITLIST_PARTY_HPP