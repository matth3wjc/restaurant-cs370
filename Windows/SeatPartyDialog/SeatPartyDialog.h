// Created by Matthew Coady

#ifndef SEATPARTY_H
#define SEATPARTY_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class SeatParty; }
QT_END_NAMESPACE

class SeatParty : public QDialog
{
    Q_OBJECT

public:
    SeatParty(QWidget *parent = nullptr);
    ~SeatParty();

private slots:
    void on_confirmButton_clicked();
    void on_cancelButton_clicked();

private:
    std::vector<int> table_nbrs;
    Ui::SeatParty *ui;
};
#endif // SEATPARTY_H
