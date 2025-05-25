/********************************************************************************
** Form generated from reading UI file 'splineregressionchartwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLINEREGRESSIONCHARTWIDGET_H
#define UI_SPLINEREGRESSIONCHARTWIDGET_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SplineRegressionChartWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *chartLayout;
    QChartView *SplineRegChartView;
    QLabel *LabelStandardDeviation;

    void setupUi(QWidget *SplineRegressionChartWidget)
    {
        if (SplineRegressionChartWidget->objectName().isEmpty())
            SplineRegressionChartWidget->setObjectName("SplineRegressionChartWidget");
        SplineRegressionChartWidget->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(SplineRegressionChartWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        chartLayout = new QVBoxLayout();
        chartLayout->setObjectName("chartLayout");
        SplineRegChartView = new QChartView(SplineRegressionChartWidget);
        SplineRegChartView->setObjectName("SplineRegChartView");

        chartLayout->addWidget(SplineRegChartView);

        LabelStandardDeviation = new QLabel(SplineRegressionChartWidget);
        LabelStandardDeviation->setObjectName("LabelStandardDeviation");
        LabelStandardDeviation->setMaximumSize(QSize(16777215, 15));

        chartLayout->addWidget(LabelStandardDeviation);


        verticalLayout_2->addLayout(chartLayout);


        retranslateUi(SplineRegressionChartWidget);

        QMetaObject::connectSlotsByName(SplineRegressionChartWidget);
    } // setupUi

    void retranslateUi(QWidget *SplineRegressionChartWidget)
    {
        SplineRegressionChartWidget->setWindowTitle(QCoreApplication::translate("SplineRegressionChartWidget", "Form", nullptr));
        LabelStandardDeviation->setText(QCoreApplication::translate("SplineRegressionChartWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SplineRegressionChartWidget: public Ui_SplineRegressionChartWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLINEREGRESSIONCHARTWIDGET_H
