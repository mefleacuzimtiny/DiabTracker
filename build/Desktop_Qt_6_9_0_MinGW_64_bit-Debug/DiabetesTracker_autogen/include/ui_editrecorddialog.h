/********************************************************************************
** Form generated from reading UI file 'editrecorddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITRECORDDIALOG_H
#define UI_EDITRECORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_EditRecordDialog
{
public:
    QFormLayout *formLayout;
    QLabel *LabelDateTimeCreated;
    QLabel *LabelRecentMealTime;
    QLabel *LabelValue;
    QLineEdit *LineEditValue;
    QLabel *LabelDescription;
    QTextEdit *TextEditDescription;
    QDialogButtonBox *buttonBox;
    QDateTimeEdit *DateTimeEditRecentMeal;
    QLabel *LabelDateTimeCreatedDisplay;

    void setupUi(QDialog *EditRecordDialog)
    {
        if (EditRecordDialog->objectName().isEmpty())
            EditRecordDialog->setObjectName("EditRecordDialog");
        EditRecordDialog->resize(400, 300);
        formLayout = new QFormLayout(EditRecordDialog);
        formLayout->setObjectName("formLayout");
        LabelDateTimeCreated = new QLabel(EditRecordDialog);
        LabelDateTimeCreated->setObjectName("LabelDateTimeCreated");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, LabelDateTimeCreated);

        LabelRecentMealTime = new QLabel(EditRecordDialog);
        LabelRecentMealTime->setObjectName("LabelRecentMealTime");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, LabelRecentMealTime);

        LabelValue = new QLabel(EditRecordDialog);
        LabelValue->setObjectName("LabelValue");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, LabelValue);

        LineEditValue = new QLineEdit(EditRecordDialog);
        LineEditValue->setObjectName("LineEditValue");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, LineEditValue);

        LabelDescription = new QLabel(EditRecordDialog);
        LabelDescription->setObjectName("LabelDescription");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, LabelDescription);

        TextEditDescription = new QTextEdit(EditRecordDialog);
        TextEditDescription->setObjectName("TextEditDescription");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, TextEditDescription);

        buttonBox = new QDialogButtonBox(EditRecordDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        formLayout->setWidget(4, QFormLayout::ItemRole::SpanningRole, buttonBox);

        DateTimeEditRecentMeal = new QDateTimeEdit(EditRecordDialog);
        DateTimeEditRecentMeal->setObjectName("DateTimeEditRecentMeal");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, DateTimeEditRecentMeal);

        LabelDateTimeCreatedDisplay = new QLabel(EditRecordDialog);
        LabelDateTimeCreatedDisplay->setObjectName("LabelDateTimeCreatedDisplay");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, LabelDateTimeCreatedDisplay);


        retranslateUi(EditRecordDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditRecordDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditRecordDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditRecordDialog);
    } // setupUi

    void retranslateUi(QDialog *EditRecordDialog)
    {
        EditRecordDialog->setWindowTitle(QCoreApplication::translate("EditRecordDialog", "Dialog", nullptr));
        LabelDateTimeCreated->setText(QCoreApplication::translate("EditRecordDialog", "Created on", nullptr));
        LabelRecentMealTime->setText(QCoreApplication::translate("EditRecordDialog", "Recent Meal Time", nullptr));
        LabelValue->setText(QCoreApplication::translate("EditRecordDialog", "Value", nullptr));
        LabelDescription->setText(QCoreApplication::translate("EditRecordDialog", "Description", nullptr));
        LabelDateTimeCreatedDisplay->setText(QCoreApplication::translate("EditRecordDialog", "LabelDateTimeCreation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditRecordDialog: public Ui_EditRecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITRECORDDIALOG_H
