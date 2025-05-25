#ifndef SPLINEREGRESSIONCHARTWIDGET_H
#define SPLINEREGRESSIONCHARTWIDGET_H

#include "recorddisplayframe.h"

#include <QWidget>

#include <vector>

namespace Ui {
class SplineRegressionChartWidget;
}

class SplineRegressionChartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SplineRegressionChartWidget(const std::vector<RecordDisplayFrame*>& HistoryData, QWidget *parent = nullptr);
    ~SplineRegressionChartWidget();

private:
    Ui::SplineRegressionChartWidget *ui;
};

#endif // SPLINEREGRESSIONCHARTWIDGET_H
