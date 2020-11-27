#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H

#include <QString>
#include <string>
#include "TableStatusEnum.h"

QString getTableStatusQString(TableStatus tableStatus);
std::string getTableStatusString(TableStatus tableStatus);
TableStatus convertStringToTableStatus(std::string tableStatus);

#endif // GLOBALFUNCTIONS_H
