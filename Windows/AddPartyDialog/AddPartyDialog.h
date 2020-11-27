// Created by Matthew Coady

#ifndef ADDPARTYDIALOG_H
#define ADDPARTYDIALOG_H

#include <QDialog>
#include "../../Party.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AddPartyDialog; }
QT_END_NAMESPACE

class AddPartyDialog : public QDialog
{
    Q_OBJECT

public:
    AddPartyDialog(QString& partyName, int& partySize, QWidget *parent = nullptr);
    ~AddPartyDialog();

private slots:
    void on_confirmButton_clicked();
    void on_cancelButton_clicked();

private:
    QString& myPartyName;
    int& myPartySize;
    Ui::AddPartyDialog *ui;
};
#endif
