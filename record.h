#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <iostream>
#include <QLabel>
#include <QDateTime>
#include <QPushButton>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QMessageBox>

#include "mainwindow.h"
#include "editrecorddialog.h"
#include "recorddisplayframe.h"

/* TODO:
 * Design the record fields and methods:
    o TimeSinceFood
    o Description
    o Time (current time if not provided)
    o Date (current date if not provided)
    o Record.repr() returns a line containing: TimeSinceFood, description, Time, Date
 * Design the Record Display Box:
    o Contains the index of the record in the vector
    o Contains an structure with sub-structures
    o Contains a sub-structure DeleteButton
    o Contains a sub-structure EditButton
*/

// class Record {
// public:
//     int Reading;
//     QTime TimeSinceEating;
//     QString Description;
//     QDateTime DateTime;

//     Record(int reading, QTime time_since_eating, QString desc, QDate date = QDate::currentDate(), QTime time = QTime::currentTime()) {
//         Reading = reading;
//         TimeSinceEating = time_since_eating;
//         Description = desc;
//         DateTime = QDateTime(date, time);
//     }

//     std::string repr() {
//         return "abc";
//     }
// };

struct Record {
    int Reading = 1;
    QTime RecentEatingTime = QTime(6,30,0);
    QString Description = "No Description";
    QDateTime DateTimeCreation = QDateTime(QDate(2022, 5, 18), QTime(4, 15, 0));
    QFrame* DisplayFrame;

    Record(int reading, QTime recent_meal_time, QString desc, QDate date = QDate::currentDate(), QTime time = QTime::currentTime()) {
        Reading = reading;
        RecentEatingTime = recent_meal_time;
        Description = desc;
        DateTimeCreation = QDateTime(date, time);
    }

    Record() {

    }

    std::string repr() {    // returns a string containing time, desc, datetime
        return "abc";
    }

    void writeToHistoryFile() {
        // writes current record to history file
    }

    void recordAddDialog(MainWindow* window) {
        RecordDialog recordInputs(window);
        recordInputs.setTimeEdit(QTime::currentTime());
        bool dialogIsAccepted = recordInputs.exec() == QDialog::Accepted;

        if (dialogIsAccepted) {
            Reading = recordInputs.getValue().toInt();
            if (Reading <= 0) {
                // popup error dialogue
                QMessageBox::critical(window, "Error", "Cannot have an empty reading!");
                qDebug() << "Cannot have an empty Reading" << "\n";
                return;
            }
            Description = recordInputs.getDescription();
            RecentEatingTime = recordInputs.getTime();
            addToDisplay(window);
        }
    }

    void recordEditDialog(MainWindow* window) {
        EditRecordDialog editRecord(window);
        editRecord.setCreationDateTime(DateTimeCreation);
        editRecord.setRecentMealTime(RecentEatingTime);
        editRecord.setDescription(Description);
        editRecord.setValue(QString::number(Reading));
        bool dialogIsAccepted = editRecord.exec() == QDialog::Accepted;

        if (dialogIsAccepted) {
            qDebug() << "RECORD BEING EDITED" << '\n';
            //TODO: Get the values from the editDialog window (by declaring and implementing it's getters) and store them into the attributes of this struct
            // And then in the edit button slot (the function that calls this one), find a way to refresh that particular frame so the new values show.

            Reading = editRecord.getValue().toInt();

            if (Reading <= 0) {
                // popup error dialogue
                QMessageBox::critical(window, "Error", "Cannot have an empty reading!");
                qDebug() << "Cannot have an empty Reading" << "\n";
                return;
            }

            RecentEatingTime = editRecord.getRecentMealTime();
            Description = editRecord.getDesc();
            DateTimeCreation = editRecord.getCreationDateTime();

            QObjectList Children = recordContainer->children();

            QLabel* ValueLabel = qobject_cast<QLabel*>(Children.at(1)->children().at(1)->children().at(1));
            QLabel* DescLabel = qobject_cast<QLabel*>(Children.at(1)->children().at(1)->children().at(2));
            QLabel* ValueDateLabel = qobject_cast<QLabel*>(Children.at(1)->children().at(1)->children().at(3));
        }
    }

    void addToDisplay(MainWindow* window) {
        /*
        // QVBoxLayout* History = qobject_cast<QVBoxLayout*>(window.ui->HistoryContents->layout());
        QVBoxLayout* History = window->getHistoryLayout();

        DisplayFrame = new QFrame();
            QHBoxLayout* newRecord = new QHBoxLayout(DisplayFrame); newRecord->setObjectName("newRecord");

            QFrame* DetailsFrame = new QFrame(); DetailsFrame->setObjectName("DetailsFrame");
                QHBoxLayout* recordDetails = new QHBoxLayout(DetailsFrame); recordDetails->setObjectName("recordDetails");

                QFrame* LabelsFrame = new QFrame(); LabelsFrame->setObjectName("LabelsFrame");
                    QVBoxLayout* detailLabels = new QVBoxLayout(LabelsFrame); detailLabels->setObjectName("LabelsFrame");

                        QLabel* ValueLabel = new QLabel(); ValueLabel->setObjectName("ValueLabel");
                        QLabel* DescLabel = new QLabel(); DescLabel->setObjectName("DescLabel");
                        QLabel* ValueDateLabel = new QLabel(); ValueDateLabel->setObjectName("ValueDateLabel");

                        ValueLabel->setText(QString::number(Reading));
                        DescLabel->setText(Description);
                        ValueDateLabel->setText(DateTimeCreation.toString());

                    detailLabels->addWidget(ValueLabel);
                    detailLabels->addWidget(DescLabel);
                    detailLabels->addWidget(ValueDateLabel);

                    QSpacerItem* spacer = new QSpacerItem(50, 50, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

                recordDetails->insertWidget(0, LabelsFrame);
                recordDetails->insertSpacerItem(1, spacer);

            QFrame* OptionsFrame = new QFrame(); OptionsFrame->setObjectName("OptionsFrame");
                QHBoxLayout* recordOptions = new QHBoxLayout(OptionsFrame); recordOptions->setObjectName("recordOptions");

                    QPushButton* btnDelete = new QPushButton("delete");
                    QPushButton* btnEdit = new QPushButton("Edit");

                    QObject::connect(btnDelete, SIGNAL(clicked()), window, SLOT(on_DeleteButton_clicked()));
                    QObject::connect(btnEdit, SIGNAL(clicked()), window, SLOT(on_EditButton_clicked()));

                recordOptions->insertWidget(0, btnDelete);
                recordOptions->insertWidget(1, btnEdit);

            newRecord->addWidget(DetailsFrame);
            newRecord->addWidget(OptionsFrame);

        // History->insertWidget(History->count()-1, RecordFrame);
        */
        History->insertWidget(0, DisplayFrame);
    }
};

QVector<Record> Records;

#endif // RECORD_H
