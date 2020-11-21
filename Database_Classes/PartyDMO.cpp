//
// Created by Admin on 10/20/2020.
//

#include <fstream>
#include "PartyDMO.hpp"
#include "DataBaseManagerObject.hpp"
#include "DataBaseManagerArray.hpp"
#include "Pair.hpp"

PartyDMO::PartyDMO() {
}

std::string PartyDMO::_name() {
    if (cachedName)
        return name;
    cachedName = true;
    name = valueForStringAttribute("name");
    return name;
}

int PartyDMO::_size() {
    if (cachedSize)
        return size;
    cachedSize = true;
    size = valueForIntegerAttribute("size");
    return size;
}

int PartyDMO::_id() {
    if (cachedId)
        return id;
    cachedId = true;
    id = valueForIntegerAttribute("id");
    return id;
}

