// this file is for generating the charts and stuff
#include "Statistics.h"

#include <QLineSeries>

BFLData::BFLData(QLineSeries* series) {
    // computing linear regression. Basically, a whole bunch of math. Look at the equations in the report to get an idea
    // of what's happening
    QVector<double> x, y;
    for (const QPointF& point : series->points()) {
        x.append(point.x());
        y.append(point.y());
    }

    xSum = std::accumulate(x.begin(), x.end(), 0.0);     // std::accumulate() basically sums up all the values of the vector, and the
    ySum = std::accumulate(y.begin(), y.end(), 0.0);     // 0.0 tells it the starting value to add on top of
    xMean = xSum / x.size();                             // I mean this part is pretty self-explanatory: it gets the mean
    yMean = ySum / y.size();

    double numerator = 0, denominator = 0;
    for (int i = 0; i < x.size(); i++) {
        numerator += (x[i] - xMean) * (y[i] - yMean);
        denominator += (x[i] - xMean) * (x[i] - xMean);
    }
    slope = numerator / denominator;
    intercept = yMean - slope * xMean;

    xMin = *std::min_element(x.begin(), x.end());
    xMax = *std::max_element(x.begin(), x.end());

    yMin = *std::min_element(y.begin(), y.end());
    yMax = *std::max_element(y.begin(), y.end());

    double sumSquared = 0.0;                            // this part calcualtes the standard deviation as per the formula in the report
    for (double val : y) {
        sumSquared += std::pow(val - yMean, 2);
    }
    stddev = std::sqrt(sumSquared / y.size());
}
