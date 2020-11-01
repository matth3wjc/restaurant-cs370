#ifndef PARTYLAYOUTWIDGET_H
#define PARTYLAYOUTWIDGET_H

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

class PartyLayoutWidget : public QGridLayout
{
    Q_OBJECT

public:
    PartyLayoutWidget(QString inName, int inSize);
private:
    QLabel nameLabel;
    QLabel sizeLabel;
    QPushButton editButton;
    QPushButton sitButton;
    QPushButton deleteButton;
};

#endif
