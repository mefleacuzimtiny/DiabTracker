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

    ui->ButtonDelete->setStyleSheet(R"(
        QPushButton {
            background-color: #3498db;
            color: white;
            border: none;
            border-radius: 25px;  /* Half of width/height to make it round */
            font-size: 50px;
        }
        QPushButton:hover {
            background-color: #2980b9;
        }
        QPushButton:pressed {
            background-color: #1c5980;
        }
    )");
    ui->ButtonDelete->setIcon(QIcon(":/icons/DeleteButton.svg"));
    ui->ButtonDelete->setIconSize(QSize(75,75));
    ui->ButtonDelete->setText("");

    ui->ButtonEdit->setStyleSheet(R"(
        QPushButton {
            background-color: #3498db;
            color: white;
            border: none;
            border-radius: 25px;  /* Half of width/height to make it round */
            font-size: 50px;
            box-shadow: 10px 10px;
        }
        QPushButton:hover {
            background-color: #2980b9;
        }
        QPushButton:pressed {
            background-color: #1c5980;
        }
    )");
    ui->ButtonEdit->setIcon(QIcon(":/icons/EditButton.svg"));
    ui->ButtonEdit->setIconSize(QSize(75,75));
    ui->ButtonEdit->setText("");
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

    if (!result.isEmpty()) {                // if result contains something, add " after eating" at the end
        result += " after eating";
    } else {
        result = "Meal eaten recently";                // else, just make it "Meal eaten recently"
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

