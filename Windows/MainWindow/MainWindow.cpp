//Created by Ryan McKay

#include "MainWindow.h"
#include "../../TableStatusEnum/TableStatusEnum.h"
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

    //thisMainWindow = this;

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

    partyDMArray = new PartyDMA();
    connect(partyDMArray, &PartyDMA::ok, this, &MainWindow::databasePartySuccess);
    partyDMArray->fileDownload("http://localhost:3000/api/party/1");

    tableDMArray = new TableDMA();
    connect(tableDMArray, &TableDMA::ok, this, &MainWindow::databaseTableSuccess);
    tableDMArray->fileDownload("http://localhost:3000/api/table");


}

//Slot functions
void MainWindow::databasePartySuccess()
{
    QMessageBox::warning(this, "Tester", "We are at party slot");
    for(auto partyToLoad : *(partyDMArray->listOfParties()))
    {
        QString pName = QString::fromStdString(partyToLoad->_name());
        QMessageBox::warning(this, "Tester",  "Name of party: " + pName);
        Party* newParty = new Party(QString::fromStdString(partyToLoad->_name()), partyToLoad->_size(), partyToLoad->_id());
        addPartyToWaitlist(newParty);
    }

    disconnect(partyDMArray, &PartyDMA::ok, this, &MainWindow::databasePartySuccess);
}

void MainWindow::databaseTableSuccess()
{
    QMessageBox::warning(this, "Tester", "We are at table slot");
    disconnect(tableDMArray, &TableDMA::ok, this, &MainWindow::databaseTableSuccess);
}

MainWindow::~MainWindow()
{
    //Not yet created
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
    while(!waitList.empty())
    {
        PartyLayoutWidget* partyButtonToDelete = waitList.front();
        waitList.pop_front();
        ui->WaitlistScrollAreaContents->removeItem(partyButtonToDelete);
        delete partyButtonToDelete;
    }
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
        //sit party
        floormap.at((tableToSit - 1) / floorMapWidth).at(((tableToSit - 1) - ((tableToSit - 1) / floorMapWidth) * floorMapWidth))->sitParty(partyLayoutWidgetToEdit->getParty());
        removePartyFromWaitlist(partyLayoutWidgetToEdit);
    }
}

void MainWindow::addPartyToWaitlist(Party* partyToAdd)
{
    PartyLayoutWidget* newPartyLayoutWidget = new PartyLayoutWidget(partyToAdd);
    waitList.push_back(newPartyLayoutWidget);
    ui->WaitlistScrollAreaContents->addLayout(newPartyLayoutWidget);

    connect(newPartyLayoutWidget, &PartyLayoutWidget::editButtonClicked, this, &MainWindow::editPartyButtonClicked);
    connect(newPartyLayoutWidget, &PartyLayoutWidget::sitButtonClicked, this, &MainWindow::sitPartyButtonClicked);
}

void MainWindow::removePartyFromWaitlist(PartyLayoutWidget* partyLayoutWidgetToDelete)
{
    auto partyIter = waitList.begin();
    bool partyToBeDeletedFound = false;
    while(!partyToBeDeletedFound && partyIter != waitList.end())
    {
        if((*partyIter)->getParty()->getID() == partyLayoutWidgetToDelete->getParty()->getID())
        {
            waitList.erase(partyIter);
            partyToBeDeletedFound = true;
        }
        else
            ++partyIter;
    }
    if(partyToBeDeletedFound)
    {
        partyLayoutWidgetToDelete->unlinkPartyPointer();
        ui->WaitlistScrollAreaContents->removeItem(partyLayoutWidgetToDelete);
        delete partyLayoutWidgetToDelete;
    }
    else
    {
        QMessageBox::warning(this, "Error",  "The party you are trying to delete does not exist.");
        exit(1);
    }
}
