#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <QFileDialog>
#include<QProcess>
#include<QTextStream>
#include<QFont>
#include<QPixmap>
#include<QIcon>
#include<iostream>
#include<cstdlib>
#include<QMovie>
#include<QGraphicsBlurEffect>
#include<QDesktopServices>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        this->setFixedSize(700,500);
        QString neuron=QCoreApplication::applicationDirPath()+"/neuron.jpg";
        QPixmap bkgnd(neuron);
        ui->lineEdit->setVisible(false);
        ui->pushButton->setVisible(false);
        ui->pushButton_3->setVisible(false);
        ui->virus_label->setVisible(false);
        ui->normal_label->setVisible(false);
        ui->image_label->setVisible(false);
        ui->error_label->setVisible(false);
        ui->directory_button->setVisible(false);
        ui->file_button->setVisible(false);
        ui->file_label->setVisible(false);
        ui->directory_label->setVisible(false);
        ui->directory_browse->setVisible(false);
        ui->directory_scan->setVisible(false);
        ui->bck_button->setVisible(false);
        ui->pushButton_4->setVisible(false);

        QPixmap f_pixmap("Docs-icon.png");
        QPixmap file_pixmap=f_pixmap.scaled(QSize(75,75));
        QIcon fileicon(file_pixmap);
        ui->file_button->setIcon(fileicon);
        ui->file_button->setIconSize(file_pixmap.size());
        ui->file_button->setFlat(true);
        ui->file_button->setFocusPolicy(Qt::NoFocus);

        QPixmap dir_pixmap("Folders-PNG-File.png");
        QPixmap directory_pixmap=dir_pixmap.scaled(QSize(75,75));
        QIcon dir_icon(directory_pixmap);
        ui->directory_button->setIcon(dir_icon);
        ui->directory_button->setIconSize(directory_pixmap.size());
        ui->directory_button->setFlat(true);
        ui->directory_button->setFocusPolicy(Qt::NoFocus);



        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

        QFont f( "DejaVu Sans",26, QFont::Bold);
        QFont f1( "DejaVu Sans",15, QFont::Bold);
        QFont d("Bitstream Vera Sans",18,QFont::Bold);
        ui->label->setText("<font color= 'grey'>WELCOME TO</font>");
        ui->label_2->setText("<font color='cyan'>DEEP-DETECT</font>");
        ui->label->setFont(f);
        ui->label_2->setFont(f);
        ui->directory_label_2->setFont(f1);
        ui->file_label->setFont(f1);
        ui->directory_label->setFont(f1);
        ui->virus_label->setFont(d);
        ui->normal_label->setFont(d);

        mt=new mythread(this);
        connect(mt,SIGNAL(output(QString)),this,SLOT(outfromthread(QString)));


            /*
infected
        QPixmap pixmap("/home/rojan/Downloads/files.png");
        QIcon FileIcon(pixmap);
        ui->pushButton_4->setIcon(FileIcon);
        ui->pushButton_4->setIconSize(QSize(110,102));

        QPixmap pixmap2("/home/rojan/Downloads/fold.png");
        QIcon FolderIcon(pixmap2);
        ui->pushButton_5->setIcon(FolderIcon);
        ui->pushButton_5->setIconSize(QSize(110,102));
        ui->pushButton_5->setAttribute(Qt::WA_TranslucentBackground);
        */
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{

    QString s=QFileDialog::getOpenFileName(this,tr("Explorer"),"/home/rojan/Desktop","All Files(*)");
    ui->lineEdit->setText(s);
//    box1.text=s;
    ui->virus_label->setVisible(false);
    ui->normal_label->setVisible(false);
    ui->image_label->setVisible(false);
    ui->error_label->setVisible(false);
}

void MainWindow::on_pushButton_2_clicked()
{
    /*ui->lineEdit->setVisible(true);
    ui->pushButton->setVisible(true);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_2->setVisible(false);
   */

    ui->pushButton_2->setVisible(false);
    ui->directory_button->setVisible(true);
    ui->file_button->setVisible(true);
    ui->file_label->setVisible(true);
    ui->directory_label->setVisible(true);

}

