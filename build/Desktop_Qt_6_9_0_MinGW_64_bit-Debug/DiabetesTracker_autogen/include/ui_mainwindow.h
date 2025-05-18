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
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *History;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *HistoryScrollArea;
    QWidget *HistoryContents;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QWidget *Statistics;
    QPushButton *StatsButton;
    QPushButton *AddButton;
    QMenuBar *menubar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(810, 642);
        actionHistory = new QAction(MainWindow);
        actionHistory->setObjectName("actionHistory");
        actionOpen_History = new QAction(MainWindow);
        actionOpen_History->setObjectName("actionOpen_History");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 0, 791, 601));
        History = new QWidget();
        History->setObjectName("History");
        verticalLayout_2 = new QVBoxLayout(History);
        verticalLayout_2->setObjectName("verticalLayout_2");
        HistoryScrollArea = new QScrollArea(History);
        HistoryScrollArea->setObjectName("HistoryScrollArea");
        HistoryScrollArea->setWidgetResizable(true);
        HistoryContents = new QWidget();
        HistoryContents->setObjectName("HistoryContents");
        HistoryContents->setGeometry(QRect(0, 0, 763, 540));
        verticalLayout = new QVBoxLayout(HistoryContents);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 264, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        HistoryScrollArea->setWidget(HistoryContents);

        verticalLayout_2->addWidget(HistoryScrollArea);

        tabWidget->addTab(History, QString());
        Statistics = new QWidget();
        Statistics->setObjectName("Statistics");
        StatsButton = new QPushButton(Statistics);
        StatsButton->setObjectName("StatsButton");
        StatsButton->setGeometry(QRect(260, 20, 211, 21));
        tabWidget->addTab(Statistics, QString());
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName("AddButton");
        AddButton->setGeometry(QRect(720, 580, 83, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 810, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_History);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionHistory->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
        actionOpen_History->setText(QCoreApplication::translate("MainWindow", "Open History", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(History), QCoreApplication::translate("MainWindow", "History", nullptr));
        StatsButton->setText(QCoreApplication::translate("MainWindow", "Generate Statistics", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Statistics), QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        AddButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
