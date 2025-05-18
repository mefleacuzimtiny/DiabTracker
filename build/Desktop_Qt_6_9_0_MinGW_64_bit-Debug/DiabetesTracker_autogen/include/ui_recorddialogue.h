/********************************************************************************
** Form generated from reading UI file 'recorddialogue.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDDIALOGUE_H
#define UI_RECORDDIALOGUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_RecordDialogue
{
public:
    QDialogButtonBox *buttonBox;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QLabel *label_3;

    void setupUi(QDialog *RecordDialogue)
    {
        if (RecordDialogue->objectName().isEmpty())
            RecordDialogue->setObjectName("RecordDialogue");
        RecordDialogue->resize(400, 300);
        buttonBox = new QDialogButtonBox(RecordDialogue);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        dateTimeEdit = new QDateTimeEdit(RecordDialogue);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(160, 30, 191, 31));
        label = new QLabel(RecordDialogue);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 131, 31));
        label_2 = new QLabel(RecordDialogue);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 70, 131, 31));
        lineEdit = new QLineEdit(RecordDialogue);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(160, 70, 191, 31));
        textEdit = new QTextEdit(RecordDialogue);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(160, 110, 191, 121));
        label_3 = new QLabel(RecordDialogue);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 110, 131, 31));

        retranslateUi(RecordDialogue);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, RecordDialogue, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, RecordDialogue, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(RecordDialogue);
    } // setupUi

    void retranslateUi(QDialog *RecordDialogue)
    {
        RecordDialogue->setWindowTitle(QCoreApplication::translate("RecordDialogue", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RecordDialogue", "Time Since Eating", nullptr));
        label_2->setText(QCoreApplication::translate("RecordDialogue", "Value/Reading", nullptr));
        label_3->setText(QCoreApplication::translate("RecordDialogue", "Description", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordDialogue: public Ui_RecordDialogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDDIALOGUE_H
