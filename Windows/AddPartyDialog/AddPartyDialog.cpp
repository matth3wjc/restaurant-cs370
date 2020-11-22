// Created by Matthew Coady
// Also created the addpartydialog.ui file

#include "AddPartyDialog.h"
#include "ui_AddPartyDialog.h"
#include <iostream>
#include "../../Party.h"

AddPartyDialog::AddPartyDialog(QWidget *parent, Party **party)
    : QDialog(parent)
    , ui(new Ui::AddPartyDialog)
{
    myParty = party;
    ui->setupUi(this);

    // set warning text to red
    QPalette palette = ui->warning->palette();
    palette.setColor(ui->warning->backgroundRole(), Qt::white);
    palette.setColor(ui->warning->foregroundRole(), Qt::red);
    ui->warning->setPalette(palette);
}

AddPartyDialog::~AddPartyDialog()
{
    delete ui;
}


void AddPartyDialog::on_confirmButton_clicked()
{
    bool flag, isOnlyLetters;
    int party_size = (ui->input_2->toPlainText()).toInt(&flag);
    QString party_name = ui->input_1->toPlainText();

    // test if the string contains only letters
    for (int i=0; i < party_name.length(); i++)
    {
        if ((party_name.at(i) >= 65 && party_name.at(i) <= 90) || (party_name.at(i) >= 97 && party_name.at(i) <= 122))
        {
            isOnlyLetters = true;
        }
        else
        {
            isOnlyLetters = false;
        }
    }

    if (party_name == NULL || party_size == NULL)
    {
        ui->warning->setText("!! You must fill out the required information before you submit.");
    }
    else if(!flag || party_size >= 100 || party_size < 0)
    {
        ui->warning->setText("!! You must enter a valid integer value (1-99) as the party size.");
        ui->input_2->clear();
    }
    else if(party_name.length() < 0 || party_name.length() >= 31 || !isOnlyLetters)
    {
        ui->warning->setText("!! You must enter a valid string (between 1-30 LETTERS) as the party name.");
        ui->input_1->clear();
    }
    else
    {
        Party *newParty = new Party(party_name, party_size);
        *myParty = newParty;
        this->accept();
        this->close();
    }
}

void AddPartyDialog::on_cancelButton_clicked()
{
    this->reject();
    this->close();
}
