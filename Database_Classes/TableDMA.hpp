//
// Created by Nicole Taketa
//

#ifndef CS370_TableDMA_HPP
#define CS370_TableDMA_HPP
#include "databasemanagerarrayq.h"  //new qt header
#include "TableDMO.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class TableDMA : public DataBaseManagerArrayQ{
public:
    TableDMA();
    DataBaseManagerObject *dataBaseManagerObject() {return new TableDMO;}
    bool addTable(int nbr, std::string);
    bool setAllOpen();
    bool setAllClosed();
    std::vector<TableDMO*> *listOfTables() { return (std::vector<TableDMO*> *) listOfDataObjects() ; }//added casting

};


#endif //CS370_TableDMA_HPP
