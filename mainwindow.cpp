#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recorddialog.h"
#include "editrecorddialog.h"
#include "recorddisplayframe.h"
#include "HistoryData.h"
#include "Statistics.h"

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
    QLineSeries *series = new QLineSeries();
    series->setName("Glucose Level");

    for (RecordDisplayFrame* recdisp: HistoryData) {                                        // each call to series->append() adds a QPointF object
        series->append(recdisp->DateTimeCreation.toMSecsSinceEpoch(), recdisp->Reading);    // to the QLineSeries. Read the code below to understand more
    }

    if (series->points().isEmpty()) {
        QMessageBox::information(this, "No Data", "No records found in the selected date range.");
        return;
    }

    // computing linear regression, basically, a whole bunch of math. Look at the equations in the report to get an idea
    // of what's happening
    BFLData bfl(series);

    QLineSeries *bestFitSeries = new QLineSeries();
    bestFitSeries->setName("Best Fit Line");
    bestFitSeries->append(bfl.xMin, bfl.slope*bfl.xMin + bfl.intercept);    // add a QPointF to the left, and calculate the y-value accordingly
    bestFitSeries->append(bfl.xMax, bfl.slope*bfl.xMax + bfl.intercept);    // Do the same for the right point... when it gets drawn, you get a straight line b/w 2 points

    // building chart
    QChart *chart = new QChart();           // you can add multiple plots on the same chart using different QLineSeries
    chart->addSeries(series);               // for the raw data (the jagged blue line)
    chart->addSeries(bestFitSeries);        // for the best-fit line (the straight green line)
    chart->setTitle("Glucose Levels Over Time (with Best Fit Line)");

    // setting x axis
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MMM dd hh:mm");
    axisX->setTitleText("Date & Time");
    axisX->setTickCount(5);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    bestFitSeries->attachAxis(axisX);

    // setting y axis
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Glucose Level (mg/dL)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    bestFitSeries->attachAxis(axisY);

    // axisY->setRange(80, 160); making the y-axis scale dynamic to sizes
    double padding = (bfl.yMax - bfl.yMin) * 0.1;       // 10% padding
    if (padding == 0) {
        padding = 10;                     // fallback if all values are the same
    }

    axisY->setRange(bfl.yMin - padding, bfl.yMax + padding);

    QLabel *stddevLabel = new QLabel(QString("Standard Deviation: %1").arg(bfl.stddev, 0, 'f', 2));  // format to 2 decimal places
    Stats->addWidget(stddevLabel, 1, 0);  // Place it below the chart (row 1, column 0)

    // Chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    Stats->addWidget(chartView, 0, 0);

    ui->StatsScrollArea->widget()->adjustSize();

    Stats->setRowStretch(0, 1);
}

void MainWindow::genSplineRegression(QGridLayout* Stats)
{
    QSplineSeries *series = new QSplineSeries();
    series->setName("Glucose Level");

    for (RecordDisplayFrame* recdisp : HistoryData) {
        series->append(recdisp->DateTimeCreation.toMSecsSinceEpoch(), recdisp->Reading);
    }

    if (series->points().isEmpty()) {
        QMessageBox::information(this, "No Data", "No records found in the selected date range.");
        return;
    }

    BFLData bfl(series);

    QLineSeries *bestFitSeries = new QLineSeries();
    bestFitSeries->setName("Best Fit Line");
    bestFitSeries->append(bfl.xMin, bfl.slope * bfl.xMin + bfl.intercept);
    bestFitSeries->append(bfl.xMax, bfl.slope * bfl.xMax + bfl.intercept);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(bestFitSeries);
    chart->setTitle("Glucose Levels Over Time (Spline with Best Fit Line)");

    // X axis (DateTime)
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MMM dd hh:mm");
    axisX->setTitleText("Date & Time");
    axisX->setTickCount(5);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    bestFitSeries->attachAxis(axisX);

    // Y axis (Glucose level)
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Glucose Level (mg/dL)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    bestFitSeries->attachAxis(axisY);

    double padding = (bfl.yMax - bfl.yMin) * 0.1;
    if (padding == 0) padding = 10;
    axisY->setRange(bfl.yMin - padding, bfl.yMax + padding);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    Stats->addWidget(chartView, 2, 0);

    Stats->setRowStretch(2, 1);
}


void MainWindow::on_actionOpen_History_triggered() {
    // add popup asking for directory to text file containing records

    std::string filename = "RecordHistory.txt";
    // parse inputed text file based on directory and store data
    // for each item in the data, generate a RecordDisplayFrame widget and store its pointer in HistoryData

    QVBoxLayout* History = this->getHistoryLayout();

    loadRecords(History, filename);

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

        std::fstream fout("RecordHistory.txt", std::ios::app);
        if (fout.is_open()) {
            fout << recdisp->repr() << '\n';
            fout.close();
        }
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
    // genSplineRegression(Stats);
}

