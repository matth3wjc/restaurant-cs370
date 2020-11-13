//Created by Ryan McKay

#include "MainWindow.h"
#include <QDialog>
#include "ui_mainwindow.h"
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
    //Not yet created
}

void MainWindow::on_addToWaitlistButton_clicked()
{
    //Dialog version
         // /*
        Party* newParty = nullptr;

            //TO MATTHEW: Below is the new constructor I would like to call
            //Your constructor's second argument should be a pointer reference variable. I.e. Party* &newParty
            //Your function will create a new Party assigned to this pointer.
            //With a reference pointer, when you update your local pointer in the AddPartyDialog class, it will update mine as well.
            //The party will need an int, not a string for it's size btw, so please convert it before passing it to the Party constructor.

        AddPartyDialog addPartyDialog(this, &newParty);

            //When I call exec() on addPartyDialog, it will return a signal if the user added the party or cancelled it.
            //Please read the QDialog Documentation, the Modal section, to learn how to do this.
            //You will also need to learn signals and slots for this.
            //If you cannot do the signal sending before the deadline, we can skip the success check for the demo.
            // (Btw you don't need to worry about input validation for this demo,
            // that can be added after the demo, after you've implemented the two above features)

            addPartyDialog.exec();

            PartyLayoutWidget* newPartyLayoutWidget = new PartyLayoutWidget(newParty);
            ++numOfParties;
            waitList.push_back(newPartyLayoutWidget);
            ui->WaitlistScrollAreaContents->addLayout(newPartyLayoutWidget);
        // */

    //Temp way that skips dialog. Comment this all out to use dialog version
     /*
    ++numOfParties;
    QString partyName = "Party " + QString::number(numOfParties, 10);
    Party* newParty = new Party(partyName, 5);

    PartyLayoutWidget* newPartyLayoutWidget = new PartyLayoutWidget(newParty);
    waitList.push_back(newPartyLayoutWidget);
    ui->WaitlistScrollAreaContents->addLayout(newPartyLayoutWidget);
     */
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
