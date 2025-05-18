#ifndef RECORDDIALOG_H
#define RECORDDIALOG_H

#include <QDialog>
#include <QTimeEdit>

namespace Ui {
class RecordDialog;
}

class RecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RecordDialog(QWidget *parent = nullptr);
    ~RecordDialog();

    QString getValue() const;

    QTime getTime() const;

    QString getDescription() const; // const protects the function from modifying members

    void setTimeEdit(QTime);

private:
    Ui::RecordDialog *ui;
};

#endif // RECORDDIALOG_H
