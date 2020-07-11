/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QLabel *virus_label;
    QLabel *normal_label;
    QLabel *image_label;
    QLabel *error_label;
    QPushButton *file_button;
    QPushButton *directory_button;
    QPushButton *directory_browse;
    QPushButton *directory_scan;
    QLabel *directory_label_2;
    QPushButton *bck_button;
    QLabel *file_label;
    QLabel *directory_label;
    QLabel *load_label;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(675, 574);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(410, 150, 99, 27));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 150, 231, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 210, 111, 27));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(60, 60, 571, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 250, 111, 27));
        virus_label = new QLabel(centralWidget);
        virus_label->setObjectName(QStringLiteral("virus_label"));
        virus_label->setGeometry(QRect(260, 370, 231, 20));
        virus_label->setStyleSheet(QLatin1String("color: rgb(255, 81, 58);\n"
""));
        virus_label->setTextFormat(Qt::PlainText);
        normal_label = new QLabel(centralWidget);
        normal_label->setObjectName(QStringLiteral("normal_label"));
        normal_label->setGeometry(QRect(240, 370, 251, 20));
        normal_label->setStyleSheet(QStringLiteral("color: rgb(99, 255, 135);"));
        image_label = new QLabel(centralWidget);
        image_label->setObjectName(QStringLiteral("image_label"));
        image_label->setGeometry(QRect(320, 300, 71, 61));
        error_label = new QLabel(centralWidget);
        error_label->setObjectName(QStringLiteral("error_label"));
        error_label->setGeometry(QRect(190, 370, 351, 17));
        error_label->setStyleSheet(QLatin1String("font: 75 16pt \"Bitstream Vera Sans\";\n"
"color: rgb(231, 231, 0);"));
        file_button = new QPushButton(centralWidget);
        file_button->setObjectName(QStringLiteral("file_button"));
        file_button->setGeometry(QRect(130, 120, 141, 161));
        directory_button = new QPushButton(centralWidget);
        directory_button->setObjectName(QStringLiteral("directory_button"));
        directory_button->setGeometry(QRect(420, 120, 161, 171));
        directory_browse = new QPushButton(centralWidget);
        directory_browse->setObjectName(QStringLiteral("directory_browse"));
        directory_browse->setGeometry(QRect(410, 150, 99, 27));
        directory_scan = new QPushButton(centralWidget);
        directory_scan->setObjectName(QStringLiteral("directory_scan"));
        directory_scan->setGeometry(QRect(310, 250, 99, 27));
        directory_label_2 = new QLabel(centralWidget);
        directory_label_2->setObjectName(QStringLiteral("directory_label_2"));
        directory_label_2->setGeometry(QRect(250, 290, 391, 131));
        directory_label_2->setStyleSheet(QStringLiteral("color: rgb(245, 245, 245);"));
        bck_button = new QPushButton(centralWidget);
        bck_button->setObjectName(QStringLiteral("bck_button"));
        bck_button->setGeometry(QRect(10, 0, 99, 31));
        file_label = new QLabel(centralWidget);
        file_label->setObjectName(QStringLiteral("file_label"));
        file_label->setGeometry(QRect(130, 240, 141, 51));
        file_label->setStyleSheet(QStringLiteral("color:rgb(245, 245, 245)"));
        directory_label = new QLabel(centralWidget);
        directory_label->setObjectName(QStringLiteral("directory_label"));
        directory_label->setGeometry(QRect(410, 240, 459, 51));
        directory_label->setStyleSheet(QStringLiteral("color: rgb(245, 245, 245);"));
        load_label = new QLabel(centralWidget);
        load_label->setObjectName(QStringLiteral("load_label"));
        load_label->setGeometry(QRect(160, 280, 381, 131));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(300, 400, 111, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 675, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Browse", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Start", 0));
        label->setText(QString());
        label_2->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "Scan", 0));
        virus_label->setText(QApplication::translate("MainWindow", "FILE  INFECTED", 0));
        normal_label->setText(QApplication::translate("MainWindow", "FILE UNINFECTED", 0));
        image_label->setText(QString());
        error_label->setText(QApplication::translate("MainWindow", "FILE FORMAT NOT SUPPORTED", 0));
        file_button->setText(QString());
        directory_button->setText(QString());
        directory_browse->setText(QApplication::translate("MainWindow", "Browse", 0));
        directory_scan->setText(QApplication::translate("MainWindow", "SCAN", 0));
        directory_label_2->setText(QString());
        bck_button->setText(QApplication::translate("MainWindow", "BACK", 0));
        file_label->setText(QApplication::translate("MainWindow", "       FILE", 0));
        directory_label->setText(QApplication::translate("MainWindow", "    DIRECTORY", 0));
        load_label->setText(QString());
        pushButton_4->setText(QApplication::translate("MainWindow", "Report", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
