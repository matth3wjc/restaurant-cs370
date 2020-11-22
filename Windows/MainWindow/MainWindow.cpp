//Created by Ryan McKay

#include "MainWindow.h"
#include "TableStatusEnum.h"
#include <QDialog>
#include "ui_MainWindow.h"
#include "../../Widgets/TableButton/TableButton.h"
#include "../../Widgets/PartyLayoutWidget/PartyLayoutWidget.h"
#include "../AddPartyDialog/AddPartyDialog.h"
#include "../../Party.h"
#include "../../Database_Classes/PartyDMA.hpp"
#include "../../Database_Classes/TableDMA.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Restuarant Table and Waitlist Manager");

    //This removes the buttons, but keeps the ui layout ratio we want
    ui->previousFloormapButton->setVisible(false);
    ui->nextFloormapButton->setVisible(false);
    ui->FloomapsComboBox->setVisible(false);

    int tableNum = 1;
    for(int xIdx = 0; xIdx < floorMapWidth; ++xIdx)
    {
        std::vector<TableButton*> newRow;
        for(int yIdx = 0; yIdx < floorMapHeight; ++yIdx)
        {
            TableButton* table = new TableButton(tableNum, TableStatus::DNE);
            newRow.push_back(table);
            ui->FloormapScrollAreaContents->addWidget(table, xIdx, yIdx);
            ++tableNum;
        }
        floormap.push_back(newRow);
    }
}

MainWindow::~MainWindow()
{
    //Not yet created
}

void MainWindow::on_addToWaitlistButton_clicked()
{
    Party* newParty = nullptr;
    AddPartyDialog addPartyDialog(this, &newParty);

    if(addPartyDialog.exec())
    {
        PartyLayoutWidget* newPartyLayoutWidget = new PartyLayoutWidget(newParty);
        ++numOfParties;
        waitList.push_back(newPartyLayoutWidget);
        ui->WaitlistScrollAreaContents->addLayout(newPartyLayoutWidget);
    }
}

void MainWindow::on_actionDelete_All_Parties_On_Waitlist_triggered()
{
    while(!waitList.empty())
    {
        PartyLayoutWidget* partyButtonToDelete = waitList.front();
        waitList.pop_front();
        ui->WaitlistScrollAreaContents->removeItem(partyButtonToDelete);
        delete partyButtonToDelete;
    }

    numOfParties = 0;
}

void MainWindow::on_actionDelete_All_Tables_triggered()
{
    for(int xIdx = 0; xIdx < floorMapWidth; ++xIdx)
    {
        for(int yIdx = 0; yIdx < floorMapHeight; ++yIdx)
        {
            floormap.at(yIdx).at(xIdx)->deleteTable();
        }
    }
}
