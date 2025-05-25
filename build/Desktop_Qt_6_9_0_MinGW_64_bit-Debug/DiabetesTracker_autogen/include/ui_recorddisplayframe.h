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
#include <QtWidgets/QFrame>
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
    QWidget *contentContainer_2;
    QHBoxLayout *contentContainer;
    QFrame *LabelsGrid;
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
        RecordDisplayFrame->resize(801, 164);
        RecordDisplayFrame->setStyleSheet(QString::fromUtf8("background-color: #323339;\n"
"color: white;\n"
""));
        verticalLayout_2 = new QVBoxLayout(RecordDisplayFrame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        contentContainer_2 = new QWidget(RecordDisplayFrame);
        contentContainer_2->setObjectName("contentContainer_2");
        contentContainer_2->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-radius: 25px;"));
        contentContainer = new QHBoxLayout(contentContainer_2);
        contentContainer->setObjectName("contentContainer");
        LabelsGrid = new QFrame(contentContainer_2);
        LabelsGrid->setObjectName("LabelsGrid");
        LabelsGrid->setStyleSheet(QString::fromUtf8("border:none;"));
        gridLayout = new QGridLayout(LabelsGrid);
        gridLayout->setObjectName("gridLayout");
        LabelDescription = new QLabel(LabelsGrid);
        LabelDescription->setObjectName("LabelDescription");
        LabelDescription->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(LabelDescription, 1, 0, 1, 1);

        LabelValue = new QLabel(LabelsGrid);
        LabelValue->setObjectName("LabelValue");
        LabelValue->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(LabelValue, 0, 0, 1, 1);

        LabelTimeSinceMeal = new QLabel(LabelsGrid);
        LabelTimeSinceMeal->setObjectName("LabelTimeSinceMeal");
        LabelTimeSinceMeal->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(LabelTimeSinceMeal, 2, 0, 1, 1);

        LabelValueDisplay = new QLabel(LabelsGrid);
        LabelValueDisplay->setObjectName("LabelValueDisplay");

        gridLayout->addWidget(LabelValueDisplay, 0, 1, 1, 1);

        LabelDescriptionDisplay = new QLabel(LabelsGrid);
        LabelDescriptionDisplay->setObjectName("LabelDescriptionDisplay");

        gridLayout->addWidget(LabelDescriptionDisplay, 1, 1, 1, 1);

        LabelTimeSinceMealDisplay = new QLabel(LabelsGrid);
        LabelTimeSinceMealDisplay->setObjectName("LabelTimeSinceMealDisplay");

        gridLayout->addWidget(LabelTimeSinceMealDisplay, 2, 1, 1, 1);


        contentContainer->addWidget(LabelsGrid);

        ButtonEdit = new QPushButton(contentContainer_2);
        ButtonEdit->setObjectName("ButtonEdit");
        ButtonEdit->setMinimumSize(QSize(60, 60));
        ButtonEdit->setMaximumSize(QSize(60, 60));

        contentContainer->addWidget(ButtonEdit);

        ButtonDelete = new QPushButton(contentContainer_2);
        ButtonDelete->setObjectName("ButtonDelete");
        ButtonDelete->setMinimumSize(QSize(60, 60));
        ButtonDelete->setMaximumSize(QSize(60, 60));

        contentContainer->addWidget(ButtonDelete);


        verticalLayout_2->addWidget(contentContainer_2);


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
