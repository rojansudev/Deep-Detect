#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mythread.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    mythread *mt;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_file_button_clicked();

    void on_directory_button_clicked();

    void on_directory_browse_clicked();

    void on_directory_scan_clicked();

    void on_bck_button_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
public slots:
    void outfromthread(QString);
};

#endif // MAINWINDOW_H
