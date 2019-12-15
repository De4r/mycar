#ifndef DRIVEMODULE_H
#define DRIVEMODULE_H

#include <iostream>
#include <pigpiod_if2.h>
#include <stdio.h>

using namespace std;

class DriveModule
{
private:

    int MAX_CAR_SPEED = 255;
    // Motor pins

    unsigned char pwmLeft = 22;
    unsigned char pwmRight = 18;
    unsigned char inLeft1 = 27;
    unsigned char inLeft2 = 17;
    unsigned char inRight3 = 14;
    unsigned char inRight4 = 15;

    // Flags
    bool errorFlag = 0;
    bool collisionFlag = 0;
    void updatePins();

    int pigpioHost = 0;
    const short buttonsMode = 1;
    const short slidersMode = 2;



public:
    DriveModule(int pigpioHost);
    ~DriveModule();
    void setPigpioHost(int pigpioHost);
    int speedLevel = 0; // for standard movement mode
    int turnSpeed = 0;
    int side = 0;
    int drivingMode = 1; // mode 1 - buttons, 2 - sliders, 3 - klawiatura

    int speedLevelLeft = 0; // for movement with calculateSpeed
    int speedLevelRight = 0;
    int speedLevelRightTrue = 0;
    int speedLevelLeftTrue = 0;

    bool getErrorFlag();
    void setErrorFlag();


    void driveForward();
    void driveBackward();
    void turnLeft();
    void turnRight();
    void stopCar();
    void calculateSpeedForButtonsMode();

    void updatePWM();
    void speedUp();
    void speedDown();
    void emergencyStop();

    void setMotorPins(unsigned char pwmLeft, unsigned char pwmRight, unsigned char inLeft1, unsigned char inLeft2, unsigned char inRight3, unsigned char inRight4);

    void calculateSpeedForSliderMode(int directionValue, int turnValue);
    void setDrivePins();


};

#endif // DRIVEMODULE_H
