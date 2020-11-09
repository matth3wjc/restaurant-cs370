#ifndef PARTY_H
#define PARTY_H

#include <QString>

class Party
{
public:
    Party(QString inName, int inSize) {name = inName; size = inSize;};
    QString getName() { return name; };
    void setName(QString inName) { name = inName; };
    int getSize() { return size; };
    void setSize(int inSize) { size = inSize; };
private:
    QString name;
    int size;
    int id = -1;
};

#endif
