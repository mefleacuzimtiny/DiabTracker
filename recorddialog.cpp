#include "recorddialog.h"
#include "ui_recorddialog.h"

RecordDialog::RecordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RecordDialog)
{
    ui->setupUi(this);
}

RecordDialog::~RecordDialog()
{
    delete ui;
}

QString RecordDialog::getValue() const {
    return ui->LineEditValue->text();
}

QTime RecordDialog::getTime() const {
    return ui->LineEditEatingTime->time();
}

QString RecordDialog::getDescription() const {
    return ui->TextEditDesc->toPlainText();
}

void RecordDialog::setTimeEdit(QTime time) {
    return ui->LineEditEatingTime->setTime(time);
}
