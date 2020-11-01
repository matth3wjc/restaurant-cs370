#include "TableButton.h"

TableButton::TableButton(int inTableNum, bool inExists)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setMinimumSize(50, 50);
    tableNum = inTableNum;
    exists = inExists;
    connect(this, &TableButton::clicked, this, &TableButton::onClicked);
    if(exists)
        setText(QString::number(tableNum, 10));
    else
        setText("+");

}

void TableButton::onClicked()
{
    if(!exists)
    {
        exists = true;
        setText(QString::number(tableNum, 10));
    }
}

TableButton::~TableButton()
{
    disconnect(this, &TableButton::clicked, this, &TableButton::onClicked);
}

