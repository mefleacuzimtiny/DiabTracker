#ifndef RECORDDISPLAYFRAME_H
#define RECORDDISPLAYFRAME_H

#include <QWidget>

namespace Ui {
class RecordDisplayFrame;
}

class RecordDisplayFrame : public QWidget
{
    Q_OBJECT

public:
    explicit RecordDisplayFrame(QWidget *parent = nullptr);
    ~RecordDisplayFrame();

private:
    Ui::RecordDisplayFrame *ui;
};

#endif // RECORDDISPLAYFRAME_H
