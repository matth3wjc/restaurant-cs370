//
// Created by Nicole Taketa
//
#include <fstream>
#include "TableDMA.hpp"

TableDMA::TableDMA(){
    setFilePath("./JSON_files/tables.txt"); //Edited by Ryan McKay
/*
    for (auto i: *listOfTables()){
        i->_status();
        i->_nbr();
        i->_seats();
    }*/
}

bool TableDMA::addTable(int nbr, std::string stat){
    auto table = new TableDMO;
    table->setStatus(stat);
    table->nbr = nbr;
    //add to database
    std::vector<QString> url;
    url.push_back("table");
    url.push_back("1");                         // rest id
    url.push_back(QString::number(nbr));
    url.push_back(QString::fromStdString(stat));
    //addToDataBase(url);

    listOfTables()->push_back(table);
    return true;
}

bool TableDMA::setAllOpen(){
    for(auto i: *listOfTables()) {
        i->setStatus("open");//open
    }
    return true;
}

bool TableDMA::setAllClosed(){
    for(auto i: *listOfTables()){
        i->setStatus("closed"); // closed
    }
    return true;
}
