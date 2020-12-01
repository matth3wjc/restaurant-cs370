//Created by Ryan McKay

#include "TableStatusEnumGlobalFunctions.h"
#include <QString>
#include <string>
#include "TableStatusEnum.h"


QString getTableStatusQString(TableStatus tableStatus)
{
    switch(tableStatus)
    {
    case TableStatus::DNE:
        return "DNE";
    case TableStatus::OPEN:
        return "Open";
    case TableStatus::SEATED:
        return "Seated";
    case TableStatus::SALAD:
        return "Salad";
    case TableStatus::ENTREE:
        return "Entree";
    case TableStatus::CHECK:
        return "Check";
    case TableStatus::BUSS:
        return "Buss";
    case TableStatus::CLOSED:
        return "Closed";
    } 
}

std::string convertTableStatusToString(TableStatus tableStatus)
{
    switch(tableStatus)
    {
    case TableStatus::DNE:
        return "DNE";
    case TableStatus::OPEN:
        return "OPEN";
    case TableStatus::SEATED:
        return "SEATED";
    case TableStatus::SALAD:
        return "SALAD";
    case TableStatus::ENTREE:
        return "ENTREE";
    case TableStatus::CHECK:
        return "CHECK";
    case TableStatus::BUSS:
        return "BUSS";
    case TableStatus::CLOSED:
        return "CLOSED";
    }
}

TableStatus convertStringToTableStatus(std::string tableStatus)
{
    if(tableStatus == "DNE")
        return TableStatus::DNE;
    if(tableStatus == "OPEN")
        return TableStatus::OPEN;
    if(tableStatus == "SEATED")
        return TableStatus::SEATED;
    if(tableStatus == "SALAD")
        return TableStatus::SALAD;
    if(tableStatus == "ENTREE")
        return TableStatus::ENTREE;
    if(tableStatus == "CHECK")
        return TableStatus::CHECK;
    if(tableStatus == "BUSS")
        return TableStatus::BUSS;
    if(tableStatus == "CLOSED")
        return TableStatus::CLOSED;
}
