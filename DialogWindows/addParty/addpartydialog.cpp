#include "addpartydialog.h"
#include "ui_addpartydialog.h"
#include <iostream>

AddPartyDialog::AddPartyDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPartyDialog)
{
    ui->setupUi(this);
}

AddPartyDialog::~AddPartyDialog()
{
    delete ui;
}


void AddPartyDialog::on_confirmButton_clicked()
{
    QString party_name = ui->input_1->toPlainText();
    QString party_nbr = ui->input_2->toPlainText();

    if (party_name == NULL || party_nbr == NULL)
    {
        ui->warning->setText("You must fill out the required information before you submit.");
    }
    else
    {
        //submit information to DB
        this->close();
    }
}
