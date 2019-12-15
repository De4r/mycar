#ifndef SENSORSMODULE_H
#define SENSORSMODULE_H

#include <QMainWindow>
#include <iostream>
#include <pigpiod_if2.h>
#include <stdio.h>
#include <QString>
#include "QObject"
#include "DriveModule.h"
#include <QDateTime>
#include <QTimer>

using namespace std;

class SensorsModule
{
private:
    // Radar sensors
    unsigned char rearTrig = 26;
    unsigned char frontTrig = 13;
    unsigned char rearEcho = 24;
    unsigned char frontEcho = 5;

    // IR sensors

    unsigned char rearLeftInfra = 16;
    unsigned char rearRightInfra = 9;
    unsigned char frontLeftInfra = 23;
    unsigned char frontRightInfra = 6;

    // Encoders

    unsigned char leftEncoder = 25;
    unsigned char rightEncoder = 10;

    // Flags
    bool errorFlag = 0;
    bool collisionFlag = 0;
    void updatePins();

    int pigpioHost = 0;

public:
    SensorsModule(int pigpioHost);
    ~SensorsModule();
    void setPigpioHost(int pigpioHost);

    bool getErrorFlag();
    void setErrorFlag();

    void setSonarPins(unsigned char rearTrig, unsigned char frontTrig, unsigned char rearEcho, unsigned char frontEcho);
    void setInfraSensorPins(unsigned char rearLeftInfra, unsigned char rearRightInfra, unsigned char frontLeftInfra, unsigned char frontRightInfra);
    void setEncoderPins(unsigned char leftEncoder, unsigned char rightEncoder);



};

#endif // SENSORSMODULE_H
