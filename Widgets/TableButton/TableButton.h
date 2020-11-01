#ifndef TABLE_H
#define TABLE_H

#include <QPushButton>

class TableButton : public QPushButton
{
    Q_OBJECT
public:
    TableButton(int, bool);
    ~TableButton();

public slots:
    void onClicked();
private:
    int tableNum;
    bool exists;
    static int numOfTables;
};

#endif // TABLE_H
