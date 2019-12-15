#include "DriveModule.h"
#include <limits>
#include <pigpiod_if2.h>

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

void DriveModule::calculateSpeedForSliderMode(int directionValue, int turnValue)
{
    if (sgn(directionValue)>=0){
        speedLevelLeftTrue = MAX_CAR_SPEED*(directionValue + turnValue)/100;
        speedLevelRightTrue = MAX_CAR_SPEED*(directionValue - turnValue)/100;
        if (speedLevelLeftTrue > MAX_CAR_SPEED) speedLevelLeftTrue = MAX_CAR_SPEED;
        if (speedLevelRightTrue > MAX_CAR_SPEED) speedLevelRightTrue = MAX_CAR_SPEED;
    }
    else if (sgn(directionValue) < 0) {
        speedLevelLeftTrue = MAX_CAR_SPEED*(directionValue - turnValue)/100;
        speedLevelRightTrue = MAX_CAR_SPEED*(directionValue + turnValue)/100;
        if (speedLevelLeftTrue < -MAX_CAR_SPEED) speedLevelLeftTrue = -MAX_CAR_SPEED;
        if (speedLevelRightTrue < -MAX_CAR_SPEED) speedLevelRightTrue = -MAX_CAR_SPEED;
    }
    // otrzymuje zakres -255 do 255, nalezy teraz pamietac ze -255 nie mozna podac na pwm
    setDrivePins();
}

void DriveModule::setDrivePins()
{
    if (speedLevelLeftTrue <0){
        gpio_write(pigpioHost, inLeft1, 1);
        gpio_write(pigpioHost, inLeft2, 0);
        speedLevelLeft = -1*speedLevelLeftTrue;
    } else {
        gpio_write(pigpioHost, inLeft1, 0);
        gpio_write(pigpioHost, inLeft2, 1);
        speedLevelLeft = speedLevelLeftTrue;
    }
    if (speedLevelRightTrue <0){
        gpio_write(pigpioHost, inRight3, 0);
        gpio_write(pigpioHost, inRight4, 1);
        speedLevelRight = -1*speedLevelRightTrue;
    } else {
        gpio_write(pigpioHost, inRight3, 1);
        gpio_write(pigpioHost, inRight4, 0);
        speedLevelRight = speedLevelRightTrue;
    }
    updatePWM();
}

void DriveModule::updatePWM()
{
   // speed level i trun speed sa ustawiane na sliderach
    set_PWM_dutycycle(pigpioHost, pwmLeft, speedLevelLeft);
    set_PWM_dutycycle(pigpioHost, pwmRight, speedLevelRight);
}

void DriveModule::calculateSpeedForButtonsMode()
{
    // LEFT SIDE
    if (side == -1){
        speedLevelLeft = turnSpeed;
        speedLevelRight = turnSpeed;
    }
    else if (side == 0){
        speedLevelLeft = speedLevel;
        speedLevelRight = speedLevel;
    }
    else if (side == 1){
        speedLevelLeft = turnSpeed;
        speedLevelRight = turnSpeed;
    }
    updatePWM();
}


void DriveModule::driveForward()
{
    // Set In pins to proper levels
    side = 0;
    calculateSpeedForButtonsMode();
    gpio_write(pigpioHost, inLeft1, 0);
    gpio_write(pigpioHost, inLeft2, 1);

    gpio_write(pigpioHost, inRight3, 1);
    gpio_write(pigpioHost, inRight4, 0);
}

void DriveModule::driveBackward()
{
    // Set In pins to proper levels
    side = 0;
    calculateSpeedForButtonsMode();
    gpio_write(pigpioHost, inLeft1, 1);
    gpio_write(pigpioHost, inLeft2, 0);

    gpio_write(pigpioHost, inRight3, 0);
    gpio_write(pigpioHost, inRight4, 1);
}

void DriveModule::turnLeft()
{
    // Set In pins to proper levels
    side = -1;
    calculateSpeedForButtonsMode();

    gpio_write(pigpioHost, inLeft1, 1);
    gpio_write(pigpioHost, inLeft2, 0);

    gpio_write(pigpioHost, inRight3, 1);
    gpio_write(pigpioHost, inRight4, 0);

}

