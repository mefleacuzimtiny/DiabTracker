#ifndef EDITRECORDDIALOG_H
#define EDITRECORDDIALOG_H

#include <QDialog>

namespace Ui {
class EditRecordDialog;
}

class EditRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditRecordDialog(QWidget *parent = nullptr);
    ~EditRecordDialog();

    QDateTime getCreationDateTime();
    QTime getRecentMealTime();
    QString getValue();
    QString getDesc();

    void setCreationDateTime(QDateTime);
    void setRecentMealTime(QTime);
    void setValue(QString);
    void setDescription(QString);

private:
    Ui::EditRecordDialog *ui;
};



#endif // EDITRECORDDIALOG_H
