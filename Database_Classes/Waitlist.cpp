//
// Created by Admin on 11/8/2020.
//

#include "Waitlist.hpp"
//
// Created by Admin on 10/20/2020.
//

#include <fstream>
#include <cstdio>
#include "Waitlist.hpp"


Waitlist::Waitlist() {
    std::fstream file("party.txt");
    parseJSONArray(file);

    for(auto i: ListOfParties()){
        i->_status();
    }
}

bool Waitlist::addParty(std::string name, int id, int size) {
    Party *party = new Party;
    party->_name() = name;
    party->_id() = id;
    party->_size() = size;
    ListOfParties().push_back(party);
    return true;
}

bool Waitlist::removeParty(int id) {
    for (auto i : ListOfParties()) {
        if (i->_id() == id) {
            ListOfParties().pop_back(i->_id());
            return true;
        }
        return false;
    }
}