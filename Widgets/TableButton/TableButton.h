//Created by Ryan McKay

#ifndef TABLE_H
#define TABLE_H

#include <QPushButton>
#include "../../TableStatusEnum.h"
#include "../../Party.h"

class TableButton : public QPushButton
{
    Q_OBJECT
public:
    TableButton(int inTableNum, TableStatus inTableStatus);

    void deleteTable();

    int getTableNum() {return tableNum;};
    TableStatus getTableStatus() {return tableStatus;};
    void sitParty(Party* partyToSit);

    ~TableButton();

public slots:
    void onClicked();
private:
    Party* party;
    int tableNum;
    TableStatus tableStatus;
};

#endif // TABLE_H
