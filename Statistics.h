#ifndef STATISTICS_H
#define STATISTICS_H

#include <QLineSeries>

struct BFLData {
    double xSum;
    double ySum;
    double xMean;
    double yMean;

    double slope;
    double intercept;

    double xMin;
    double xMax;

    double yMin;
    double yMax;

    double stddev;
    BFLData(QLineSeries* series);
};

#endif // STATISTICS_H
