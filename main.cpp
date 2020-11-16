#include "Windows\MainWindow\MainWindow.h"
#include "Database_Classes/PartyDMA.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
