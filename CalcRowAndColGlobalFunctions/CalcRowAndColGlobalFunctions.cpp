#include "CalcRowAndColGlobalFunctions.h"
#include "Windows/MainWindow/MainWindow.h"

//tableNum is subtracted by one as counting actually starts at zero internally for the floormap.

//Dividing the tableNum - 1 by the width of the floormap gives the row number.
int calcRowFromTableNum(int tableNum)
{
    return (tableNum - 1) / MainWindow::FLOORMAP_WIDTH;
}

//The remainder of dividing tableNum - 1 by the width of the floormap gives the col number.
int calcColFromTableNum(int tableNum)
{
    return (tableNum - 1) % MainWindow::FLOORMAP_WIDTH;
}
