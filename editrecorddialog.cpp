#include "editrecorddialog.h"
#include "ui_editrecorddialog.h"

EditRecordDialog::EditRecordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditRecordDialog) {
    ui->setupUi(this);
}

EditRecordDialog::~EditRecordDialog() {
    delete ui;
}

QDateTime EditRecordDialog::getCreationDateTime() {
    return ui->DateTimeEditCreation->dateTime();
}
QTime EditRecordDialog::getRecentMealTime() {
    return ui->TimeEditRecentMeal->time();
}
QString EditRecordDialog::getValue() {
    return ui->LineEditValue->text();
}
QString EditRecordDialog::getDesc() {
    return ui->TextEditDescription->toPlainText();
}

void EditRecordDialog::setCreationDateTime(QDateTime datetime) {
    ui->DateTimeEditCreation->setDateTime(datetime);
}
void EditRecordDialog::setRecentMealTime(QTime time) {
    ui->TimeEditRecentMeal->setTime(time);
}

void EditRecordDialog::setValue(QString value) {
    ui->LineEditValue->setText(value);
}

void EditRecordDialog::setDescription(QString desc) {
    ui->TextEditDescription->setText(desc);
}
