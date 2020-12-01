//
// Created by Nicole Taketa
//

#ifndef CS370_TableDMO_HPP
#define CS370_TableDMO_HPP
#include <string>
#include <iostream>
#include <fstream>
#include "DataBaseManagerObject.hpp"
#include "Pair.hpp"

class TableDMO : public DataBaseManagerObject{
public:
    TableDMO();
    std::string _status();
    int _nbr();
    int _seats();
    std::string _name();
    int _size();
    int _id();
    std::string setStatus(std::string);

//private: temporary fix, add accesors
    std::string status, name;
    int nbr, seats, size, id;
    bool cachedStatus, cachedNbr, cachedSeats, cachedName, cachedId, cachedSize;
};


#endif //CS370_TableDMO_HPP

