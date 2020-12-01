//Created by Ryan McKay

#include "TableButton.h"
#include "../../TableStatusEnum/TableStatusEnumGlobalFunctions.h"
#include "../../TableStatusEnum/TableStatusEnum.h"
#include "../../TableStatusEnum/TableStatusEnumGlobalFunctions.h"

TableButton::TableButton(int inTableNum)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setMinimumSize(50, 50);
    tableNum = inTableNum;
    tableStatus = TableStatus::DNE;
    party = nullptr;
    connect(this, &TableButton::clicked, this, &TableButton::onClicked);
    setText("+");
    setFlat(true);
}

void TableButton::setOpenFromDNE()
{
    tableStatus = TableStatus::OPEN;
    setFlat(false);
    setText(QString::number(tableNum, 10) + "\n" + getTableStatusQString(tableStatus));
}

void TableButton::sitParty(Party* partyToSit)
{
    setFlat(false);
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
            setOpenFromDNE();
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
