// Created by Matthew Coady

#ifndef SEATPARTY_H
#define SEATPARTY_H

#include <QDialog>
#include "../../TableStatusEnum/TableStatusEnum.h"
#include "../../Widgets/TableButton/TableButton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SeatParty; }
QT_END_NAMESPACE

class SeatParty : public QDialog
{
    Q_OBJECT

public:
    SeatParty(int& tableToSit, std::vector<std::vector<TableButton*>> *tables = nullptr, QWidget *parent = nullptr);
    ~SeatParty();

private slots:
    void on_confirmButton_clicked();
    void on_cancelButton_clicked();

private:
    int& _tableToSit;
    std::vector<std::vector<TableButton*>> *_tables;
    Ui::SeatParty *ui;

};
#endif // SEATPARTY_H
