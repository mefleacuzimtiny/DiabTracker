#include "recorddisplayframe.h"
#include "ui_recorddisplayframe.h"
#include "editrecorddialog.h"

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
    ui->LabelTimeSinceMealDisplay->setText(datetime.toString(GLOBAL_DATE_TIME_FORMAT));
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

QString RecordDisplayFrame::getTimeSinceMeal()
{
    // datetimecreation - recentmealtime
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
    // remove from history vector
    this->deleteLater();
}

