/********************************************************************************
** Form generated from reading UI file 'recorddisplayframe.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDDISPLAYFRAME_H
#define UI_RECORDDISPLAYFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordDisplayFrame
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *LabelDescription;
    QLabel *LabelValue;
    QLabel *LabelTimeSinceMeal;
    QLabel *LabelValueDisplay;
    QLabel *LabelDescriptionDisplay;
    QLabel *LabelTimeSinceMealDisplay;
    QPushButton *ButtonEdit;
    QPushButton *ButtonDelete;

    void setupUi(QWidget *RecordDisplayFrame)
    {
        if (RecordDisplayFrame->objectName().isEmpty())
            RecordDisplayFrame->setObjectName("RecordDisplayFrame");
        RecordDisplayFrame->resize(741, 109);
        RecordDisplayFrame->setStyleSheet(QString::fromUtf8("background-color: #323339;\n"
"color: white;"));
        verticalLayout_2 = new QVBoxLayout(RecordDisplayFrame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        LabelDescription = new QLabel(RecordDisplayFrame);
        LabelDescription->setObjectName("LabelDescription");
        LabelDescription->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(LabelDescription, 1, 0, 1, 1);

        LabelValue = new QLabel(RecordDisplayFrame);
        LabelValue->setObjectName("LabelValue");
        LabelValue->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(LabelValue, 0, 0, 1, 1);

        LabelTimeSinceMeal = new QLabel(RecordDisplayFrame);
        LabelTimeSinceMeal->setObjectName("LabelTimeSinceMeal");
        LabelTimeSinceMeal->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(LabelTimeSinceMeal, 2, 0, 1, 1);

        LabelValueDisplay = new QLabel(RecordDisplayFrame);
        LabelValueDisplay->setObjectName("LabelValueDisplay");

        gridLayout->addWidget(LabelValueDisplay, 0, 1, 1, 1);

        LabelDescriptionDisplay = new QLabel(RecordDisplayFrame);
        LabelDescriptionDisplay->setObjectName("LabelDescriptionDisplay");

        gridLayout->addWidget(LabelDescriptionDisplay, 1, 1, 1, 1);

        LabelTimeSinceMealDisplay = new QLabel(RecordDisplayFrame);
        LabelTimeSinceMealDisplay->setObjectName("LabelTimeSinceMealDisplay");

        gridLayout->addWidget(LabelTimeSinceMealDisplay, 2, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        ButtonEdit = new QPushButton(RecordDisplayFrame);
        ButtonEdit->setObjectName("ButtonEdit");
        ButtonEdit->setMinimumSize(QSize(0, 75));
        ButtonEdit->setMaximumSize(QSize(75, 75));

        horizontalLayout->addWidget(ButtonEdit);

        ButtonDelete = new QPushButton(RecordDisplayFrame);
        ButtonDelete->setObjectName("ButtonDelete");
        ButtonDelete->setMinimumSize(QSize(0, 75));
        ButtonDelete->setMaximumSize(QSize(75, 75));

        horizontalLayout->addWidget(ButtonDelete);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(RecordDisplayFrame);

        QMetaObject::connectSlotsByName(RecordDisplayFrame);
    } // setupUi

    void retranslateUi(QWidget *RecordDisplayFrame)
    {
        RecordDisplayFrame->setWindowTitle(QCoreApplication::translate("RecordDisplayFrame", "Form", nullptr));
        LabelDescription->setText(QCoreApplication::translate("RecordDisplayFrame", "Description", nullptr));
        LabelValue->setText(QCoreApplication::translate("RecordDisplayFrame", "Value:", nullptr));
        LabelTimeSinceMeal->setText(QCoreApplication::translate("RecordDisplayFrame", "Time Since Meal", nullptr));
        LabelValueDisplay->setText(QCoreApplication::translate("RecordDisplayFrame", "TextLabel", nullptr));
        LabelDescriptionDisplay->setText(QCoreApplication::translate("RecordDisplayFrame", "TextLabel", nullptr));
        LabelTimeSinceMealDisplay->setText(QCoreApplication::translate("RecordDisplayFrame", "TextLabel", nullptr));
        ButtonEdit->setText(QCoreApplication::translate("RecordDisplayFrame", "Edit", nullptr));
        ButtonDelete->setText(QCoreApplication::translate("RecordDisplayFrame", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordDisplayFrame: public Ui_RecordDisplayFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDDISPLAYFRAME_H
