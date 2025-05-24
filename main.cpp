#include "mainwindow.h"
#include <QApplication>
#include <QDateTime>

#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // QLineSeries *series = new QLineSeries();

    // series->append(QDateTime::fromString("2025-05-20 08:30", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 110);
    // series->append(QDateTime::fromString("2025-05-21 09:15", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 120);
    // series->append(QDateTime::fromString("2025-05-22 07:50", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 98);
    // series->append(QDateTime::fromString("2025-05-23 10:05", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 105);
    // series->append(QDateTime::fromString("2025-05-24 08:00", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 112);
    // series->append(QDateTime::fromString("2025-05-25 09:30", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 115);
    // series->append(QDateTime::fromString("2025-05-26 07:45", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 101);
    // series->append(QDateTime::fromString("2025-05-27 08:20", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 108);
    // series->append(QDateTime::fromString("2025-05-28 09:10", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 117);
    // series->append(QDateTime::fromString("2025-05-29 07:30", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 99);
    // series->append(QDateTime::fromString("2025-05-30 08:40", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 113);
    // series->append(QDateTime::fromString("2025-05-31 09:00", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 118);


    // QChart *chart = new QChart();
    // chart->addSeries(series);
    // chart->setTitle("Glucose Levels Over Time");

    // QDateTimeAxis *axisX = new QDateTimeAxis;
    // axisX->setFormat("MMM dd hh:mm");
    // axisX->setTitleText("Date & Time");
    // axisX->setTickCount(5);
    // chart->addAxis(axisX, Qt::AlignBottom);
    // series->attachAxis(axisX);

    // QValueAxis *axisY = new QValueAxis;
    // axisY->setLabelFormat("%i");
    // axisY->setTitleText("Glucose Level (mg/dL)");
    // axisY->setRange(80, 160); // adjust based on your data
    // chart->addAxis(axisY, Qt::AlignLeft);
    // series->attachAxis(axisY);

    // QChartView *chartView = new QChartView(chart);
    // chartView->setRenderHint(QPainter::Antialiasing);
    // chartView->show();
    // ui->yourLayout->addWidget(chartView); // Add to your main window layout

    QLineSeries *series = new QLineSeries();

    series->append(QDateTime::fromString("2025-05-20 08:30", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 110);
    series->append(QDateTime::fromString("2025-05-21 09:15", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 120);
    series->append(QDateTime::fromString("2025-05-22 07:50", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 98);
    series->append(QDateTime::fromString("2025-05-23 10:05", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 105);
    series->append(QDateTime::fromString("2025-05-24 08:00", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 112);
    series->append(QDateTime::fromString("2025-05-25 09:30", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 115);
    series->append(QDateTime::fromString("2025-05-26 07:45", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 101);
    series->append(QDateTime::fromString("2025-05-27 08:20", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 108);
    series->append(QDateTime::fromString("2025-05-28 09:10", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 117);
    series->append(QDateTime::fromString("2025-05-29 07:30", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 99);
    series->append(QDateTime::fromString("2025-05-30 08:40", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 113);
    series->append(QDateTime::fromString("2025-05-31 09:00", "yyyy-MM-dd HH:mm").toMSecsSinceEpoch(), 118);

    // Step 1: Compute Linear Regression
    QVector<qreal> x, y;
    for (const QPointF &point : series->points()) {
        x.append(point.x());
        y.append(point.y());
    }

    qreal xSum = std::accumulate(x.begin(), x.end(), 0.0);
    qreal ySum = std::accumulate(y.begin(), y.end(), 0.0);
    qreal xMean = xSum / x.size();
    qreal yMean = ySum / y.size();

    qreal numerator = 0, denominator = 0;
    for (int i = 0; i < x.size(); ++i) {
        numerator += (x[i] - xMean) * (y[i] - yMean);
        denominator += (x[i] - xMean) * (x[i] - xMean);
    }
    qreal slope = numerator / denominator;
    qreal intercept = yMean - slope * xMean;

    // Step 2: Create Line of Best Fit
    qreal xMin = *std::min_element(x.begin(), x.end());
    qreal xMax = *std::max_element(x.begin(), x.end());

    QLineSeries *bestFitSeries = new QLineSeries();
    bestFitSeries->setName("Best Fit Line");
    bestFitSeries->append(xMin, slope * xMin + intercept);
    bestFitSeries->append(xMax, slope * xMax + intercept);

    // Step 3: Build Chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(bestFitSeries);
    chart->setTitle("Glucose Levels Over Time (with Best Fit Line)");

    // X Axis
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MMM dd hh:mm");
    axisX->setTitleText("Date & Time");
    axisX->setTickCount(5);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    bestFitSeries->attachAxis(axisX);

    // Y Axis
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Glucose Level (mg/dL)");
    axisY->setRange(80, 160);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    bestFitSeries->attachAxis(axisY);

    // Chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->show();


    return a.exec();
}
