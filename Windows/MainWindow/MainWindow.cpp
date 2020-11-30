//Created by Ryan McKay

#include "MainWindow.h"
#include "../../TableStatusEnum/TableStatusEnum.h"
#include "../../TableStatusEnum/TableStatusEnumGlobalFunctions.h"
#include <QDialog>
#include <QMessageBox>
#include "ui_MainWindow.h"
#include "../../Widgets/TableButton/TableButton.h"
#include "../../Widgets/PartyLayoutWidget/PartyLayoutWidget.h"
#include "../AddPartyDialog/AddPartyDialog.h"
#include "../../Party.h"
#include "../../Database_Classes/PartyDMA.hpp"
#include "../../Database_Classes/TableDMA.hpp"
#include "../../Windows/EditPartyDialog/EditPartyDialog.h"
#include "../../Windows/SeatPartyDialog/SeatPartyDialog.h"

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
            TableButton* table = new TableButton(tableNum);
            newRow.push_back(table);
            ui->FloormapScrollAreaContents->addWidget(table, xIdx, yIdx);
            ++tableNum;
        }
        floormap.push_back(newRow);
    }

    partyDMArray = new PartyDMA();
    connect(partyDMArray, &PartyDMA::ok, this, &MainWindow::databasePartyLoadSuccess);
    partyDMArray->fileDownload("http://localhost:3000/api/party/1");

    tableDMArray = new TableDMA();
    connect(tableDMArray, &TableDMA::ok, this, &MainWindow::databaseTableLoadSuccess);
    tableDMArray->fileDownload("http://localhost:3000/api/table");
}

//Slot functions
void MainWindow::databasePartyLoadSuccess()
{
    for(auto partyToLoad : *(partyDMArray->listOfParties()))
    {
        Party* newParty = new Party(QString::fromStdString(partyToLoad->_name()), partyToLoad->_size(), partyToLoad->_id());
        addPartyToWaitlist(newParty);
    }

    disconnect(partyDMArray, &PartyDMA::ok, this, &MainWindow::databasePartyLoadSuccess);
}

void MainWindow::databaseTableLoadSuccess()
{
    int row = 0;
    int col = 0;

    for(auto tableToLoad : *(tableDMArray->listOfTables()))
    {
        if(row == floorMapHeight)
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
        if(col == floorMapWidth)
        {
            col = 0;
            ++row;
        }
    }
    disconnect(tableDMArray, &TableDMA::ok, this, &MainWindow::databaseTableLoadSuccess);
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

void MainWindow::on_addToWaitlistButton_clicked()
{
    QString newPartyName;
    int newPartySize;
    AddPartyDialog addPartyDialog(newPartyName, newPartySize, this);

    if(addPartyDialog.exec())
    {
        //lifeTimeNumOfParties is temp
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
    for(int xIdx = 0; xIdx < floorMapWidth; ++xIdx)
    {
        for(int yIdx = 0; yIdx < floorMapHeight; ++yIdx)
        {
            floormap.at(yIdx).at(xIdx)->deleteTable();
        }
    }
}

//PartyLayoutWidget Button Handler Slots
void MainWindow::editPartyButtonClicked(PartyLayoutWidget* partyLayoutWidgetToEdit)
{
    QString newPartyName = partyLayoutWidgetToEdit->getParty()->getName();
    int newPartySize = partyLayoutWidgetToEdit->getParty()->getSize();
    EditPartyDialog editPartyDialog(newPartyName, newPartySize, this);
    if(editPartyDialog.exec())
        partyLayoutWidgetToEdit->updateParty(newPartyName, newPartySize);
}

void MainWindow::sitPartyButtonClicked(PartyLayoutWidget* partyLayoutWidgetToEdit)
{
    int tableToSit;
    SeatParty seatPartyDialog(tableToSit, &floormap, this);
    if(seatPartyDialog.exec())
    {
        floormap.at((tableToSit - 1) / floorMapWidth)
                .at(((tableToSit - 1) - ((tableToSit - 1) / floorMapWidth) * floorMapWidth))
                ->sitParty(partyLayoutWidgetToEdit->getParty());
        removePartyFromWaitlist(partyLayoutWidgetToEdit, false);
    }
}

void MainWindow::deletePartyButtonClicked(PartyLayoutWidget* partyLayoutWidgetToEdit)
{
    removePartyFromWaitlist(partyLayoutWidgetToEdit, true);
}

//Helper functions
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
            delete partyLayoutWidgetToDelete->getParty();
        partyLayoutWidgetToDelete->setPartyPointerToNull();
        ui->WaitlistScrollAreaContents->removeItem(partyLayoutWidgetToDelete);
        delete partyLayoutWidgetToDelete;
    }
    else
    {
        QMessageBox::warning(this, "Error",  "The party you are trying to delete does not exist.");
        exit(1);
    }
}
