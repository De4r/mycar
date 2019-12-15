#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <pigpiod_if2.h>
#include <stdio.h>
#include <QString>
#include "QObject"
#include "DriveModule.h"
#include <QDateTime>
#include <QTimer>
#include "SensorsModule.h"
#include <QKeyEvent>
#include <QEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    DriveModule* driveModule;
    SensorsModule* sensorsModule;

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void on_clearMonitorButton_clicked();

    void on_directionSlider_valueChanged(int value);

    void on_turningSlider_2_valueChanged(int value);

    void on_stopButton_clicked();

    void on_buttonsMode_clicked(bool checked);

    void on_slidersMode_clicked(bool checked);

    void on_driveForawrdButton_pressed();

    void on_turningSlider_valueChanged(int value);

    void on_speedSlider_valueChanged(int value);

    void on_driveBackwardButton_pressed();

    void on_driveLeftButton_pressed();

    void on_driveRightButton_pressed();

    void on_speedSlider_sliderReleased();

    void on_turningSlider_sliderReleased();

    void on_directionSlider_sliderReleased();

    void on_turningSlider_2_sliderReleased();

    void on_keyboardMode_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    void addToLogs(QString message);
    int pigpioHost = 0;
    bool errorFlag = 0;
    bool errorFlagSens = 0;
    bool errorFlagDrive = 0;

};
#endif // MAINWINDOW_H
