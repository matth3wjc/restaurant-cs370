//
// Created by nt101 on 11/2/2020.
//

#include "TableDMO.hpp"

TableDMO::TableDMO(){
}

std::string TableDMO::_status(){
    if(cachedStatus)
        return status;
    cachedStatus = true;
    status = valueForStringAttribute("status");
    return status;
}

int TableDMO::_nbr(){
    if( cachedNbr )  //right here the bool cached variable are used to check if you called one of the functions yet
        return nbr;              //if you have just return the value
    cachedNbr = true;
    nbr = valueForIntegerAttribute("nbr"); //otherwise call the function
    return nbr;
}

int TableDMO::_seats(){
    if(cachedSeats)
        return seats;
    cachedSeats = true;
    seats = valueForIntegerAttribute("seats");
    return seats;
}

void TableDMO::setStatus(std::string stat){
    status = valueForStringAttribute(stat);
}
