//Created by Ryan McKay

#include "MainWindow.h"
#include "../../TableStatusEnum/TableStatusEnum.h"
#include "../../TableStatusEnum/TableStatusEnumGlobalFunctions.h"
#include <QDialog>
#include <QMessageBox>
#include <QDir>
#include "ui_MainWindow.h"
#include "../../Widgets/TableButton/TableButton.h"
#include "../../Widgets/PartyLayoutWidget/PartyLayoutWidget.h"
#include "../AddPartyDialog/AddPartyDialog.h"
#include "../../Party.h"
#include "../../Database_Classes/PartyDMA.hpp"
#include "../../Database_Classes/TableDMA.hpp"
#include "../../Windows/EditPartyDialog/EditPartyDialog.h"
#include "../../Windows/SeatPartyDialog/SeatPartyDialog.h"
#include "../../CalcRowAndColGlobalFunctions/CalcRowAndColGlobalFunctions.h"
#include "../../Updaters/PartyUpdatermain.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QDir dirMaker;
    dirMaker.mkpath("./JsonFiles");

    ui->setupUi(this);
    setWindowTitle("Restaurant Table and Waitlist Manager");

    //This buttons are currently unused, but keeps the ui layout ratio we want
    ui->previousFloormapButton->setVisible(false);
    ui->nextFloormapButton->setVisible(false);
    ui->FloomapsComboBox->setVisible(false);

    //Creates the collection of tables in floormap, all are set to DNE
    int tableNum = 1;
    for(int xIdx = 0; xIdx < FLOORMAP_WIDTH; ++xIdx)
    {
        std::vector<TableButton*> newRow;
        for(int yIdx = 0; yIdx < FLOORMAP_HEIGHT; ++yIdx)
        {
            TableButton* table = new TableButton(tableNum);
            newRow.push_back(table);
            ui->FloormapScrollAreaContents->addWidget(table, xIdx, yIdx);
            ++tableNum;
        }
        floormap.push_back(newRow);
    }

    //loading the parties, stored on the waitlist, from the database
    partyDMArray = new PartyDMA();
    connect(partyDMArray, &PartyDMA::ok, this, &MainWindow::databasePartyLoadSuccess);
    partyDMArray->fileDownload("http://localhost:3000/api/party/1");

    tableDMArray = new TableDMA();
    connect(tableDMArray, &TableDMA::ok, this, &MainWindow::databaseTableLoadSuccess);
    tableDMArray->fileDownload("http://localhost:3000/api/table");

    //Create the party database updater
    partyUpdater = new PartyUpdatermain();
}

MainWindow::~MainWindow()
{
    deleteAllParties();

    //Delete all the TableButtons
    while(!floormap.empty())
    {
        std::vector<TableButton*> rowOfTables = floormap.back();
        while(!rowOfTables.empty())
        {
            TableButton* tableToDelete = rowOfTables.back();
            rowOfTables.pop_back();
            delete tableToDelete;
            tableToDelete = nullptr;
        }
    }

}







/* Database slot functions */
void MainWindow::databasePartyLoadSuccess()
{
    //QMessageBox::warning(this, "At Slot", "At databasePartyLoadSuccess");
    for(auto partyToLoad : *(partyDMArray->listOfParties()))
    {
        Party* newParty = new Party(QString::fromStdString(partyToLoad->_name()), partyToLoad->_size(), partyToLoad->_id());
        addPartyToWaitlist(newParty);
    }

    disconnect(partyDMArray, &PartyDMA::ok, this, &MainWindow::databasePartyLoadSuccess);
}

void MainWindow::databaseTableLoadSuccess()
{
    //QMessageBox::warning(this, "At Slot", "At databaseTableLoadSuccess");
    int row = 0;
    int col = 0;

    for(auto tableToLoad : *(tableDMArray->listOfTables()))
    {
        //QMessageBox::warning(this, "At Slot", QString::fromStdString(tableToLoad->_status()));
        if(row == FLOORMAP_HEIGHT)
        {
            //This is put here, so that if there are too many tables, instead of crashing, it only loads as many as it can fit.
            QMessageBox::warning(this, "Database Error", "The number of tables in the database does not match the number of tables in the program.");
            break;
        }
        TableStatus tableStatus = convertStringToTableStatus(tableToLoad->_status());
        if(tableStatus == TableStatus::OPEN)
            floormap.at(row).at(col)->setOpenFromDNE();
        else if(tableStatus == TableStatus::SEATED)
        {
            Party* partyAtTable = new Party(QString::fromStdString(tableToLoad->_name()), tableToLoad->_size(), tableToLoad->_id());
            floormap.at(row).at(col)->sitParty(partyAtTable);
        }

        ++col;
        if(col == FLOORMAP_WIDTH)
        {
            col = 0;
            ++row;
        }
    }
    disconnect(tableDMArray, &TableDMA::ok, this, &MainWindow::databaseTableLoadSuccess);
}





