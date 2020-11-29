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

    switch(tableStatus)
    {
    case TableStatus::DNE:
        {
            setText("+");
            setFlat(true);
        }
        break;
    case TableStatus::OPEN:
        {
            setFlat(false);
            setText(QString::number(tableNum, 10) + "\n" + getTableStatusQString(tableStatus));
        }
        break;
    case TableStatus::SEATED:
        {

        }
        break;
    }
}

void TableButton::sitParty(Party* partyToSit)
{
    party = partyToSit;
    QString buttonText = QString::number(tableNum, 10) + "\n";
    if(party->getName().size() <= 5)
        setText(buttonText + party->getName());
    else
    {
        QString truncatedName = party->getName();
        truncatedName.truncate(5);
        setText(buttonText + truncatedName + "...");
    }

    tableStatus = TableStatus::SEATED;
    setToolTip(party->getName());
}

void TableButton::onClicked()
{
    switch(tableStatus)
    {
    case TableStatus::DNE:
        {
            //set to OPEN
            tableStatus = TableStatus::OPEN;
            setFlat(false);
            setText(QString::number(tableNum, 10) + "\n" + getTableStatusQString(tableStatus));
        }
        break;
    case TableStatus::OPEN:
        {
            //set to DNE
            tableStatus = TableStatus::DNE;
            setFlat(true);
            setText("+");
        }
        break;
    case TableStatus::SEATED:
        {
            //set to OPEN
            delete party;
            party = nullptr;
            tableStatus = TableStatus::OPEN;
            setFlat(false);
            setText(QString::number(tableNum, 10) + "\n" + getTableStatusQString(tableStatus));
            setToolTip("");
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
        setToolTip("");
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
