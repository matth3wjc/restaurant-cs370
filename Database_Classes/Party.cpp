//
// Created by Admin on 10/20/2020.
//

#include <fstream>
#include "Party.hpp"
#include "DataBaseManagerObject.hpp"
#include "DataBaseManagerArray.hpp"
#include "Pair.hpp"

Party::Party() {
    parseJsonArray();
}

std::string Party::_name() {
    if (cachedName)
        return name;
    cachedName = true;
    name = valueForStringAttribute("name");
    return name;
}

int Party::_size() {
    if (cachedSize)
        return size;
    cachedSize = true;
    size = valueForIntegerAttribute("size");
    return size;
}

int Party::_id() {
    if (cachedId)
        return id;
    cachedId = true;
    id = valueForIntegerAttribute("id");
    return id;
}