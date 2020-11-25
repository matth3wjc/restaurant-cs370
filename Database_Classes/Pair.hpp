
//Luke Shoulders

#ifndef PAIR_HPP
#define PAIR_HPP
#include <string>
#include <fstream>
#include <iostream>


class Pair {
    // represents a entity and its value:

public:
    Pair();
    Pair(std::string attributeValue, std::string attributeName);
    Pair(std::string attributeName, int);
    bool isNumber();  // is the datatype of the value of this entity integer?
    int numberValue();
    std::string stringValue();
    std::string attributeName();
    void parsePair(std::fstream &stream);

private:
    void parseKey(std::fstream &stream);
    void parseNumberAtt(std::fstream &stream);
    void parseStringAtt(std::fstream &stream);
    void parseNullAtt(std::fstream &stream);
    std::string _attributeName, _attributeStringValue;
    int _attributeNumberValue;
    bool _isNumber;
};


#endif //PAIR_HPP
