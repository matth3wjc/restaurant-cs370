#include "DataBaseManagerObject.hpp"
#include<iostream>


DataBaseManagerObject::DataBaseManagerObject() {
    _listOfDataItems = new std::vector<Pair *>;
}

DataBaseManagerObject::~DataBaseManagerObject() {
   while(!listOfDataItems()->empty()){
        delete listOfDataItems()->back();
        listOfDataItems()->pop_back();
    }
    delete _listOfDataItems;
}

void DataBaseManagerObject::parseDataObject(std::fstream &stream) {
    char c;

    if (!(stream >> c) || c != '{') {
        std::cout << "Not a valid JSON object: expected '{'\n";
        exit(2);
    }

    do {
        Pair *tmp = new Pair();
        tmp->parsePair(stream);
        listOfDataItems()->push_back(tmp);
        stream >> c;
    }while(c != '}');
}

std::string DataBaseManagerObject::valueForStringAttribute(std::string s){
    for(auto i: *listOfDataItems())
        if(s == i->attributeName())
            return i->stringValue();
    return "No matching key for: " + s;
}

int DataBaseManagerObject::valueForIntegerAttribute(std::string s) {
    for(auto i: *_listOfDataItems)
        if(s == i->attributeName())
            return i->numberValue();
    return 0;
}