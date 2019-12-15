/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *buttonControlBox;
    QPushButton *driveRightButton;
    QPushButton *driveForawrdButton;
    QPushButton *driveLeftButton;
    QPushButton *driveBackwardButton;
    QSlider *speedSlider;
    QSlider *turningSlider;
    QLabel *speedLabel;
    QLabel *turningLabel;
    QGroupBox *groupBox_2;
    QRadioButton *buttonsMode;
    QRadioButton *slidersMode;
    QPushButton *stopButton;
    QTextEdit *logsMonitor;
    QLabel *logsMonitorLabel;
    QPushButton *clearMonitorButton;
    QGroupBox *groupBox;
    QSlider *directionSlider;
    QLabel *sliderDirectionLabel;
    QSlider *turningSlider_2;
    QLabel *turningSliderLabel;
    QLCDNumber *frontRadarLCD;
    QLCDNumber *rearRadarLCD;
    QLabel *frontRadarLabel;
    QLabel *rearRadaerLabel;
    QLabel *cmLabel;
    QLabel *cmLabel_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        buttonControlBox = new QGroupBox(centralwidget);
        buttonControlBox->setObjectName(QString::fromUtf8("buttonControlBox"));
        buttonControlBox->setGeometry(QRect(10, 0, 321, 231));
        driveRightButton = new QPushButton(buttonControlBox);
        driveRightButton->setObjectName(QString::fromUtf8("driveRightButton"));
        driveRightButton->setGeometry(QRect(120, 70, 101, 31));
        driveForawrdButton = new QPushButton(buttonControlBox);
        driveForawrdButton->setObjectName(QString::fromUtf8("driveForawrdButton"));
        driveForawrdButton->setGeometry(QRect(20, 30, 201, 31));
        driveLeftButton = new QPushButton(buttonControlBox);
        driveLeftButton->setObjectName(QString::fromUtf8("driveLeftButton"));
        driveLeftButton->setGeometry(QRect(20, 70, 101, 31));
        driveBackwardButton = new QPushButton(buttonControlBox);
        driveBackwardButton->setObjectName(QString::fromUtf8("driveBackwardButton"));
        driveBackwardButton->setGeometry(QRect(20, 110, 201, 31));
        speedSlider = new QSlider(buttonControlBox);
        speedSlider->setObjectName(QString::fromUtf8("speedSlider"));
        speedSlider->setGeometry(QRect(260, 30, 16, 160));
        speedSlider->setMinimum(0);
        speedSlider->setMaximum(255);
        speedSlider->setSingleStep(1);
        speedSlider->setOrientation(Qt::Vertical);
        turningSlider = new QSlider(buttonControlBox);
        turningSlider->setObjectName(QString::fromUtf8("turningSlider"));
        turningSlider->setGeometry(QRect(40, 180, 160, 16));
        turningSlider->setOrientation(Qt::Horizontal);
        speedLabel = new QLabel(buttonControlBox);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));
        speedLabel->setGeometry(QRect(240, 200, 67, 17));
        turningLabel = new QLabel(buttonControlBox);
        turningLabel->setObjectName(QString::fromUtf8("turningLabel"));
        turningLabel->setGeometry(QRect(90, 200, 67, 17));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(640, 0, 141, 111));
        buttonsMode = new QRadioButton(groupBox_2);
        buttonsMode->setObjectName(QString::fromUtf8("buttonsMode"));
        buttonsMode->setGeometry(QRect(10, 40, 112, 23));
        slidersMode = new QRadioButton(groupBox_2);
        slidersMode->setObjectName(QString::fromUtf8("slidersMode"));
        slidersMode->setGeometry(QRect(10, 70, 112, 23));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(18, 234, 311, 71));
        logsMonitor = new QTextEdit(centralwidget);
        logsMonitor->setObjectName(QString::fromUtf8("logsMonitor"));
        logsMonitor->setGeometry(QRect(13, 329, 771, 231));
        logsMonitorLabel = new QLabel(centralwidget);
        logsMonitorLabel->setObjectName(QString::fromUtf8("logsMonitorLabel"));
        logsMonitorLabel->setGeometry(QRect(20, 310, 111, 17));
        clearMonitorButton = new QPushButton(centralwidget);
        clearMonitorButton->setObjectName(QString::fromUtf8("clearMonitorButton"));
        clearMonitorButton->setGeometry(QRect(690, 300, 89, 25));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(340, 0, 211, 231));
        directionSlider = new QSlider(groupBox);
        directionSlider->setObjectName(QString::fromUtf8("directionSlider"));
        directionSlider->setGeometry(QRect(80, 40, 31, 141));
        directionSlider->setMinimum(-100);
        directionSlider->setMaximum(100);
        directionSlider->setOrientation(Qt::Vertical);
        sliderDirectionLabel = new QLabel(groupBox);
        sliderDirectionLabel->setObjectName(QString::fromUtf8("sliderDirectionLabel"));
        sliderDirectionLabel->setGeometry(QRect(60, 20, 67, 17));
        turningSlider_2 = new QSlider(groupBox);
        turningSlider_2->setObjectName(QString::fromUtf8("turningSlider_2"));
        turningSlider_2->setGeometry(QRect(20, 190, 151, 16));
        turningSlider_2->setMinimum(-100);
        turningSlider_2->setMaximum(100);
        turningSlider_2->setOrientation(Qt::Horizontal);
        turningSliderLabel = new QLabel(groupBox);
        turningSliderLabel->setObjectName(QString::fromUtf8("turningSliderLabel"));
        turningSliderLabel->setGeometry(QRect(60, 210, 67, 17));
        frontRadarLCD = new QLCDNumber(centralwidget);
        frontRadarLCD->setObjectName(QString::fromUtf8("frontRadarLCD"));
        frontRadarLCD->setGeometry(QRect(400, 240, 91, 31));
        rearRadarLCD = new QLCDNumber(centralwidget);
        rearRadarLCD->setObjectName(QString::fromUtf8("rearRadarLCD"));
        rearRadarLCD->setGeometry(QRect(400, 280, 91, 31));
        frontRadarLabel = new QLabel(centralwidget);
        frontRadarLabel->setObjectName(QString::fromUtf8("frontRadarLabel"));
        frontRadarLabel->setGeometry(QRect(350, 250, 41, 17));
        rearRadaerLabel = new QLabel(centralwidget);
        rearRadaerLabel->setObjectName(QString::fromUtf8("rearRadaerLabel"));
        rearRadaerLabel->setGeometry(QRect(350, 280, 31, 17));
        cmLabel = new QLabel(centralwidget);
        cmLabel->setObjectName(QString::fromUtf8("cmLabel"));
        cmLabel->setGeometry(QRect(500, 250, 31, 17));
        cmLabel_2 = new QLabel(centralwidget);
        cmLabel_2->setObjectName(QString::fromUtf8("cmLabel_2"));
        cmLabel_2->setGeometry(QRect(500, 290, 31, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonControlBox->setTitle(QApplication::translate("MainWindow", "Sterowanie przyciskami", nullptr));
        driveRightButton->setText(QApplication::translate("MainWindow", "Prawo", nullptr));
        driveForawrdButton->setText(QApplication::translate("MainWindow", "Do przodu", nullptr));
        driveLeftButton->setText(QApplication::translate("MainWindow", "Lewo", nullptr));
        driveBackwardButton->setText(QApplication::translate("MainWindow", "Do tylu", nullptr));
        speedLabel->setText(QApplication::translate("MainWindow", "Predkosc", nullptr));
        turningLabel->setText(QApplication::translate("MainWindow", "Skrecanie", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Tryb", nullptr));
        buttonsMode->setText(QApplication::translate("MainWindow", "Przyciski", nullptr));
        slidersMode->setText(QApplication::translate("MainWindow", "Slidery", nullptr));
        stopButton->setText(QApplication::translate("MainWindow", "STOP", nullptr));
        logsMonitorLabel->setText(QApplication::translate("MainWindow", "Monitor logow", nullptr));
        clearMonitorButton->setText(QApplication::translate("MainWindow", "Wyczysc", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Sterowanie sliderami", nullptr));
        sliderDirectionLabel->setText(QApplication::translate("MainWindow", "Przod/tyl", nullptr));
        turningSliderLabel->setText(QApplication::translate("MainWindow", "Skrecanie", nullptr));
        frontRadarLabel->setText(QApplication::translate("MainWindow", "Przod", nullptr));
        rearRadaerLabel->setText(QApplication::translate("MainWindow", "Tyl", nullptr));
        cmLabel->setText(QApplication::translate("MainWindow", "cm", nullptr));
        cmLabel_2->setText(QApplication::translate("MainWindow", "cm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
