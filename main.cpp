#include "Windows\MainWindow\MainWindow.h"
#include "Database_Classes/PartyDMA.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PartyDMA tmp;
    tmp.addParty("kim", 1, 2);
    MainWindow w;
    w.show();
    return a.exec();
}
