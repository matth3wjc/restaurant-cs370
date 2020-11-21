// Created by Matthew Coady
// Also created the seatparty.ui file

#include "SeatPartyDialog.h"
#include "ui_SeatPartyDialog.h"

SeatParty::SeatParty(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SeatParty)
{
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

    for (int number : table_nbrs)
    {
        if(table_nbr == number)
        {
            selectedTableIsOpen = true;
        }
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
        // return table_nbr
        this->accept();
        this->close();
    }
}

void SeatParty::on_cancelButton_clicked()
{
    this->reject();
    this->close();
}
