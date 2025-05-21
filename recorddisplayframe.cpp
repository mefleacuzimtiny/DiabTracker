#include "recorddisplayframe.h"
#include "ui_recorddisplayframe.h"
#include "editrecorddialog.h"

#include <QMessageBox>

RecordDisplayFrame::RecordDisplayFrame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecordDisplayFrame)
{
    ui->setupUi(this);
}

RecordDisplayFrame::~RecordDisplayFrame()
{
    delete ui;
}

void RecordDisplayFrame::setValue(int reading)
{
    ui->LabelValueDisplay->setText(QString::number(reading));
}

void RecordDisplayFrame::setDescription(QString desc)
{
    ui->LabelDescriptionDisplay->setText(desc);
}

void RecordDisplayFrame::setRecentMealTime(QTime time, QDate date)
{
    ui->LabelRecentMealTimeDisplay->setText(date.toString() + ", " + time.toString());
}

void RecordDisplayFrame::updateValues()
{
    setValue(Reading);
    setRecentMealTime(RecentMealTime);
    setDescription(Description);
}

void RecordDisplayFrame::on_ButtonEdit_clicked()
{
    EditRecordDialog editRecord(this);
    editRecord.setCreationDateTime(DateTimeCreation);
    editRecord.setRecentMealTime(RecentMealTime);
    editRecord.setDescription(Description);
    editRecord.setValue(QString::number(Reading));

    bool dialogIsAccepted = editRecord.exec() == QDialog::Accepted;
    if (dialogIsAccepted) {
        qDebug() << "RECORD BEING EDITED" << '\n';

        Reading = editRecord.getValue().toInt();

        if (Reading <= 0) {
            QMessageBox::critical(this, "Error", "Cannot have an empty reading!");
            qDebug() << "Cannot have an empty Reading" << "\n";
            return;
        }

        Reading = editRecord.getValue().toInt();
        RecentMealTime = editRecord.getRecentMealTime();
        Description = editRecord.getDesc();
        DateTimeCreation = editRecord.getCreationDateTime();

        updateValues();
    }
}
