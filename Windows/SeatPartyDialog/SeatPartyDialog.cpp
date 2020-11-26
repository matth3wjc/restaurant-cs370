// Created by Matthew Coady
// Also created the seatparty.ui file

#include "SeatPartyDialog.h"
#include "ui_SeatPartyDialog.h"
#include "../../TableStatusEnum.h"
#include "../../Widgets/TableButton/TableButton.h"

SeatParty::SeatParty(QWidget *parent, std::vector<std::vector<TableButton>> *tables)
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
    bool flag, selectedTableIsOpen = false;
    int table_nbr = (ui->input->toPlainText()).toInt(&flag);

    // this line below makes sense, we promise. Don't think about it too hard.
    if(_tables->at(table_nbr / 10).at(table_nbr - (table_nbr / 10)*10).getTableStatus() == TableStatus::OPEN)
    {
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
        this->result();
        this->close();
    }
}

void SeatParty::on_cancelButton_clicked()
{
    this->reject();
    this->close();
}
