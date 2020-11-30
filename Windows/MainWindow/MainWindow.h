//Created by Ryan McKay
// The corresponding .ui to this window,
// i.e. MainWindow.ui, was also created by Ryan McKay

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QMainWindow>
#include <QPushButton>
#include <vector>
#include <list>
#include "../../Widgets/TableButton/TableButton.h"
#include "../../Widgets/PartyLayoutWidget/PartyLayoutWidget.h"
#include "../../Database_Classes/PartyDMA.hpp"
#include "../../Database_Classes/TableDMA.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    const static int FLOORMAP_WIDTH = 10;
    const static int FLOORMAP_HEIGHT = 10;

private slots:
    //Database Slots
    void databasePartyLoadSuccess();
    void databaseTableLoadSuccess();

    //Native ui components' slots
    void on_addToWaitlistButton_clicked();
    void on_actionDelete_All_Parties_On_Waitlist_triggered();
    void on_actionDelete_All_Tables_triggered();

    //PartyLayoutWidget Button Handlers
    void editPartyButtonClicked(PartyLayoutWidget* partyLayoutWidgetToEdit);
    void sitPartyButtonClicked(PartyLayoutWidget* partyLayoutWidgetToEdit);
    void deletePartyButtonClicked(PartyLayoutWidget* partyLayoutWidgetToEdit);

private:
    //Helper functions
    void deleteAllParties();
    void addPartyToWaitlist(Party* partyToAdd);
    void removePartyFromWaitlist(PartyLayoutWidget* partyLayoutWidgetToDelete, bool deleteParty);

    //Database loaders
    PartyDMA* partyDMArray = nullptr;
    TableDMA* tableDMArray = nullptr;

    std::vector<std::vector<TableButton*>> floormap;


    std::list<PartyLayoutWidget*> waitList;
    int numOfParties = 0;

    Ui::MainWindow *ui;

    //temp
    int lifeTimeNumOfParties = 100;
};
#endif // MAINWINDOW_H
