#ifndef REGRESSIONCHARTWIDGET_H
#define REGRESSIONCHARTWIDGET_H

#include "recorddisplayframe.h"

#include <QWidget>

#include <vector>

namespace Ui {
class RegressionChartWidget;
}

class RegressionChartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegressionChartWidget(const std::vector<RecordDisplayFrame*>& HistoryData, QWidget *parent = nullptr);
    ~RegressionChartWidget();

private:
    Ui::RegressionChartWidget *ui;
};

#endif // REGRESSIONCHARTWIDGET_H
