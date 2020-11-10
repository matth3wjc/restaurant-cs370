#include "AddPartyDialog.h"
#include "ui_addpartydialog.h"
#include <iostream>
#include "../../Party.h"

AddPartyDialog::AddPartyDialog(QWidget *parent, Party *&newParty)
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
    //input validation still required

    QString party_name = ui->input_1->toPlainText();
    //QString party_nbr = ui->input_2->toPlainText();
    bool flag;
    int party_nbr = (ui->input_2->toPlainText()).toInt(&flag);
    if(!flag)
    {
        ui->warning->setText("NaN");
        this->close();
    }

    if (party_name == NULL || party_nbr == NULL)
    {
        ui->warning->setText("You must fill out the required information before you submit.");
    }
    else
    {
        Party *&newParty = new Party(party_name, party_nbr);
        this->close();
    }
}
