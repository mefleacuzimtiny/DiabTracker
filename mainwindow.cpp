#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recorddialog.h"
#include "editrecorddialog.h"
#include "recorddisplayframe.h"
#include "HistoryData.h"
#include "Statistics.h"
#include "regressionchartwidget.h"
#include "splineregressionchartwidget.h"

#include <QLabel>
#include <QDateTime>
#include <QPushButton>
#include <QMessageBox>

#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QSplineSeries>

#include <array>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);

    ui->AddButton->raise();

    int margin = 50;
    int btnWidth = ui->AddButton->width();
    int btnHeight = ui->AddButton->height();
    ui->AddButton->move(
        ui->centralwidget->width() - btnWidth - margin,
        ui->centralwidget->height() - btnHeight - margin
        );

    ui->AddButton->setStyleSheet(R"(
        QPushButton {
            color: white;
            border: 2px solid #d6b5d2;
            border-radius: 25px;  /* Half of width/height to make it round */
        }
        QPushButton:hover {
            background: qlineargradient(
                x1:0, y1:0, x2:0, y2:1,
                stop:0 #fddce3,   /* lighter orange */
                stop:1 #f4b3bb    /* deeper orange */
            );
            color: #d6b5d2;
            background-color: #fddce3;
        }
        QPushButton:pressed {
            background-color: #f4b3bb;
        }
    )");

    ui->AddButton->setIcon(QIcon(":/icons/AddButton.svg"));     // looks inside the resources.qrc file we made to search for the svg
    ui->AddButton->setIconSize(QSize(45, 45));  // Adjust size
    ui->AddButton->setText("");  // No text
}

MainWindow::~MainWindow() {
    delete ui;
}

QVBoxLayout* MainWindow::getHistoryLayout() {
    return qobject_cast<QVBoxLayout*>(ui->HistoryContents->layout());
}

QGridLayout *MainWindow::getStatsLayout()
{
    return qobject_cast<QGridLayout*>(ui->StatsContents->layout());
}

void MainWindow::genRegression(QGridLayout* Stats)
{
    RegressionChartWidget* regchart = new RegressionChartWidget(HistoryData);
    Stats->addWidget(regchart, 0, 0);   // Place it at (row 0, column 0)

    ui->StatsScrollArea->widget()->adjustSize();

    Stats->setRowStretch(0, 1);
}

void MainWindow::genSplineRegression(QGridLayout* Stats)
{
    SplineRegressionChartWidget* splinechart = new SplineRegressionChartWidget(HistoryData);
    Stats->addWidget(splinechart, 1, 0);   // Place it at (row 0, column 0)

    ui->StatsScrollArea->widget()->adjustSize();

    Stats->setRowStretch(0, 1);
}


void MainWindow::on_actionOpen_History_triggered() {
    // add popup asking for directory to text file containing records

    filename = "RecordHistory.csv";
    // parse inputed text file based on directory and store data
    // for each item in the data, generate a RecordDisplayFrame widget and store its pointer in HistoryData

    QVBoxLayout* History = this->getHistoryLayout();

    loadRecords(History);

    /* PARSING PSEUDOCODE:
    for each character in file:
        is it a quote?
            toggle insideQuotes
        no? is it a comma?
            is it inside quotes?
                add the character to the field
            no?
                we haven't reached maximum fields (i.e 4 fields)?
                    add field to currentRecord
                    field string becomes empty
        no? is it a newline?
            is it inside quotes?
                add it to the field
            no?
                add field to currentRecord
                add currentRecord to record table

                reset state
        no?
            add the character to the field

    last record will be an empty string if the file doesn't end with a newline so this is to safeguard from that
    is there is a remaining field or field index is 3?
        add field to currentRecord
        add currentRecord to record table
    */
    dumpRecords();
}

void MainWindow::on_actionSave_Data_triggered()
{
    // filename = "RecordHistory.csv";
    if (filename == "") {
        //Dialogue to enter filename
    }
    writeRecordsToFile();
}

void MainWindow::on_AddButton_clicked() {

    QVBoxLayout* History = this->getHistoryLayout();
    RecordDisplayFrame* recdisp = new RecordDisplayFrame();

    RecordDialog recordInputs(this);
    recordInputs.setDateTimeEdit(QDateTime::currentDateTime());

    bool dialogIsAccepted = recordInputs.exec() == QDialog::Accepted;
    if (dialogIsAccepted) {
        int Reading = recordInputs.getValue().toInt();
        if (Reading <= 0) {
            QMessageBox::critical(this, "Error", "Cannot have an empty reading!");
            qDebug() << "Cannot have an empty Reading" << "\n";
            return;
        }

        recdisp->Reading = Reading;
        recdisp->RecentMealDateTime = recordInputs.getDateTime();
        recdisp->Description = recordInputs.getDescription();
        recdisp->DateTimeCreation = QDateTime::currentDateTime();

        recdisp->updateValues();
        History->insertWidget(0, recdisp);

        addRecord(recdisp);
    }
    recordInputs.deleteLater();
}

void MainWindow::on_GenStatsButton_clicked()
{
    if (HistoryData.size() == 0) {
        QMessageBox::critical(this, "Error", "There is no data to generate statistics!");
        return;
    }
    sortRecords();

    QGridLayout* Stats = getStatsLayout();

    genRegression(Stats);
    genSplineRegression(Stats);
}

