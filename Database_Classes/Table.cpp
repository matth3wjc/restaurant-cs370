//
// Created by nt101 on 11/2/2020.
//

#include "Table.hpp"

Table::Table(){
}

std::string Table::_status(){
    if(cachedStatus)
        return status;
    cachedStatus = true;
    status = valueForStringAttribute("status");
    return status;
}

int Table::_nbr(){
    if( cachedNbr )  //right here the bool cached variable are used to check if you called one of the functions yet
        return nbr;              //if you have just return the value
    cachedNbr = true;
    nbr = valueForIntegerAttribute("nbr"); //otherwise call the function
    return nbr;
}

int Table::_seats(){
    if(cachedSeats)
        return seats;
    cachedSeats = true;
    seats = valueForIntegerAttribute("seats");
    return seats;
}

void Table::setStatus(std::string stat){
    status = valueForStringAttribute(stat);
}
