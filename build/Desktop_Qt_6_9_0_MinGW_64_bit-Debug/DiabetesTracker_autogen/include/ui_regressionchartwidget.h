/********************************************************************************
** Form generated from reading UI file 'regressionchartwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGRESSIONCHARTWIDGET_H
#define UI_REGRESSIONCHARTWIDGET_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegressionChartWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *chartLayout;
    QChartView *LinRegChartView;
    QLabel *LabelStandardDeviation;

    void setupUi(QWidget *RegressionChartWidget)
    {
        if (RegressionChartWidget->objectName().isEmpty())
            RegressionChartWidget->setObjectName("RegressionChartWidget");
        RegressionChartWidget->resize(581, 349);
        verticalLayout_2 = new QVBoxLayout(RegressionChartWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        chartLayout = new QVBoxLayout();
        chartLayout->setObjectName("chartLayout");
        LinRegChartView = new QChartView(RegressionChartWidget);
        LinRegChartView->setObjectName("LinRegChartView");

        chartLayout->addWidget(LinRegChartView);

        LabelStandardDeviation = new QLabel(RegressionChartWidget);
        LabelStandardDeviation->setObjectName("LabelStandardDeviation");
        LabelStandardDeviation->setMaximumSize(QSize(16777215, 15));

        chartLayout->addWidget(LabelStandardDeviation);


        verticalLayout_2->addLayout(chartLayout);


        retranslateUi(RegressionChartWidget);

        QMetaObject::connectSlotsByName(RegressionChartWidget);
    } // setupUi

    void retranslateUi(QWidget *RegressionChartWidget)
    {
        RegressionChartWidget->setWindowTitle(QCoreApplication::translate("RegressionChartWidget", "Form", nullptr));
        LabelStandardDeviation->setText(QCoreApplication::translate("RegressionChartWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegressionChartWidget: public Ui_RegressionChartWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGRESSIONCHARTWIDGET_H
