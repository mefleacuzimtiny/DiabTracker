#ifndef RECORDDISPLAYFRAME_H
#define RECORDDISPLAYFRAME_H

#include <QWidget>
#include <QDateTime>

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
    void setRecentMealTime(QTime time, QDate date = QDate::currentDate());
    void updateValues();

    int Reading = 1;
    QTime RecentMealTime = QTime(6,30,0);
    QString Description = "No Description";
    QDateTime DateTimeCreation = QDateTime::currentDateTime();

private slots:
    void on_ButtonEdit_clicked();

private:
    Ui::RecordDisplayFrame *ui;
};

#endif // RECORDDISPLAYFRAME_H
