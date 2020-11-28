//Created by Ryan McKay

#include "TableButton.h"
#include "../../TableStatusEnum/TableStatusEnumGlobalFunctions.h"
#include "../../TableStatusEnum/TableStatusEnum.h"
#include "../../TableStatusEnum/TableStatusEnumGlobalFunctions.h"

TableButton::TableButton(int inTableNum, TableStatus inTableStatus)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setMinimumSize(50, 50);
    tableNum = inTableNum;
    tableStatus = inTableStatus;
    party = nullptr;
    connect(this, &TableButton::clicked, this, &TableButton::onClicked);
    if(tableStatus != TableStatus::DNE)
        setText(QString::number(tableNum, 10) + "\n" + getTableStatusQString(tableStatus));
    else
    {
        setText("+");
        setFlat(true);
    }
}

void TableButton::sitParty(Party* partyToSit)
{
    party = partyToSit;
    setText(QString::number(tableNum, 10) + "\n" + party->getName());
    tableStatus = TableStatus::SEATED;
}

void TableButton::onClicked()
{
    switch(tableStatus)
    {
    case TableStatus::DNE:
        {
            tableStatus = TableStatus::OPEN;
            setFlat(false);
            setText(QString::number(tableNum, 10) + "\n" + getTableStatusQString(tableStatus));
        }
        break;
    case TableStatus::OPEN:
        {
            tableStatus = TableStatus::DNE;
            setFlat(true);
            setText("+");
        }
        break;
    case TableStatus::SEATED:
        {
            delete party;
            party = nullptr;
            tableStatus = TableStatus::OPEN;
            setFlat(false);
            setText(QString::number(tableNum, 10) + "\n" + getTableStatusQString(tableStatus));
        }
        break;
    }
}

void TableButton::deleteTable()
{
    if(tableStatus != TableStatus::DNE)
    {
        if(tableStatus == TableStatus::SEATED)
        {
            delete party;
            party = nullptr;
        }
        tableStatus = TableStatus::DNE;
        setText("+");
        setFlat(true);
    }
}

TableButton::~TableButton()
{
    if(party)
    {
        delete party;
        party = nullptr;
    }
    disconnect(this, &TableButton::clicked, this, &TableButton::onClicked);
}
