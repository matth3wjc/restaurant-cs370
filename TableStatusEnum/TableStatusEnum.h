//Created by Ryan McKay

#ifndef TABLESTATUS_H
#define TABLESTATUS_H

#include <QString>
#include <string>

enum class TableStatus
{
    DNE,
    OPEN,
    SEATED,
    SALAD,
    ENTREE,
    CHECK,
    BUSS,
    CLOSED
};

#endif // TABLESTATUS_H
