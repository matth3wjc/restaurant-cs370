//Created by Ryan McKay

#include "PartyLayoutWidget.h"
#include "../../Windows/EditPartyDialog/EditPartyDialog.h"
#include <QString>
#include <QPushButton>

PartyLayoutWidget::PartyLayoutWidget(Party* inParty)
{
    party = inParty;

    nameLabel.setText("Name: " + party->getName());
    nameLabel.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&nameLabel, 0, 0);

    sizeLabel.setText("Size: " + QString::number(party->getSize(), 10));
    sizeLabel.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&sizeLabel, 0, 1);

    editButton.setText("Edit");
    editButton.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&editButton, 1, 0);
    connect(&editButton, &QPushButton::clicked, this, &PartyLayoutWidget::onEditButtonClicked);

    sitButton.setText("Sit");
    sitButton.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&sitButton, 1, 1);
    connect(&sitButton, &QPushButton::clicked, this, &PartyLayoutWidget::onSitButtonClicked);

    deleteButton.setText("Delete");
    deleteButton.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&deleteButton, 1, 2);
}


void PartyLayoutWidget::onEditButtonClicked()
{
    emit editButtonClicked(&party, this);
}

void PartyLayoutWidget::onSitButtonClicked()
{
    emit sitButtonClicked(this);
}

void PartyLayoutWidget::updateDisplay()
{
    nameLabel.setText("Name: " + party->getName());
    sizeLabel.setText("Size: " + QString::number(party->getSize(), 10));
}
