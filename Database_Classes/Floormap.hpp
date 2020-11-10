//
// Created by nt101 on 11/2/2020.
//

#ifndef CS370_FLOORMAP_HPP
#define CS370_FLOORMAP_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Floormap {
public:
    Floormap();
    virtual DataBaseManagerObject *objectNode() {new Table}
    bool setTableStat(int nbr, std::string);
    bool setAllOpen();
    bool setAllClosed();
    std::vector<Table*> *listOfTables() { return _listOfDataObjects; }
private:
    std::vector<Table *> *_listOfDataObjects;

};


#endif //CS370_FLOORMAP_HPP
