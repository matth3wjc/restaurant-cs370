#ifndef ADDPARTYDIALOG_H
#define ADDPARTYDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class AddPartyDialog; }
QT_END_NAMESPACE

class AddPartyDialog : public QDialog
{
    Q_OBJECT

public:
    AddPartyDialog(QWidget *parent = nullptr);
    ~AddPartyDialog();

private slots:
    void on_confirmButton_clicked();

private:
    Ui::AddPartyDialog *ui;
};
#endif
