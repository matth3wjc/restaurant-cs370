//
// Created by nt101 on 11/2/2020.
//

#include "TableDMO.hpp"
#include "PartyDMO.hpp"

TableDMO::TableDMO(){
    cachedNbr = false;
    cachedSeats = false;
    cachedStatus = false;
    cachedName = false;
    cachedSize = false;
    cachedId = false;
}

std::string TableDMO::_name() {
    if (cachedName)
        return name;
    cachedName = true;
    name = valueForStringAttribute("p_name");
    return name;
}

int TableDMO::_size() {
    if (cachedSize)
        return size;
    cachedSize = true;
    size = valueForIntegerAttribute("p_size");
    return size;
}

int TableDMO::_id() {
    if (cachedId)
        return id;
    cachedId = true;
    id = valueForIntegerAttribute("p_id ");
    return id;
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

std::string TableDMO::setStatus(std::string stat){
    if(cachedStatus)
        return status;
    cachedStatus = true;
    status = valueForStringAttribute(stat);
    return status;
}
