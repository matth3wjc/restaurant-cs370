// Created by Matthew Coady
// Also created the seatparty.ui file

#include "SeatPartyDialog.h"
#include "ui_SeatPartyDialog.h"
#include "../../TableStatusEnum/TableStatusEnum.h"
#include "../../Widgets/TableButton/TableButton.h"
#include <QMessageBox>

SeatParty::SeatParty(QWidget *parent, std::vector<std::vector<TableButton*>> *tables)
    : QDialog(parent)
    , ui(new Ui::SeatParty)
{
    _tables = tables;
    ui->setupUi(this);
}

SeatParty::~SeatParty()
{
    delete ui;
}

void SeatParty::on_confirmButton_clicked()
{
    bool flag;
    bool selectedTableIsOpen = false;
    int table_nbr = (ui->input->toPlainText()).toInt(&flag) - 1;
    // this line below makes sense, we promise. Don't think about it too hard.
    int row = (table_nbr) / 10;
    int col = (table_nbr - (table_nbr / 10) * 10);
    if(_tables->at(row).at(col)->getTableStatus() == TableStatus::OPEN)
    {
        QMessageBox::warning(this, "Congratulations", "We found it!");
        selectedTableIsOpen = true;
    }

    if (table_nbr == NULL)
    {
        ui->warning->setText("!! You must fill out the required information before you submit.");
    }
    else if(!flag)
    {
        ui->warning->setText("!! You must enter a valid integer value (1-100) as the table number.");
        ui->input->clear();
    }
    else if(!selectedTableIsOpen)
    {
        ui->warning->setText("!! The table number you entered is not open or does not exist! Please try again.");
        ui->input->clear();
    }
    else
    {
        this->setResult(table_nbr);
        this->close();
    }
}

void SeatParty::on_cancelButton_clicked()
{
    this->reject();
    this->close();
}
