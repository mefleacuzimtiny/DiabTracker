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

QDateTime RecordDialog::getDateTime() const {
    return ui->DateTimeEditLastMeal->dateTime();
}

QString RecordDialog::getDescription() const {
    return ui->TextEditDesc->toPlainText();
}

void RecordDialog::setDateTimeEdit(QDateTime datetime) {
    return ui->DateTimeEditLastMeal->setDateTime(datetime);
}
