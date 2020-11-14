//Created by Ryan McKay

#ifndef TABLE_H
#define TABLE_H

#include <QPushButton>
#include "../../TableStatusEnum.h"

class TableButton : public QPushButton
{
    Q_OBJECT
public:
    TableButton(int, TableStatus);

    void deleteTable();

    int getTableNum() {return tableNum;};
    TableStatus getTableStatus() {return tableStatus;};

    ~TableButton();

public slots:
    void onClicked();
private:
    int tableNum;
    TableStatus tableStatus;
};

#endif // TABLE_H
