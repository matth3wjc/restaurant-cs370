//
// Created by nt101 on 11/2/2020.
//
#include <fstream>
#include "Floormap.hpp"

Floormap::Floormap(){
    std::fstream file("C:/Users/lukes/restaurant-cs370/JSON_examples/tables.txt");//added file path, make sure to set your own

    parseJSONArray(file); //DataBaseManagerArray

    for (auto i: *listOfTables()){
        i->_status();
        i->_nbr();
        i->_seats();
    }
}

bool Floormap::addTable(int nbr, std::string stat){
    auto table = new Table;
    table->setStatus(stat);
    table->nbr = nbr;
    //add to database
    std::vector<QString> url;
    url.push_back("table");
    url.push_back("1");                         // rest id
    url.push_back(QString::number(nbr));
    url.push_back(QString::fromStdString(stat));
    addToDataBase(url);

    listOfTables()->push_back(table);
    return true;
}

bool Floormap::setAllOpen(){
    for(auto i: *listOfTables()) {
        i->setStatus("open");//open
    }
    return true;
}

bool Floormap::setAllClosed(){
    for(auto i: *listOfTables()){
        i->setStatus("closed"); // closed
    }
    return true;
}
