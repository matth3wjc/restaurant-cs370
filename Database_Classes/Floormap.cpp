//
// Created by nt101 on 11/2/2020.
//

#include "Floormap.hpp"

Floormap::Floormap(){
    std::fstream file("tables.txt");

    file->parseJSONArray(file); //DataBaseManagerArray

    for (auto i: *listOfTables()){
        i->_status();
        i->_nbr();
        i->_seats();
    }
}

bool Floormap::setTableStat(int nbr, std::string stat){
    auto table = new Table;
    table->setStatus(stat);
    listOfTables()->push_back(table);
    return true;
}

bool Floormap::setAllOpen(){
    for(auto i: *listOfTables()) {
        i->setTableStat(i, "open");//open
    }
    return true;
}

bool Floormap::setAllClosed(){
    for(auto i: *listOfTables()){
        i->setTableStat(i, "closed"); // closed
    }
    return true;
}
