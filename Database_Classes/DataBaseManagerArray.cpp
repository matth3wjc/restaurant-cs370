#include"DataBaseManagerArray.hpp"
#include<iostream>

DataBaseManagerArray::DataBaseManagerArray(){
    _listOfDataObjects = new std::vector<DataBaseManagerObject *>;
}

DataBaseManagerArray::~DataBaseManagerArray(){
    while(!listOfDataObjects()->empty()){
        delete listOfDataObjects()->back();
        listOfDataObjects()->pop_back();
    }
    delete _listOfDataObjects;
}

void DataBaseManagerArray::parseJSONArray(std::fstream &stream) {
    char c;
    stream >> c;

    if(c != '['){
        std::cout << "Not a JSON array";
        exit(1);
    }

    while(c != ']'){
        DataBaseManagerObject *tmp = dataBaseManagerObject();

        tmp->parseDataObject(stream);

        listOfDataObjects()->push_back(tmp);

        stream >> c;
        if(c != ']' && c != ','){
            std::cout << R"(Not a valid JSON array, expected "]" or "," after object)";
            exit(4);
        }
    }
}