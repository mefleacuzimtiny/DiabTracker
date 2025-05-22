#include "recorddisplayframe.h"
#include "ui_recorddisplayframe.h"
#include "editrecorddialog.h"
#include "HistoryData.h"

#include <QMessageBox>
#include <string>

const QString GLOBAL_DATE_TIME_FORMAT = "hh:mm AP, ddd, dd MMMM yyyy";

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

QString RecordDisplayFrame::getTimeSinceMeal()
{
    // qint64 totalSeconds = RecentMealDateTime.secsTo(DateTimeCreation);

    long long totalSeconds = RecentMealDateTime.secsTo(DateTimeCreation);
    int days = totalSeconds / (3600 * 24);
    int hours = (totalSeconds % (3600 * 24)) / 3600;
    int minutes = (totalSeconds % 3600) / 60;

    QString result;

    if (days > 0) {
        result += QString::number(days) + " day";
        if (days != 1){
            result += "s";
        }
    }

    if (hours > 0) {
        if (!result.isEmpty()){             // qtstring equivalent of result != "", omits hours if they're zero
            result += ", ";
        }
        result += QString::number(hours) + " hour";
        if (hours != 1){
            result += "s";
        }
    }

    if (minutes > 0) {
        if (!result.isEmpty()) {            // omits minutes if they're zero
            result += ", ";
        }
        result += QString::number(minutes) + " minute";
        if (minutes != 1){
            result += "s";
        }
    }

    if (!result.isEmpty()) {                // if result contains something, add " ago" at the end
        result += " ago";
    } else {
        result = "just now";                // else, just make it "just now"
    }

    return result;
}

void RecordDisplayFrame::setValue(int reading)
{
    ui->LabelValueDisplay->setText(QString::number(reading));
}

void RecordDisplayFrame::setDescription(QString desc)
{
    ui->LabelDescriptionDisplay->setText(desc);
}


void RecordDisplayFrame::setTimeSinceMeal(QDateTime datetime)
{
    ui->LabelTimeSinceMealDisplay->setText(getTimeSinceMeal());
}

void RecordDisplayFrame::updateValues()
{
    setValue(Reading);
    setTimeSinceMeal(RecentMealDateTime);
    setDescription(Description);
}

std::string RecordDisplayFrame::repr()
{
    return std::to_string(Reading) + ","
            + '"' + Description.toStdString() + '"' + ","
            + RecentMealDateTime.toString().toStdString() + ","
            + DateTimeCreation.toString().toStdString();
}

void RecordDisplayFrame::on_ButtonEdit_clicked()
{
    EditRecordDialog recordEditDialogue(this);

    recordEditDialogue.setValue(QString::number(Reading));
    recordEditDialogue.setDescription(Description);
    recordEditDialogue.setRecentMealDateTime(RecentMealDateTime);
    recordEditDialogue.setCreationDateTime(DateTimeCreation);

    bool dialogIsAccepted = recordEditDialogue.exec() == QDialog::Accepted;
    if (dialogIsAccepted) {
        qDebug() << "RECORD BEING EDITED" << '\n';

        Reading = recordEditDialogue.getValue().toInt();

        if (Reading <= 0) {
            QMessageBox::critical(this, "Error", "Cannot have an empty reading!");
            qDebug() << "Cannot have an empty Reading" << "\n";
            return;
        }

        Reading = recordEditDialogue.getValue().toInt();
        RecentMealDateTime = recordEditDialogue.getRecentMealTime();
        Description = recordEditDialogue.getDesc();

        updateValues();
    }
    recordEditDialogue.deleteLater();
}

void RecordDisplayFrame::on_ButtonDelete_clicked()
{
    // delete from HistoryData
    deleteRecord(this);
    this->deleteLater();
}

