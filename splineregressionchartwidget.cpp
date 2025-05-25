#include "splineregressionchartwidget.h"
#include "ui_splineregressionchartwidget.h"
#include "Statistics.h"
#include "recorddisplayframe.h"

#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QSplineSeries>

SplineRegressionChartWidget::SplineRegressionChartWidget(const std::vector<RecordDisplayFrame*>& data, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SplineRegressionChartWidget)
{
    ui->setupUi(this);

    QSplineSeries* series = new QSplineSeries();
    series->setName("Glucose Level");

    for (RecordDisplayFrame* recdisp : data) {                                              // each call to series->append() adds a QPointF object
        series->append(recdisp->DateTimeCreation.toMSecsSinceEpoch(), recdisp->Reading);    // to the QLineSeries. Read the code below to understand more
    }

    if (series->points().isEmpty()) {
        ui->chartLayout->addWidget(new QLabel("No data to display."));
        return;
    }

    // computing linear regression, basically, a whole bunch of math. Look at the equations in the report to get an idea
    // of what's happening
    BFLData bfl(series);

    QLineSeries* bestFitSeries = new QLineSeries();
    bestFitSeries->setName("Best Fit Line");
    bestFitSeries->append(bfl.xMin, bfl.slope * bfl.xMin + bfl.intercept);
    bestFitSeries->append(bfl.xMax, bfl.slope * bfl.xMax + bfl.intercept);

    // create the chart diagram itself
    QChart* chart = new QChart();           // you can add multiple plots on the same chart using different QLineSeries
    chart->addSeries(series);               // for the raw data (the jagged blue line)
    chart->addSeries(bestFitSeries);        // for the best-fit line (the straight green line)
    chart->setTitle("Glucose Levels Over Time (with Best Fit Line)");

    //setting x axis
    QDateTimeAxis* axisX = new QDateTimeAxis;
    axisX->setFormat("MMM dd hh:mm");
    axisX->setTitleText("Date & Time");
    axisX->setTickCount(5);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    bestFitSeries->attachAxis(axisX);

    //setting y axis
    QValueAxis* axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Glucose Level (mg/dL)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    bestFitSeries->attachAxis(axisY);

    // axisY->setRange(80, 160); making the y-axis scale dynamic to sizes
    double padding = (bfl.yMax - bfl.yMin) * 0.1;       // 10% padding
    if (padding == 0) {
        padding = 10;   // fallback if all values are the same
    }
    axisY->setRange(bfl.yMin - padding, bfl.yMax + padding);

    ui->SplineRegChartView->setChart(chart);
    ui->SplineRegChartView->setRenderHint(QPainter::Antialiasing);
    ui->LabelStandardDeviation->setText(QString("Standard Deviation: %1").arg(bfl.stddev, 0, 'f', 2));
    ui->SplineRegChartView->setMinimumHeight(200);
}

SplineRegressionChartWidget::~SplineRegressionChartWidget()
{
    delete ui;
}
