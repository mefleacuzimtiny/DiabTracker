#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recorddialog.h"
#include "editrecorddialog.h"
#include "recorddisplayframe.h"

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

    /*
    Open file
    Initialize: vector of 4 string fields
    Initialize: field index = 0
    Initialize: current field string
    Initialize: insideQuotes = false

    While reading character-by-character:
        If char is quote ("):
            Toggle insideQuotes (entering or leaving quoted field)
            (Don't add quote character to field)

        Else if char is comma:
            If insideQuotes:
                Append comma to field
            Else:
                Save current field to arr[field index]
                Clear current field
                Increment field index

        Else if char is newline:
            If insideQuotes:
                Append newline to field
            Else:
                Save current field to arr[field index]
                Push record to vector
                Reset: field index, current field, field array, insideQuotes

        Else:
            Append char to current field

    After loop ends:
        If there's a remaining field and field index is 3:
            Save it and push record to vector
     */
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

        // HistoryData.push_back(recdisp);

        std::fstream fout("RecordHistory.txt", std::ios::app);
        if (fout) {
            fout << recdisp->repr() << '\n';
            fout.close();
        }
    }
}
