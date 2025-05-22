#include "recorddialog.h"
#include "ui_recorddialog.h"

const QString GLOBAL_DATE_TIME_FORMAT = "hh:mm AP, ddd, dd MMMM yyyy";

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
    return ui->DateTimeEditRecentMeal->dateTime();
}

QString RecordDialog::getDescription() const {
    return ui->TextEditDesc->toPlainText();
}

void RecordDialog::setDateTimeEdit(QDateTime datetime) {
    ui->DateTimeEditRecentMeal->setDisplayFormat(GLOBAL_DATE_TIME_FORMAT);
    return ui->DateTimeEditRecentMeal->setDateTime(datetime);
}
