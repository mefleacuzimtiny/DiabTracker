#include "editrecorddialog.h"
#include "ui_editrecorddialog.h"
const QString GLOBAL_DATE_TIME_FORMAT = "hh:mm AP, ddd, dd MMMM yyyy";

EditRecordDialog::EditRecordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditRecordDialog) {
    ui->setupUi(this);
}

EditRecordDialog::~EditRecordDialog() {
    delete ui;
}

QDateTime EditRecordDialog::getRecentMealTime() {
    return ui->DateTimeEditRecentMeal->dateTime();
}
QString EditRecordDialog::getValue() {
    return ui->LineEditValue->text();
}
QString EditRecordDialog::getDesc() {
    return ui->TextEditDescription->toPlainText();
}

void EditRecordDialog::setCreationDateTime(QDateTime datetime) {
    ui->LabelDateTimeCreatedDisplay->setText(datetime.toString(GLOBAL_DATE_TIME_FORMAT));
}
void EditRecordDialog::setRecentMealDateTime(QDateTime datetime) {
    ui->DateTimeEditRecentMeal->setDisplayFormat(GLOBAL_DATE_TIME_FORMAT);
    ui->DateTimeEditRecentMeal->setDateTime(datetime);
}

void EditRecordDialog::setValue(QString value) {
    ui->LineEditValue->setText(value);
}

void EditRecordDialog::setDescription(QString desc) {
    ui->TextEditDescription->setText(desc);
}
