//
// Created by Jorge Calderon
//

#include <fstream>
#include <cstdio>
#include "PartyDMA.hpp"


PartyDMA::PartyDMA() {
    setFilePath("../RestaurantApp/JSON_files/waitlist.txt");
    for(auto i: *listOfParties()){
        i->_name();
    }
}

bool PartyDMA::addParty(std::string name, int id, int size) {
    PartyDMO *party = new PartyDMO;
    party->name = name;
    party->id = id;
    party->size = size;
    //add to database
    std::vector<QString> url;
    url.push_back("party");
    url.push_back("1");                         // rest id
    url.push_back(QString::fromStdString(name));
    url.push_back(QString::number(size));
    //fileDownload();

    listOfParties()->push_back(party);
    return true;
}

bool PartyDMA::removeParty(int id) {
    for (auto i : *listOfParties()) {
        if (i->_id() == id) {
            //ListOfParties()->pop_back(i->_id());
            return true;
        }
        return false;
    }
}
