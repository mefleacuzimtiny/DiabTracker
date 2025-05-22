#ifndef RECORDDISPLAYFRAME_H
#define RECORDDISPLAYFRAME_H

#include <QWidget>
#include <QDateTime>
#include <string>

namespace Ui {
class RecordDisplayFrame;
}

class RecordDisplayFrame : public QWidget
{
    Q_OBJECT

public:
    explicit RecordDisplayFrame(QWidget *parent = nullptr);
    ~RecordDisplayFrame();

    void setValue(int reading);
    void setDescription(QString desc);
    void setTimeSinceMeal(QDateTime datetime);
    void updateValues();

    std::string repr(); // returns a string to be stoored inside of a text file, with values separated by commas
    QString getTimeSinceMeal(); // returns difference between RecentMealTime and DateTimeCreation

    int Reading = 1;
    QString Description = "No Description";
    QDateTime RecentMealDateTime = QDateTime(QDate::currentDate(), QTime(6,30,0));
    QDateTime DateTimeCreation;

private slots:
    void on_ButtonEdit_clicked();

    void on_ButtonDelete_clicked();

private:
    Ui::RecordDisplayFrame *ui;
};

#endif // RECORDDISPLAYFRAME_H
