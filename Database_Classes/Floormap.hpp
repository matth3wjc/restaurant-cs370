//
// Created by nt101 on 11/2/2020.
//

#ifndef CS370_FLOORMAP_HPP
#define CS370_FLOORMAP_HPP
#include "databasemanagerarrayq.h"  //new qt header
#include "Table.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Floormap : public DataBaseManagerArrayQ{
public:
    Floormap();
    DataBaseManagerObject *dataBaseManagerObject() {return new Table;}
    bool addTable(int nbr, std::string);
    bool setAllOpen();
    bool setAllClosed();
    std::vector<Table*> *listOfTables() { return (std::vector<Table*> *) listOfDataObjects() ; }//added casting

};


#endif //CS370_FLOORMAP_HPP
