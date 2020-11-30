//Created by Ryan McKay

#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H

#include <QString>
#include <string>
#include "TableStatusEnum.h"

extern QString getTableStatusQString(TableStatus tableStatus);
extern std::string getTableStatusString(TableStatus tableStatus);
extern TableStatus convertStringToTableStatus(std::string tableStatus);

#endif // GLOBALFUNCTIONS_H
