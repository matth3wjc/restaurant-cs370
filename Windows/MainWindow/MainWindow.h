//Created by Ryan McKay
// The corresponding .ui to this window,
// i.e. MainWindow.ui, was also created by Ryan McKay

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <vector>
#include <list>
#include "../../Widgets/TableButton/TableButton.h"
#include "../../Widgets/PartyLayoutWidget/PartyLayoutWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    //static MainWindow* getMainWindow() { return thisMainWindow; };
    ~MainWindow();

private slots:
    void on_addToWaitlistButton_clicked();

    void on_actionDelete_All_Parties_On_Waitlist_triggered();
    void on_actionDelete_All_Tables_triggered();

    //PartyLayoutWidget Button Handlers
    void editPartyButtonClicked(PartyLayoutWidget* partyLayoutWidgetToEdit);
    void sitPartyButtonClicked(PartyLayoutWidget* partyLayoutWidgetToEdit);

private:
    //static MainWindow* thisMainWindow;
    QPushButton button;
    Ui::MainWindow *ui;
    std::vector<std::vector<TableButton*>> floormap;
    std::list<PartyLayoutWidget*> waitList;
    int numOfParties = 0;
    int floorMapWidth = 10;
    int floorMapHeight = 10;
};
#endif // MAINWINDOW_H
