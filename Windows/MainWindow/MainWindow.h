//Created by Ryan McKay
// The corresponding .ui to this window,
// i.e. MainWindow.ui, was also created by Ryan McKay

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <vector>
#include "..\..\Widgets\TableButton\TableButton.h"
#include "..\..\Widgets\PartyLayoutWidget\PartyLayoutWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addToWaitlistButton_clicked();
    void on_actionDelete_All_Parties_On_Waitlist_triggered();

private:
    QPushButton button;
    Ui::MainWindow *ui;
    std::vector<std::vector<TableButton*>> floormap;
    std::vector<PartyLayoutWidget*> waitList;
    int numOfParties = 0;
    int floorMapWidth = 5;
    int floorMapHeight = 5;
};
#endif // MAINWINDOW_H