void DriveModule::turnRight()
{
    // Set In pins to proper levels
    side = 1;
    calculateSpeedForButtonsMode();

    gpio_write(pigpioHost, inLeft1, 0);
    gpio_write(pigpioHost, inLeft2, 1);

    gpio_write(pigpioHost, inRight3, 0);
    gpio_write(pigpioHost, inRight4, 1);
}

void DriveModule::stopCar()
{
    speedLevelLeft = 0;
    speedLevelRight = 0;
    updatePWM();

    gpio_write(pigpioHost, inLeft1, 0);
    gpio_write(pigpioHost, inLeft2, 0);

    gpio_write(pigpioHost, inRight3, 0);
    gpio_write(pigpioHost, inRight4, 0);

}


void DriveModule::emergencyStop()
{
    speedLevelLeft = 0;
    speedLevelRight = 0;
    updatePWM();
    gpio_write(pigpioHost, inLeft1, 1);
    gpio_write(pigpioHost, inLeft2, 1);

    gpio_write(pigpioHost, inRight3, 1);
    gpio_write(pigpioHost, inRight4, 1);

    time_sleep(0.4);

    gpio_write(pigpioHost, inLeft1, 0);
    gpio_write(pigpioHost, inLeft2, 0);

    gpio_write(pigpioHost, inRight3, 0);
    gpio_write(pigpioHost, inRight4, 0);
}

bool DriveModule::getErrorFlag() {
    return errorFlag;
}

void DriveModule::setErrorFlag()
{
    errorFlag = 1;
}

void DriveModule::speedUp()
{
    speedLevel++;
}

void DriveModule::speedDown()
{
    speedLevel--;
}

DriveModule::DriveModule(int pigpioHost)
{
//    pigpioHost = pigpio_start(NULL, NULL);
    if (pigpioHost < 0)
    {
        errorFlag = 1;
        // add in communication to parent

    }
    else
    {
        // pigpio initialised okay.
        this->pigpioHost = pigpioHost;

        set_PWM_dutycycle(pigpioHost, pwmLeft, speedLevel);
        set_PWM_dutycycle(pigpioHost, pwmRight, speedLevel);

        set_mode(pigpioHost, inLeft2, PI_OUTPUT); //in 1
        set_mode(pigpioHost, inLeft1, PI_OUTPUT); //in 2

        set_mode(pigpioHost, inRight3, PI_OUTPUT); // in3
        set_mode(pigpioHost, inRight4, PI_OUTPUT); // in4

    }
}

DriveModule::~DriveModule()
{
    gpio_write(pigpioHost, inLeft1, 0);
    gpio_write(pigpioHost, inLeft2, 0);

    gpio_write(pigpioHost, inRight3, 0);
    gpio_write(pigpioHost, inRight4, 0);
}

void DriveModule::setPigpioHost(int pigpioHost)
{
    this->pigpioHost = pigpioHost;
}

void DriveModule::updatePins()
{
    set_PWM_dutycycle(pigpioHost, pwmLeft, speedLevel);
    set_PWM_dutycycle(pigpioHost, pwmRight, speedLevel);

    set_mode(pigpioHost, inLeft2, PI_OUTPUT); //in 1
    set_mode(pigpioHost, inLeft1, PI_OUTPUT); //in 2

    set_mode(pigpioHost, inRight3, PI_OUTPUT); // in3
    set_mode(pigpioHost, inRight4, PI_OUTPUT); // in4

}

// Setting the pins to control L298N brigde
void DriveModule::setMotorPins(unsigned char pwmLeft, unsigned char pwmRight, unsigned char inLeft1, unsigned char inLeft2, unsigned char inRight3, unsigned char inRight4)
{
    this->pwmLeft = pwmLeft;
    this->pwmRight = pwmRight;
    this->inLeft1 = inLeft1;
    this->inLeft2 = inLeft2;
    this->inRight3 = inRight3;
    this->inRight4 = inRight4;
    updatePins();
}
