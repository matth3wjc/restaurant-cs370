#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "..\..\Widgets\TableButton\TableButton.h"
#include "..\..\Widgets\PartyLayoutWidget\PartyLayoutWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int tableNum = 1;
    for(int xIdx = 0; xIdx < floorMapWidth; ++xIdx)
    {
        std::vector<TableButton*> newRow;
        for(int yIdx = 0; yIdx < floorMapHeight; ++yIdx)
        {
            TableButton* table = new TableButton(tableNum, false);
            newRow.push_back(table);
            ui->FloormapScrollAreaContents->addWidget(table, xIdx, yIdx);
            ++tableNum;
        }
        floormap.push_back(newRow);
    }
}

MainWindow::~MainWindow()
{

}


void MainWindow::on_addToWaitlistButton_clicked()
{
    ++numOfParties;
    QString partyName = "Party " + QString::number(numOfParties, 10);
    PartyLayoutWidget* newParty = new PartyLayoutWidget(partyName, 5);
    waitList.push_back(newParty);
    ui->WaitlistScrollAreaContents->addLayout(newParty);
}

void MainWindow::on_actionDelete_All_Parties_On_Waitlist_triggered()
{
    for(int idx = numOfParties - 1; idx >= 0; --idx)
    {
        PartyLayoutWidget* partyButtonToDelete = waitList.at(idx);
        waitList.pop_back();
        ui->WaitlistScrollAreaContents->removeItem(partyButtonToDelete);
        delete partyButtonToDelete;
    }
    numOfParties = 0;
}
