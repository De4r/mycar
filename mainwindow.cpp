#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->pigpioHost = pigpio_start(NULL, NULL);
        if (pigpioHost < 0)
        {
            errorFlag = 1;
            ui->logsMonitor->append("FAILED TO CREATE PIGPIO DEAMON HOST!");

        }
        else
        {
        ui->logsMonitor->append("Started pigpio deamon host: " + QString::number(pigpioHost));
        sensorsModule = new SensorsModule(pigpioHost);
        this->errorFlagSens = sensorsModule->getErrorFlag();
        driveModule = new DriveModule(pigpioHost);
        this->errorFlagDrive = driveModule->getErrorFlag();
        }
        if (errorFlag || errorFlagSens || errorFlagDrive){
            ui->logsMonitor->append("Error ocurred");
            ui->logsMonitor->append("Flags: UI:" + QString::number(errorFlag)
                                    + " Sens: " + QString::number(errorFlagSens) +
                                    " Drive: " + QString::number(errorFlagDrive));
        }
        ui->buttonsMode->setChecked(1);

        ui->keyboardMode->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete driveModule;
    delete sensorsModule;
    delete ui;
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Space)
        {
            this->on_stopButton_clicked();
        }
        else if (keyEvent->key() == Qt::Key_W)
        {
            ui->directionSlider->setValue(ui->directionSlider->value()+1);
        }
        return true;
    } else {
        return QMainWindow::eventFilter(watched, event);
    }
}


void MainWindow::on_clearMonitorButton_clicked()
{
    ui->logsMonitor->clear();
}

void MainWindow::addToLogs(QString message)
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    ui->logsMonitor->append(currentDateTime + "\t" + message);
}

void MainWindow::on_directionSlider_valueChanged(int value)
{
    if (ui->slidersMode->isChecked() || ui->keyboardMode->isChecked()){
        int directionValue = ui->directionSlider->value();
        int turnValue = ui->turningSlider_2->value();
        this->driveModule->calculateSpeedForSliderMode(directionValue, turnValue);
        ui->leftSpeedIndicator->display(driveModule->speedLevelLeftTrue);
        ui->rightSpeedIndicator->display(driveModule->speedLevelRightTrue);
    }
    else {
        QString message = "Erorr at on_directionSlider_valueChanged";
        this->addToLogs(message);
    }
}

void MainWindow::on_directionSlider_sliderReleased()
{
    if (ui->slidersMode->isChecked() || ui->keyboardMode->isChecked()){
    QString message = "Driving SliderMode | L: " + QString::number(driveModule->speedLevelLeftTrue)
            + " R: " + QString::number(driveModule->speedLevelRightTrue);
    this->addToLogs(message);
    } else {
        QString message = "Erorr at on_directionSlider_sliderReleased";
        this->addToLogs(message);
    }
}

void MainWindow::on_turningSlider_2_valueChanged(int value)
{
    if (ui->slidersMode->isChecked() || ui->keyboardMode->isChecked()){
        int directionValue = ui->directionSlider->value();
        int turnValue = ui->turningSlider_2->value();
        this->driveModule->calculateSpeedForSliderMode(directionValue, turnValue);
        ui->leftSpeedIndicator->display(driveModule->speedLevelLeftTrue);
        ui->rightSpeedIndicator->display(driveModule->speedLevelRightTrue);
    }
    else {
        QString message = "Erorr at on_turningSlider_2_valueChanged";
        this->addToLogs(message);
    }
}

void MainWindow::on_turningSlider_2_sliderReleased()
{
    if (ui->slidersMode->isChecked() || ui->keyboardMode->isChecked()){
    QString message = "Driving SliderMode | L: " + QString::number(driveModule->speedLevelLeftTrue)
            + " R: " + QString::number(driveModule->speedLevelRightTrue);
    this->addToLogs(message);
    } else {
        QString message = "Erorr at on_turningSlider_2_sliderReleased";
        this->addToLogs(message);
    }
}

void MainWindow::on_stopButton_clicked()
{
    this->driveModule->stopCar();
    QString message = "STOPING...";
    this->addToLogs(message);
}

void MainWindow::on_buttonsMode_clicked(bool checked)
{
    if (checked){
        QString message = "Changed mode to 1: BUTTONS MODE ON!";
        this->addToLogs(message);
    }
}

void MainWindow::on_slidersMode_clicked(bool checked)
{
    if (checked){
        QString message = "Changed mode to 2: SLIDERS MODE ON!";
        this->addToLogs(message);
    }
}

void MainWindow::on_keyboardMode_clicked(bool checked)
{
    if (checked){
        QString message = "Changed mode to 3: KEYBOARD MODE ON!";
        this->addToLogs(message);
    }
}

void MainWindow::on_driveForawrdButton_pressed()
{
    if (ui->buttonsMode->isChecked()){
        this->driveModule->driveForward();
        QString message ="Driving ButtonsMode | FORWARD";
        this->addToLogs(message);
    }
    else {
        QString message = "on_driveForawrdButton_pressed";
        this->addToLogs(message);
    }
}


void MainWindow::on_driveBackwardButton_pressed()
{
    if (ui->buttonsMode->isChecked()){
        this->driveModule->driveBackward();
        QString message ="Driving ButtonsMode | BACKWARD";
        this->addToLogs(message);
    }
    else {
        QString message = "on_driveBackwardButton_pressed";
        this->addToLogs(message);
    }
}


void MainWindow::on_driveLeftButton_pressed()
{
    if (ui->buttonsMode->isChecked()){
        this->driveModule->turnLeft();
        QString message ="Driving ButtonsMode | TURNING LEFT";
        this->addToLogs(message);
    }
    else {
        QString message = "on_driveLeftButton_pressed";
        this->addToLogs(message);
    }
}

void MainWindow::on_driveRightButton_pressed()
{
    if (ui->buttonsMode->isChecked()){
        this->driveModule->turnRight();
        QString message ="Driving ButtonsMode | TURNING RIGHT";
        this->addToLogs(message);
    }
    else {
        QString message = "on_driveRightButton_pressed";
        this->addToLogs(message);
    }
}



void MainWindow::on_speedSlider_valueChanged(int value)
{
    if (ui->buttonsMode->isChecked()){
        this->driveModule->speedLevel = value;
        this->driveModule->calculateSpeedForButtonsMode();
    }
    else {
        QString message = "Erorr at on_speedSlider_valueChanged";
        this->addToLogs(message);
    }
}

void MainWindow::on_speedSlider_sliderReleased()
{
    if (ui->buttonsMode->isChecked()){
        QString message ="Driving ButtonsMode | speedLevel: "
                + QString::number(this->driveModule->speedLevel);
        this->addToLogs(message);
    }
    else {
        QString message = "Erorr at on_speedSlider_sliderReleased";
        this->addToLogs(message);
    }
}

void MainWindow::on_turningSlider_valueChanged(int value)
{
    if (ui->buttonsMode->isChecked()){
        this->driveModule->turnSpeed = value;
        this->driveModule->calculateSpeedForButtonsMode();
    }
    else {
        QString message = "Erorr at on_turningSlider_valueChanged";
        this->addToLogs(message);
    }
}

void MainWindow::on_turningSlider_sliderReleased()
{
    if (ui->buttonsMode->isChecked()){
        QString message ="Driving ButtonsMode | turnSpeed: "
                + QString::number(this->driveModule->turnSpeed);
        this->addToLogs(message);
    }
    else {
        QString message = "Erorr at on_turningSlider_sliderReleased";
        this->addToLogs(message);
    }
}






