//Created by Ryan McKay

#ifndef PARTY_H
#define PARTY_H

#include <QString>

class Party
{
public:
    Party(QString inName, int inSize, int inId) {name = inName; size = inSize; id = inId;};
    QString getName() { return name; };
    void setName(QString inName) { name = inName; };
    int getSize() { return size; };
    void setSize(int inSize) { size = inSize; };
    int getID() {return id;};
private:
    QString name;
    int size;
    int id = -1;
};

#endif