void MainWindow::on_pushButton_3_clicked()
{

    QMovie* movie=new QMovie("/home/rojan/Downloads/final.gif");
    ui->load_label->setMovie(movie);
    movie->start();
    QProcess proc;
    QString cmd="python file_predict.py "+ui->lineEdit->text();
    proc.start(cmd);
    proc.waitForFinished(-1);
    ui->load_label->clear();
    QString printed=proc.readAllStandardOutput();
    QString err=proc.readAllStandardError();
    //ui->textEdit->setText(printed);

        if(printed.compare("virus")==1)
        {
                ui->image_label->setVisible(true);
                QPixmap pix("Error.png");
                QPixmap scaled_pixmap=pix.scaled(ui->image_label->width(),ui->image_label->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
                ui->image_label->setPixmap(scaled_pixmap);

                ui->normal_label->setVisible(false);
                ui->virus_label->setVisible(true);
                ui->error_label->setVisible(false);
                //QFont f( "DejaVu Sans",26, QFont::Bold);
                //ui->virus_label->setText("<font color='red'>File infected</font>");
                //ui->virus_label->setFont(f);
        }
        if(printed.compare("normal")==1)
        {

            ui->normal_label->setVisible(true);
            ui->virus_label->setVisible(false);
            ui->image_label->setVisible(true);
            QPixmap pix("Ok.png");
            QPixmap scaled_pixmap=pix.scaled(ui->image_label->width(),ui->image_label->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
            ui->image_label->setPixmap(scaled_pixmap);
            ui->error_label->setVisible(false);

        }

        if(printed.compare("Not")==1)
        {
            ui->image_label->setVisible(true);
            QPixmap pix("Error.png");
            QPixmap scaled_pixmap=pix.scaled(ui->image_label->width(),ui->image_label->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
            ui->image_label->setPixmap(scaled_pixmap);
            ui->normal_label->setVisible(false);
            ui->virus_label->setVisible(false);
            ui->error_label->setVisible(true);

        }
}


void MainWindow::on_file_button_clicked()
{
    ui->lineEdit->setVisible(true);
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_2->setVisible(false);
        ui->file_button->setVisible(false);
        ui->file_label->setVisible(false);
        ui->directory_button->setVisible(false);
        ui->directory_label->setVisible(false);
        ui->bck_button->setVisible(true);
}

void MainWindow::on_directory_button_clicked()
{
    ui->directory_browse->setVisible(true);
    ui->lineEdit->setVisible(true);
    ui->directory_scan->setVisible(true);
    ui->directory_button->setVisible(false);
    ui->file_button->setVisible(false);
    ui->directory_label->setVisible(false);
    ui->file_label->setVisible(false);
    ui->bck_button->setVisible(true);

}

void MainWindow::on_directory_browse_clicked()
{
    QFileDialog dialog;
    QString p=dialog.getExistingDirectory(this,tr("Open Directory"),"/home",QFileDialog::ShowDirsOnly);
    ui->lineEdit->setText(p);
    ui->directory_label_2->clear();
    ui->pushButton_4->setVisible(false);
}

void MainWindow::on_directory_scan_clicked()
{
    ui->load_label->setVisible(true);
    ui->directory_label_2->clear();
    ui->pushButton_4->setVisible(false);
    mt->path=ui->lineEdit->text();
    mt->start();
    QMovie* movie=new QMovie("final.gif");
    ui->load_label->setMovie(movie);
    movie->start();

    //QProcess proc;
    //QString cmd="python directory_predict.py "+ui->lineEdit->text();
    //proc.start(cmd);
    //proc.waitForFinished(-1);

    //QString printed=proc.readAllStandardOutput();
    //QString err=proc.readAllStandardError();
    //ui->directory_label_2->setText(printed);
   // ui->directory_label_2->setText(printed);



}

void MainWindow::outfromthread(QString stdout)
{
    ui->load_label->clear();
    ui->load_label->setVisible(false);
    ui->directory_label_2->setVisible(true);
    ui->directory_label_2->setText(stdout);
    ui->pushButton_4->setVisible(true);
}

void MainWindow::on_bck_button_clicked()
{
    ui->directory_button->setVisible(true);
    ui->file_button->setVisible(true);
    ui->directory_label->setVisible(true);
    ui->file_label->setVisible(true);
    ui->bck_button->setVisible(false);

    ui->lineEdit->clear();
    ui->lineEdit->setVisible(false);
    ui->directory_browse->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->virus_label->setVisible(false);
    ui->normal_label->setVisible(false);
    ui->image_label->setVisible(false);
    ui->error_label->setVisible(false);
    ui->directory_scan->setVisible(false);
    ui->directory_label_2->clear();
    ui->directory_label_2->setVisible(false);
    ui->pushButton_4->setVisible(false);
}

void MainWindow::on_pushButton_4_clicked()
{
    QDesktopServices::openUrl(QUrl("report.txt"));
}
