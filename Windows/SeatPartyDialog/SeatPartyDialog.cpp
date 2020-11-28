// Created by Matthew Coady
// Also created the seatparty.ui file

#include "SeatPartyDialog.h"
#include "ui_SeatPartyDialog.h"
#include "../../TableStatusEnum/TableStatusEnum.h"
#include "../../Widgets/TableButton/TableButton.h"
#include <QMessageBox>

const int FLOORMAP_WIDTH = 10;

SeatParty::SeatParty(int& tableToSit, std::vector<std::vector<TableButton*>> *tables, QWidget *parent)
    : QDialog(parent)
    , _tableToSit(tableToSit)
    , _tables(tables)
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
    bool flag;
    bool selectedTableIsOpen = false;
    int table_nbr = (ui->input->toPlainText()).toInt(&flag);    //table_nbr must be subtracted by one for calculations

    int row = (table_nbr - 1) / FLOORMAP_WIDTH;
    int col = ((table_nbr - 1) - ((table_nbr - 1) / FLOORMAP_WIDTH) * FLOORMAP_WIDTH);
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
        _tableToSit = table_nbr;
        this->accept();
        this->close();
    }
}

void SeatParty::on_cancelButton_clicked()
{
    this->reject();
    this->close();
}
