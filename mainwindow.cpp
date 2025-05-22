#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recorddialog.h"
#include "editrecorddialog.h"
#include "recorddisplayframe.h"
#include "HistoryData.h"

#include <QLabel>
#include <QDateTime>
#include <QPushButton>
#include <QMessageBox>
#include <array>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

QVBoxLayout* MainWindow::getHistoryLayout() {
    return qobject_cast<QVBoxLayout*>(ui->HistoryContents->layout());
}

void MainWindow::on_actionOpen_History_triggered() {
    // add popup asking for directory to text file containing records
    // parse inputed text file based on directory and store data
    // for each item in the data, generate a RecordDisplayFrame widget and store its pointer in HistoryData

    QVBoxLayout* History = this->getHistoryLayout();

    std::vector <std::array <std::string, 4>> records;
    std::ifstream fout("RecordHistory.txt", std::ios::app);
    if (fout.is_open()) {
        records = parseCSV(fout);
        fout.close();
    }


    for (int i = 0; i < records.size(); i++) {
        RecordDisplayFrame* recdisp = new RecordDisplayFrame;
        // todo: fix the damn CSV parser!!!
        qDebug() << "Value: " << records[i][0] << "\n"
                  << "Description: " << records[i][1] << "\n"
                  << "RecentMealTime: " << records[i][2] << "\n"
                  << "Date Created: " << records[i][3] << "\n"
                  << "--------------------------\n";


        recdisp->Reading = std::stoi(records[i][0]);
        recdisp->Description = QString::fromStdString(records[i][1]);
        recdisp->RecentMealDateTime = QDateTime::fromString(QString::fromStdString(records[i][2]), "ddd MMM dd HH:mm:ss yyyy");
        recdisp->DateTimeCreation = QDateTime::fromString(QString::fromStdString(records[i][3]), "ddd MMM dd HH:mm:ss yyyy");

        History->insertWidget(0, recdisp);
        addRecord(recdisp);
    }

    /* PARSING PSEUDOCODE:
    for each character in file:
        is it a quote?
            toggle insideQuotes
        no? is it a comma?
            is it inside quotes?
                add the character to the field
            no?
                we haven't reached maximum fields (i.e 4 fields)?
                    add field to currentRecord
                    field string becomes empty
        no? is it a newline?
            is it inside quotes?
                add it to the field
            no?
                add field to currentRecord
                add currentRecord to record table

                reset state
        no?
            add the character to the field

    last record will be an empty string if the file doesn't end with a newline so this is to safeguard from that
    is there is a remaining field or field index is 3?
        add field to currentRecord
        add currentRecord to record table
    */
    dumpRecords();
}

void MainWindow::on_actionSave_Data_triggered()
{
    writeRecordsToFile();
}

void MainWindow::on_AddButton_clicked() {

    QVBoxLayout* History = this->getHistoryLayout();
    RecordDisplayFrame* recdisp = new RecordDisplayFrame();

    RecordDialog recordInputs(this);
    recordInputs.setDateTimeEdit(QDateTime::currentDateTime());

    bool dialogIsAccepted = recordInputs.exec() == QDialog::Accepted;
    if (dialogIsAccepted) {
        int Reading = recordInputs.getValue().toInt();
        if (Reading <= 0) {
            QMessageBox::critical(this, "Error", "Cannot have an empty reading!");
            qDebug() << "Cannot have an empty Reading" << "\n";
            return;
        }

        recdisp->Reading = Reading;
        recdisp->RecentMealDateTime = recordInputs.getDateTime();
        recdisp->Description = recordInputs.getDescription();
        recdisp->DateTimeCreation = QDateTime::currentDateTime();

        recdisp->updateValues();
        History->insertWidget(0, recdisp);

        addRecord(recdisp);

        std::fstream fout("RecordHistory.txt", std::ios::app);
        if (fout.is_open()) {
            fout << recdisp->repr() << '\n';
            fout.close();
        }
    }
}


