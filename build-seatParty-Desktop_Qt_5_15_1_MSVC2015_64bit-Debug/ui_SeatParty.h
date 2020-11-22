/********************************************************************************
** Form generated from reading UI file 'SeatParty.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEATPARTY_H
#define UI_SEATPARTY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SeatParty
{
public:
    QLabel *title;
    QLabel *prompt;
    QTextEdit *input;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QLabel *warning;

    void setupUi(QDialog *SeatParty)
    {
        if (SeatParty->objectName().isEmpty())
            SeatParty->setObjectName(QString::fromUtf8("SeatParty"));
        SeatParty->resize(590, 210);
        title = new QLabel(SeatParty);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(20, 10, 431, 31));
        QFont font;
        font.setPointSize(12);
        title->setFont(font);
        prompt = new QLabel(SeatParty);
        prompt->setObjectName(QString::fromUtf8("prompt"));
        prompt->setGeometry(QRect(70, 80, 161, 21));
        QFont font1;
        font1.setPointSize(10);
        prompt->setFont(font1);
        input = new QTextEdit(SeatParty);
        input->setObjectName(QString::fromUtf8("input"));
        input->setGeometry(QRect(350, 80, 201, 31));
        confirmButton = new QPushButton(SeatParty);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(350, 120, 80, 25));
        cancelButton = new QPushButton(SeatParty);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(470, 120, 80, 25));
        warning = new QLabel(SeatParty);
        warning->setObjectName(QString::fromUtf8("warning"));
        warning->setGeometry(QRect(20, 160, 551, 31));
        QFont font2;
        font2.setPointSize(9);
        warning->setFont(font2);
        warning->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(SeatParty);

        QMetaObject::connectSlotsByName(SeatParty);
    } // setupUi

    void retranslateUi(QDialog *SeatParty)
    {
        SeatParty->setWindowTitle(QCoreApplication::translate("SeatParty", "SeatParty", nullptr));
        title->setText(QCoreApplication::translate("SeatParty", "Seat selected party from the waitlist to a table:", nullptr));
        prompt->setText(QCoreApplication::translate("SeatParty", "Enter table number:", nullptr));
        confirmButton->setText(QCoreApplication::translate("SeatParty", "Confirm", nullptr));
        cancelButton->setText(QCoreApplication::translate("SeatParty", "Cancel", nullptr));
        warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SeatParty: public Ui_SeatParty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEATPARTY_H
