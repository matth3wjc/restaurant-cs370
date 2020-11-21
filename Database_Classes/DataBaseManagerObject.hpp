//Luke Shoulders

#ifndef DATABASEMANAGEROBJECT_HPP
#define DATABASEMANAGEROBJECT_HPP
#include <vector>
#include <fstream>
#include "Pair.hpp"

class DataBaseManagerObject {
public:
    DataBaseManagerObject();
    virtual ~DataBaseManagerObject();
    std::vector<Pair *> *listOfDataItems() { return _listOfDataItems; }
    void parseDataObject(std::fstream &stream);
    std::string valueForStringAttribute(std::string s);
    int valueForIntegerAttribute(std::string s);

private:
    std::vector<Pair *> *_listOfDataItems;
};

#endif 


