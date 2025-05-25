/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHistory;
    QAction *actionOpen_History;
    QAction *actionSave_Data;
    QWidget *centralwidget;
    QPushButton *AddButton;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *History;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *HistoryScrollArea;
    QWidget *HistoryContents;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QWidget *Statistics;
    QVBoxLayout *verticalLayout_3;
    QPushButton *GenStatsButton;
    QScrollArea *StatsScrollArea;
    QWidget *StatsContents;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(808, 640);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setAnimated(true);
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        actionHistory = new QAction(MainWindow);
        actionHistory->setObjectName("actionHistory");
        actionOpen_History = new QAction(MainWindow);
        actionOpen_History->setObjectName("actionOpen_History");
        actionSave_Data = new QAction(MainWindow);
        actionSave_Data->setObjectName("actionSave_Data");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName("AddButton");
        AddButton->setGeometry(QRect(710, 520, 50, 50));
        AddButton->setMinimumSize(QSize(50, 50));
        AddButton->setAutoDefault(false);
        AddButton->setFlat(false);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        History = new QWidget();
        History->setObjectName("History");
        History->setStyleSheet(QString::fromUtf8("background-color: rgb(55, 72, 86);"));
        verticalLayout_2 = new QVBoxLayout(History);
        verticalLayout_2->setObjectName("verticalLayout_2");
        HistoryScrollArea = new QScrollArea(History);
        HistoryScrollArea->setObjectName("HistoryScrollArea");
        HistoryScrollArea->setStyleSheet(QString::fromUtf8(""));
        HistoryScrollArea->setWidgetResizable(true);
        HistoryContents = new QWidget();
        HistoryContents->setObjectName("HistoryContents");
        HistoryContents->setGeometry(QRect(0, 0, 758, 532));
        HistoryContents->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(HistoryContents);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 264, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        HistoryScrollArea->setWidget(HistoryContents);

        verticalLayout_2->addWidget(HistoryScrollArea);

        tabWidget->addTab(History, QString());
        Statistics = new QWidget();
        Statistics->setObjectName("Statistics");
        verticalLayout_3 = new QVBoxLayout(Statistics);
        verticalLayout_3->setObjectName("verticalLayout_3");
        GenStatsButton = new QPushButton(Statistics);
        GenStatsButton->setObjectName("GenStatsButton");

        verticalLayout_3->addWidget(GenStatsButton);

        StatsScrollArea = new QScrollArea(Statistics);
        StatsScrollArea->setObjectName("StatsScrollArea");
        StatsScrollArea->setMinimumSize(QSize(0, 496));
        StatsScrollArea->setFrameShape(QFrame::Shape::Box);
        StatsScrollArea->setFrameShadow(QFrame::Shadow::Raised);
        StatsScrollArea->setWidgetResizable(true);
        StatsContents = new QWidget();
        StatsContents->setObjectName("StatsContents");
        StatsContents->setGeometry(QRect(0, 0, 756, 494));
        gridLayout = new QGridLayout(StatsContents);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        StatsScrollArea->setWidget(StatsContents);

        verticalLayout_3->addWidget(StatsScrollArea);

        tabWidget->addTab(Statistics, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        tabWidget->raise();
        AddButton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 808, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_History);
        menuFile->addAction(actionSave_Data);

        retranslateUi(MainWindow);

        AddButton->setDefault(false);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionHistory->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
        actionOpen_History->setText(QCoreApplication::translate("MainWindow", "Open History", nullptr));
        actionSave_Data->setText(QCoreApplication::translate("MainWindow", "Save Data", nullptr));
        AddButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(History), QCoreApplication::translate("MainWindow", "History", nullptr));
        GenStatsButton->setText(QCoreApplication::translate("MainWindow", "Generate Statistics", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Statistics), QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
