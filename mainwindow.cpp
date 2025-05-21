#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recorddialog.h"
#include "record.h"
#include "editrecorddialog.h"
#include "recorddisplayframe.h"

#include <QLabel>
#include <QDateTime>
#include <QPushButton>
#include <QMessageBox>
#include <QVector>

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
    qDebug() << "ABCDEFGHI" <<"\n";
}

void MainWindow::on_DeleteButton_clicked() {
    // QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    // if (senderButton == nullptr) {
    //     return;
    // }

    // QWidget* recordContainer = senderButton->parentWidget()->parentWidget();
    // if (recordContainer == nullptr) {
    //     return;
    // }

    // recordContainer->deleteLater();
}

void MainWindow::on_EditButton_clicked() {
    // Record rec;
    // rec.recordEditDialog(this);
    // QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    // if (senderButton == nullptr) {
    //     return;
    // }

    // QWidget* recordContainer = senderButton->parentWidget()->parentWidget();
    // if (recordContainer == nullptr) {
    //     return;
    // }

    // // TODO: write code to update the labels inside the recordContainer to be the same as the attributes of rec

    // QObjectList Children = recordContainer->children();

    // QLabel* ValueLabel = qobject_cast<QLabel*>(Children.at(1)->children().at(1)->children().at(1));
    // QLabel* DescLabel = qobject_cast<QLabel*>(Children.at(1)->children().at(1)->children().at(2));
    // QLabel* ValueDateLabel = qobject_cast<QLabel*>(Children.at(1)->children().at(1)->children().at(3));

    // ValueLabel->setText(QString::number(rec.Reading));
    // DescLabel->setText(rec.Description);
    // ValueDateLabel->setText(rec.DateTimeCreation.toString());

    /////////////////////////////////////////////// DEBUGGING AREA /////////////////////////////////////////////
    // {
    //     for (QObject* child : Children) {
    //         qDebug() << child->objectName() << "\n";
    //         for (QObject* subchild : child->children()) {
    //             qDebug() << "\t" <<  subchild->objectName() << "\n";
    //             for (QObject* subsubchild : subchild->children()) {
    //                 qDebug() << "\t\t" << subsubchild->objectName() << "\n";
    //             }
    //         }
    //     }

    //     qDebug() << ValueLabel->objectName();
    //     qDebug() << ValueDateLabel->objectName();
    //     qDebug() << DescLabel->objectName();

    // }

    /* Name Tree:
        "newRecord"

        "DetailsFrame"

             "recordDetails"

             "LabelsFrame"

                 "LabelsFrame"

                 "ValueLabel"

                 "DescLabel"

                 "ValueDateLabel"

        "OptionsFrame"

             "recordOptions"

             ""

             ""
    */
    /////////////////////////////////////////// END DEBUGGING AREA //////////////////////////////////////////////
}

QVector<Record> Records;

void MainWindow::on_AddButton_clicked() {

    QVBoxLayout* History = this->getHistoryLayout();
    RecordDisplayFrame* recdisp = new RecordDisplayFrame();

    RecordDialog recordInputs(this);
    recordInputs.setTimeEdit(QTime::currentTime());
    bool dialogIsAccepted = recordInputs.exec() == QDialog::Accepted;

    if (dialogIsAccepted) {
        int Reading = recordInputs.getValue().toInt();
        if (Reading <= 0) {
            // popup error dialogue
            QMessageBox::critical(this, "Error", "Cannot have an empty reading!");
            qDebug() << "Cannot have an empty Reading" << "\n";
            return;
        }

        recdisp->Reading = Reading;
        recdisp->RecentMealTime = recordInputs.getTime();
        recdisp->Description = recordInputs.getDescription();
        recdisp->updateValues();
    }

    History->insertWidget(0, recdisp);

    // rec.repr();
}


/*
QVBoxLayout* History = qobject_cast<QVBoxLayout*>(ui->HistoryContents->layout());

QFrame* RecordFrame = new QFrame();
QHBoxLayout* newRecord = new QHBoxLayout(RecordFrame);

    QFrame* DetailsFrame = new QFrame();
    QHBoxLayout* recordDetails = new QHBoxLayout(DetailsFrame);

            QFrame* LabelsFrame = new QFrame();
            QVBoxLayout* detailLabels = new QVBoxLayout(LabelsFrame);

                QLabel* ValueLabel1 = new QLabel(QObject::tr("Value#%1").arg(History->count()));
                QLabel* ValueLabel2 = new QLabel(QObject::tr("Value#%1").arg(History->count()));
                QLabel* ValueLabel3 = new QLabel(QObject::tr("Value#%1").arg(History->count()));

            detailLabels->addWidget(ValueLabel1);
            detailLabels->addWidget(ValueLabel2);
            detailLabels->addWidget(ValueLabel3);

            QSpacerItem* spacer = new QSpacerItem(50, 50, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

    recordDetails->insertWidget(0, LabelsFrame);
    recordDetails->insertSpacerItem(1, spacer);

    QFrame* OptionsFrame = new QFrame();
    QHBoxLayout* recordOptions = new QHBoxLayout(OptionsFrame);

        QPushButton* btnDelete = new QPushButton("delete");
        connect(btnDelete, SIGNAL(clicked()), this, SLOT(on_DeleteButton_clicked()));
        QPushButton* btnEdit = new QPushButton("Edit");
        connect(btnEdit, SIGNAL(clicked()), this, SLOT(on_EditButton_clicked()));
    recordOptions->insertWidget(0, btnDelete);
    recordOptions->insertWidget(1, btnEdit);

newRecord->addWidget(DetailsFrame);
newRecord->addWidget(OptionsFrame);

History->insertWidget(History->count()-1, RecordFrame);
*/

