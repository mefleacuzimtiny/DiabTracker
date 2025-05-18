#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>


QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE



class MainWindow : public QMainWindow {
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVBoxLayout* getHistoryLayout();


private slots:
    void on_actionOpen_History_triggered();

    void on_DeleteButton_clicked();
    void on_EditButton_clicked();
    void on_AddButton_clicked();

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
