/********************************************************************************
** Form generated from reading UI file 'addpartydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPARTYDIALOG_H
#define UI_ADDPARTYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddPartyDialog
{
public:
    QLabel *title;
    QPushButton *confirmButton;
    QLabel *prompt_1;
    QTextEdit *input_1;
    QLabel *prompt_2;
    QTextEdit *input_2;
    QLabel *warning;

    void setupUi(QDialog *AddPartyDialog)
    {
        if (AddPartyDialog->objectName().isEmpty())
            AddPartyDialog->setObjectName(QString::fromUtf8("AddPartyDialog"));
        AddPartyDialog->resize(438, 337);
        title = new QLabel(AddPartyDialog);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(10, 10, 291, 31));
        QFont font;
        font.setPointSize(12);
        title->setFont(font);
        confirmButton = new QPushButton(AddPartyDialog);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(310, 260, 80, 25));
        prompt_1 = new QLabel(AddPartyDialog);
        prompt_1->setObjectName(QString::fromUtf8("prompt_1"));
        prompt_1->setGeometry(QRect(70, 80, 161, 21));
        QFont font1;
        font1.setPointSize(10);
        prompt_1->setFont(font1);
        input_1 = new QTextEdit(AddPartyDialog);
        input_1->setObjectName(QString::fromUtf8("input_1"));
        input_1->setGeometry(QRect(250, 80, 141, 31));
        prompt_2 = new QLabel(AddPartyDialog);
        prompt_2->setObjectName(QString::fromUtf8("prompt_2"));
        prompt_2->setGeometry(QRect(70, 170, 131, 21));
        prompt_2->setFont(font1);
        input_2 = new QTextEdit(AddPartyDialog);
        input_2->setObjectName(QString::fromUtf8("input_2"));
        input_2->setGeometry(QRect(250, 170, 141, 31));
        warning = new QLabel(AddPartyDialog);
        warning->setObjectName(QString::fromUtf8("warning"));
        warning->setGeometry(QRect(20, 290, 401, 31));
        QFont font2;
        font2.setPointSize(9);
        warning->setFont(font2);

        retranslateUi(AddPartyDialog);

        QMetaObject::connectSlotsByName(AddPartyDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPartyDialog)
    {
        AddPartyDialog->setWindowTitle(QCoreApplication::translate("AddPartyDialog", "AddPartyDialog", nullptr));
        title->setText(QCoreApplication::translate("AddPartyDialog", "Add a new party to the waitlist:", nullptr));
        confirmButton->setText(QCoreApplication::translate("AddPartyDialog", "Confirm", nullptr));
        prompt_1->setText(QCoreApplication::translate("AddPartyDialog", "Enter name for party:", nullptr));
        prompt_2->setText(QCoreApplication::translate("AddPartyDialog", "Enter party size:", nullptr));
        warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddPartyDialog: public Ui_AddPartyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPARTYDIALOG_H
