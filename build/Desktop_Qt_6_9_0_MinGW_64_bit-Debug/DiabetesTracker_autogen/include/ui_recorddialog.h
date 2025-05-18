/********************************************************************************
** Form generated from reading UI file 'recorddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDDIALOG_H
#define UI_RECORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_RecordDialog
{
public:
    QFormLayout *formLayout;
    QLabel *LabelVal;
    QLineEdit *LineEditValue;
    QLabel *LabelTime;
    QTimeEdit *LineEditEatingTime;
    QLabel *LabelDesc;
    QTextEdit *TextEditDesc;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RecordDialog)
    {
        if (RecordDialog->objectName().isEmpty())
            RecordDialog->setObjectName("RecordDialog");
        RecordDialog->resize(400, 300);
        formLayout = new QFormLayout(RecordDialog);
        formLayout->setObjectName("formLayout");
        LabelVal = new QLabel(RecordDialog);
        LabelVal->setObjectName("LabelVal");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, LabelVal);

        LineEditValue = new QLineEdit(RecordDialog);
        LineEditValue->setObjectName("LineEditValue");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, LineEditValue);

        LabelTime = new QLabel(RecordDialog);
        LabelTime->setObjectName("LabelTime");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, LabelTime);

        LineEditEatingTime = new QTimeEdit(RecordDialog);
        LineEditEatingTime->setObjectName("LineEditEatingTime");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, LineEditEatingTime);

        LabelDesc = new QLabel(RecordDialog);
        LabelDesc->setObjectName("LabelDesc");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, LabelDesc);

        TextEditDesc = new QTextEdit(RecordDialog);
        TextEditDesc->setObjectName("TextEditDesc");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, TextEditDesc);

        buttonBox = new QDialogButtonBox(RecordDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        formLayout->setWidget(3, QFormLayout::ItemRole::SpanningRole, buttonBox);


        retranslateUi(RecordDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, RecordDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, RecordDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(RecordDialog);
    } // setupUi

    void retranslateUi(QDialog *RecordDialog)
    {
        RecordDialog->setWindowTitle(QCoreApplication::translate("RecordDialog", "Dialog", nullptr));
        LabelVal->setText(QCoreApplication::translate("RecordDialog", "Value", nullptr));
        LabelTime->setText(QCoreApplication::translate("RecordDialog", "Last Meal time", nullptr));
        LineEditEatingTime->setSpecialValueText(QString());
        LabelDesc->setText(QCoreApplication::translate("RecordDialog", "Description", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordDialog: public Ui_RecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDDIALOG_H
