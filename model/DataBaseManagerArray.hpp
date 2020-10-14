#ifndef DATABASEMANAGERARRAY_HPP
#define DATABASEMANAGERARRAY_HPP
#include <fstream>
#include <vector>
#include "DataBaseManagerObject.hpp"


class DataBaseManagerArray {
public:
    DataBaseManagerArray();
    ~DataBaseManagerArray();
    std::vector<DataBaseManagerObject *> *listOfDataObjects() { return _listOfDataObjects; }
    virtual DataBaseManagerObject *dataBaseManagerObject() = 0;
    int numJSONObjects();
    void parseJSONArray(std::fstream &stream);

protected:
    std::vector<DataBaseManagerObject *> *_listOfDataObjects;

};


#endif //DATABASEMANAGERARRAY_HPP