#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recorddialog.h"
#include "record.h"
#include "editrecorddialog.h"

#include <QLabel>
#include <QDateTime>
#include <QPushButton>

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
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (senderButton == nullptr) {
        return;
    }

    QWidget* recordContainer = senderButton->parentWidget()->parentWidget();
    if (recordContainer == nullptr) {
        return;
    }

    recordContainer->deleteLater();
}

void MainWindow::on_EditButton_clicked() {
    Record rec;
    rec.recordEditDialog(this);
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (senderButton == nullptr) {
        return;
    }

    QWidget* recordContainer = senderButton->parentWidget()->parentWidget();
    if (recordContainer == nullptr) {
        return;
    }

    // TODO: write code to update the labels inside the recordContainer to be the same as the attributes of rec

    QObjectList Children = recordContainer->children();
    for (QObject* child : Children) {
        qDebug() << child->objectName() << "\n";
    }
}


void MainWindow::on_AddButton_clicked() {

    // Record rec(123, QTime::currentTime(), "this is a description");
    // rec.takeInputs(this);
    // rec.addToDisplay(this);

    Record rec;
    rec.recordAddDialog(this);

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

