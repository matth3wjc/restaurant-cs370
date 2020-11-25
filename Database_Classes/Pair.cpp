#include "Pair.hpp"


Pair::Pair(){
}

Pair::Pair(std::string attributeName, std::string attributeValue)
    :  _attributeName{attributeName}, _attributeStringValue{attributeValue}, _isNumber{false}{
}

Pair::Pair(std::string attributeName, int attributeNumberValue)
    : _attributeName{attributeName}, _attributeNumberValue{attributeNumberValue}, _isNumber{true}{
}

bool Pair::isNumber() {
    return _isNumber;
}

int Pair::numberValue() {
    return _attributeNumberValue;
}

std::string Pair::stringValue() {
    return _attributeStringValue;
}

std::string Pair::attributeName() {
    return _attributeName;
}

void Pair::parsePair(std::fstream &stream) {
    char c;

    parseKey(stream);

    stream >> c;

    if(isdigit(c)) {
        stream.unget();
        parseNumberAtt(stream);
    }
    else if(c == 'N' || c == 'n'){
        parseNullAtt(stream);
    }
    else{
        stream.unget();
        parseStringAtt(stream);
    }
}


void Pair::parseKey(std::fstream &stream) {
    char c;

    if(!(stream >> c) || c != '"'){
        std::cout << "Invalid pair: expected ' \" ' before key\n";
        exit(3);
    }

    stream.get(c);

    while(c != '"'){
        _attributeName.push_back(c);

        stream.get(c);
    }
    std::cout << _attributeName << '\n';

    if(!(stream >> c) || c != ':'){
        std::cout << "Invalid pair: expected ' : '  at the end of the attribute key";
        exit(3);
    }
}

void  Pair::parseNumberAtt(std::fstream &stream) {
    char c;

    if(!(stream >> c)){
        std::cout << "Invalid attribute: expected attribute to be a digit or to have a ' \" '  before it";
        exit(4);
    }

    stream.unget();

    stream >> _attributeNumberValue;
    std::cout << _attributeNumberValue << '\n';
}

void Pair::parseStringAtt(std::fstream &stream) {
    char c;

    if(!(stream >> c) || c != '"'){
        std::cout << "Invalid attribute: expected attribute to be a digit or to have a ' \" '  before it";
        exit(4);
    }

    stream.get(c);

    while(c != '"'){
        if(c == '\\') {
            _attributeStringValue.push_back(c);
            stream.get(c);
        }

        _attributeStringValue.push_back(c);

        stream.get(c);
    }

    std::cout << _attributeStringValue << '\n';
}

void Pair::parseNullAtt(std::fstream &stream){
    char c;

    stream.get(c);

    while(c != ',' && c != '}'){
        stream.get(c);
    }

    stream.unget();

    //set value
    _attributeNumberValue = -1;
}

