#include "recorddisplayframe.h"
#include "ui_recorddisplayframe.h"

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
