//Created by Ryan McKay

#ifndef PARTYLAYOUTWIDGET_H
#define PARTYLAYOUTWIDGET_H

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "Party.h"

class PartyLayoutWidget : public QGridLayout
{
    Q_OBJECT

public:
    PartyLayoutWidget(Party* inParty);
    Party* getParty() { return party; };
private:
    Party* party;
    QLabel nameLabel;
    QLabel sizeLabel;
    QPushButton editButton;
    QPushButton sitButton;
    QPushButton deleteButton;
};

#endif
