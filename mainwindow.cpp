#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recorddialog.h"
#include "editrecorddialog.h"
#include "recorddisplayframe.h"
#include "HistoryData.h"

#include <QLabel>
#include <QDateTime>
#include <QPushButton>
#include <QMessageBox>

#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>

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


struct BFL {

};

void MainWindow::on_GenStatsButton_clicked()
{
    if (HistoryData.size() == 0) {
        QMessageBox::critical(this, "Error", "There is no data to generate statistics!");
        return;
    }

    QGridLayout* Stats = getStatsLayout();

    QLineSeries *series = new QLineSeries();
    series->setName("Glucose Level");

    sortRecords();

    for (RecordDisplayFrame* recdisp: HistoryData) {
        series->append(recdisp->DateTimeCreation.toMSecsSinceEpoch(), recdisp->Reading);    // each call to series->append() adds a QPointF object
    }                                                                                       // to the QLineSeries. Read the code below to understand more

    // computing linear regression, basically, a whole bunch of math. Look at the equations in the report to get an idea
    // of what's happening
    QVector<double> x, y;
    for (const QPointF& point : series->points()) {
        x.append(point.x());
        y.append(point.y());
    }

    double xSum = std::accumulate(x.begin(), x.end(), 0.0);     // std::accumulate() basically sums up all the values of the vector, and the
    double ySum = std::accumulate(y.begin(), y.end(), 0.0);     // 0.0 tells it the starting value to add on top of
    double xMean = xSum / x.size();                             // I mean this part is pretty self-explanatory: it gets the mean
    double yMean = ySum / y.size();

    double numerator = 0, denominator = 0;
    for (int i = 0; i < x.size(); i++) {
        numerator += (x[i] - xMean) * (y[i] - yMean);
        denominator += (x[i] - xMean) * (x[i] - xMean);
    }
    double slope = numerator / denominator;
    double intercept = yMean - slope * xMean;

    // generating line of Best Fit
    double xMin = *std::min_element(x.begin(), x.end());
    double xMax = *std::max_element(x.begin(), x.end());

    QLineSeries *bestFitSeries = new QLineSeries();
    bestFitSeries->setName("Best Fit Line");
    bestFitSeries->append(xMin, slope * xMin + intercept);      // add a QPointF to the left, and calculate the y-value accordingly
    bestFitSeries->append(xMax, slope * xMax + intercept);      // Do the same for the right point... when it gets drawn, you get a straight line b/w 2 points

    // building chart
    QChart *chart = new QChart();
    chart->addSeries(series);               // cuz series holds the raw data (for the jagged plot)
    chart->addSeries(bestFitSeries);        // for the best-fit line
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
    if (!y.isEmpty()) {
        qreal yMin = *std::min_element(y.begin(), y.end());
        qreal yMax = *std::max_element(y.begin(), y.end());

        qreal padding = (yMax - yMin) * 0.1;    // 10% padding
        if (padding == 0) padding = 10;         // fallback if all values are the same

        axisY->setRange(yMin - padding, yMax + padding);
    }

    // Chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    Stats->addWidget(chartView, 0, 0);
}

