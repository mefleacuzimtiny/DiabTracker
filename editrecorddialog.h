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

    QDateTime getRecentMealTime();
    QString getValue();
    QString getDesc();

    void setCreationDateTime(QDateTime);
    void setRecentMealDateTime(QDateTime);
    void setValue(QString);
    void setDescription(QString);

private:
    Ui::EditRecordDialog *ui;
};



#endif // EDITRECORDDIALOG_H