/* Native ui components' slot functions */
void MainWindow::on_addToWaitlistButton_clicked()
{
    QString newPartyName;
    int newPartySize;
    AddPartyDialog addPartyDialog(newPartyName, newPartySize, this);

    if(addPartyDialog.exec())
    {
        Party* newParty = new Party(newPartyName, newPartySize, lifeTimeNumOfParties);
        addPartyToWaitlist(newParty);
        ++lifeTimeNumOfParties;
    }
}

void MainWindow::on_actionDelete_All_Parties_On_Waitlist_triggered()
{
    deleteAllParties();
}

void MainWindow::on_actionDelete_All_Tables_triggered()
{
    for(int xIdx = 0; xIdx < FLOORMAP_WIDTH; ++xIdx)
    {
        for(int yIdx = 0; yIdx < FLOORMAP_HEIGHT; ++yIdx)
        {
            floormap.at(yIdx).at(xIdx)->deleteTable();
        }
    }
}







/* Slots for PartyLayoutWidget's buttons
    When one of PartyLayoutWidget's buttons is pressed, it emits a signal,
    that is recieved by MainWindow, so it can handle them.                  */

void MainWindow::editPartyButtonClicked(PartyLayoutWidget* partyLayoutWidgetToEdit)
{
    QString newPartyName = partyLayoutWidgetToEdit->getParty()->getName();
    int newPartySize = partyLayoutWidgetToEdit->getParty()->getSize();
    EditPartyDialog editPartyDialog(newPartyName, newPartySize, this);
    if(editPartyDialog.exec())
    {
        partyLayoutWidgetToEdit->updateParty(newPartyName, newPartySize);
        partyUpdater->updateNameAndSize(partyLayoutWidgetToEdit->getParty()->getID(), newPartyName, newPartySize);
    }
}

void MainWindow::sitPartyButtonClicked(PartyLayoutWidget* partyLayoutWidgetToEdit)
{
    int tableToSit;
    SeatParty seatPartyDialog(tableToSit, &floormap, this);
    if(seatPartyDialog.exec())
    {
        partyUpdater->sitParty(partyLayoutWidgetToEdit->getParty()->getID(), tableToSit);
        floormap.at(calcRowFromTableNum(tableToSit))
                .at(calcColFromTableNum(tableToSit))
                ->sitParty(partyLayoutWidgetToEdit->getParty());
        removePartyFromWaitlist(partyLayoutWidgetToEdit, false);
    }
}

void MainWindow::deletePartyButtonClicked(PartyLayoutWidget* partyLayoutWidgetToEdit)
{
    partyUpdater->deleteParty(partyLayoutWidgetToEdit->getParty()->getID());
    removePartyFromWaitlist(partyLayoutWidgetToEdit, true);
}







/* Helper functions */
void MainWindow::deleteAllParties()
{
    while(!waitList.empty())
    {
        PartyLayoutWidget* partyButtonToDelete = waitList.front();
        waitList.pop_front();
        ui->WaitlistScrollAreaContents->removeItem(partyButtonToDelete);
        delete partyButtonToDelete;
    }
}

void MainWindow::addPartyToWaitlist(Party* partyToAdd)
{
    PartyLayoutWidget* newPartyLayoutWidget = new PartyLayoutWidget(partyToAdd);
    waitList.push_back(newPartyLayoutWidget);

    ui->WaitlistScrollAreaContents->addLayout(newPartyLayoutWidget);

    connect(newPartyLayoutWidget, &PartyLayoutWidget::editButtonClicked, this, &MainWindow::editPartyButtonClicked);
    connect(newPartyLayoutWidget, &PartyLayoutWidget::sitButtonClicked, this, &MainWindow::sitPartyButtonClicked);
    connect(newPartyLayoutWidget, &PartyLayoutWidget::deleteButtonClicked, this, &MainWindow::deletePartyButtonClicked);
}

    //The bool var "deleteParty" determines whether to actually delete the party or not
    //Set it to false when calling the function after moving a party to a table.
    //      The above option simply deletes all references to the party.
    //Set it to true when calling the function to delete party as a whole.
    //
    //In either case, the function deletes the passed PartyLayoutWidget
void MainWindow::removePartyFromWaitlist(PartyLayoutWidget* partyLayoutWidgetToDelete, bool deleteParty)
{

    auto partyIter = waitList.begin();
    bool partyToBeRemovedFound = false;
    while(!partyToBeRemovedFound && partyIter != waitList.end())
    {
        if((*partyIter)->getParty()->getID() == partyLayoutWidgetToDelete->getParty()->getID())
        {
            waitList.erase(partyIter);
            partyToBeRemovedFound = true;
        }
        else
            ++partyIter;
    }
    if(partyToBeRemovedFound)
    {
        if(deleteParty)
        {
            delete partyLayoutWidgetToDelete->getParty();
            partyLayoutWidgetToDelete->setPartyPointerToNull();
        }
        else
        {
            partyLayoutWidgetToDelete->setPartyPointerToNull();
        }

        ui->WaitlistScrollAreaContents->removeItem(partyLayoutWidgetToDelete);
        delete partyLayoutWidgetToDelete;
    }
    else
    {
        QMessageBox::warning(this, "Error",  "The party you are trying to delete does not exist.");
        exit(1);
    }
}
