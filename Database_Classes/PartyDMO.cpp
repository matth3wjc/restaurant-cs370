//
// Created by Jorge Calderon
//

#include <fstream>
#include "PartyDMO.hpp"
#include "DataBaseManagerObject.hpp"
#include "Pair.hpp"

PartyDMO::PartyDMO() {
    cachedName = false;
    cachedSize = false;
    cachedId = false;
}

std::string PartyDMO::_name() {
    if (cachedName)
        return name;
    cachedName = true;
    name = valueForStringAttribute("p_name");
    return name;
}

int PartyDMO::_size() {
    if (cachedSize)
        return size;
    cachedSize = true;
    size = valueForIntegerAttribute("p_size");
    return size;
}

int PartyDMO::_id() {
    if (cachedId)
        return id;
    cachedId = true;
    id = valueForIntegerAttribute("p_id");
    return id;
}

