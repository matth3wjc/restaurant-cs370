#include "PartyLayoutWidget.h"
#include <QString>

PartyLayoutWidget::PartyLayoutWidget(QString inName, int inSize)
{
    nameLabel.setText("Name: " + inName);
    nameLabel.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&nameLabel, 0, 0);

    sizeLabel.setText("Size: " + QString::number(inSize, 10));
    sizeLabel.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&sizeLabel, 0, 1);

    editButton.setText("Edit");
    editButton.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&editButton, 1, 0);

    sitButton.setText("Sit");
    sitButton.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&sitButton, 1, 1);

    deleteButton.setText("Delete");
    deleteButton.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&deleteButton, 1, 2);
}
