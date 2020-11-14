//Created by Ryan McKay

#include "TableButton.h"
#include "../../globalFunctions.h"
#include "../../TableStatusEnum.h"
#include "../../globalFunctions.h"

TableButton::TableButton(int inTableNum, TableStatus inTableStatus)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setMinimumSize(50, 50);
    tableNum = inTableNum;
    tableStatus = inTableStatus;
    connect(this, &TableButton::clicked, this, &TableButton::onClicked);
    if(tableStatus != TableStatus::DNE)
        setText(QString::number(tableNum, 10) + "\n" + getTableStatusQString(tableStatus));
    else
    {
        setText("+");
        setFlat(true);
    }

}

void TableButton::onClicked()
{
    if(tableStatus == TableStatus::DNE)
    {
        tableStatus = TableStatus::OPEN;
        setFlat(false);
        setText(QString::number(tableNum, 10) + "\n" + getTableStatusQString(tableStatus));
    }
}

void TableButton::deleteTable()
{
    if(tableStatus != TableStatus::DNE)
    {
        tableStatus = TableStatus::DNE;
        setText("+");
        setFlat(true);
    }
}

TableButton::~TableButton()
{
    disconnect(this, &TableButton::clicked, this, &TableButton::onClicked);
}
