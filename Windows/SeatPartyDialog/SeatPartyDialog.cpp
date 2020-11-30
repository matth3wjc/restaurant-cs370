// Created by Matthew Coady
// Also created the seatparty.ui file

#include "SeatPartyDialog.h"
#include "ui_SeatPartyDialog.h"
#include "../../TableStatusEnum/TableStatusEnum.h"
#include "../../Widgets/TableButton/TableButton.h"
#include "../../CalcRowAndColGlobalFunctions/CalcRowAndColGlobalFunctions.h"
#include <QMessageBox>

SeatParty::SeatParty(int& tableToSit, std::vector<std::vector<TableButton*>> *tables, QWidget *parent)
    : QDialog(parent)
    , _tableToSit(tableToSit)
    , _tables(tables)
    , ui(new Ui::SeatParty)
{
    ui->setupUi(this);

    // set warning text to red
    QPalette palette = ui->warning->palette();
    palette.setColor(ui->warning->backgroundRole(), Qt::white);
    palette.setColor(ui->warning->foregroundRole(), Qt::red);
    ui->warning->setPalette(palette);
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

    if (table_nbr == NULL)
    {
        ui->warning->setText("!! You must fill out the required information before you submit.");
        return;
    }
    else if(!flag)
    {
        ui->warning->setText("!! You must enter a valid integer value (1-100) as the table number.");
        ui->input->clear();
        return;
    }

    int row = calcRowFromTableNum(table_nbr);
    int col = calcColFromTableNum(table_nbr);
    if(_tables->at(row).at(col)->getTableStatus() == TableStatus::OPEN)
    {
        selectedTableIsOpen = true;
    }


    if(!selectedTableIsOpen)
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
