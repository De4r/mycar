#include "SensorsModule.h"

SensorsModule::SensorsModule(int pigpioHost)
{
    if (pigpioHost < 0)
    {
        errorFlag = 1;
        // add in logs monitor

    }
    else
    {
        // pigpio initialised okay.
        this->pigpioHost = pigpioHost;

        set_mode(pigpioHost, rearTrig, PI_OUTPUT);
        set_mode(pigpioHost, frontTrig, PI_OUTPUT);

        set_mode(pigpioHost, rearEcho, PI_INPUT);
        set_pull_up_down(pigpioHost, rearEcho, PI_PUD_UP);

        set_mode(pigpioHost, frontEcho, PI_INPUT);
        set_pull_up_down(pigpioHost, frontEcho, PI_PUD_UP);

        set_mode(pigpioHost, rearLeftInfra, PI_INPUT);
        set_mode(pigpioHost, frontLeftInfra, PI_INPUT);
        set_mode(pigpioHost, rearRightInfra, PI_INPUT);
        set_mode(pigpioHost, frontRightInfra, PI_INPUT);

        set_pull_up_down(pigpioHost, rearLeftInfra, PI_PUD_UP);
        set_pull_up_down(pigpioHost, frontLeftInfra, PI_PUD_UP);
        set_pull_up_down(pigpioHost, rearRightInfra, PI_PUD_UP);
        set_pull_up_down(pigpioHost, frontRightInfra, PI_PUD_UP);
//        callback(pi, rearLeftInfra, 0, setErrorFlag());
//        callback(pi, leftLeftInfra, 0, setErrorFlag());
//        callback(pi, frontLeftInfra, 0, setErrorFlag());
//        callback(pi, rearLeftInfra, 0, setErrorFlag());


        set_mode(pigpioHost, leftEncoder, PI_INPUT);
        set_mode(pigpioHost, rightEncoder, PI_INPUT);
        set_pull_up_down(pigpioHost, leftEncoder, PI_PUD_UP);
        set_pull_up_down(pigpioHost, rightEncoder, PI_PUD_UP);
    }
}

SensorsModule::~SensorsModule()
{

}

void SensorsModule::setPigpioHost(int pigpioHost)
{
    this->pigpioHost = pigpioHost;
}

bool SensorsModule::getErrorFlag() {
    return errorFlag;
}

void SensorsModule::setErrorFlag()
{
    errorFlag = 1;
}

void SensorsModule::updatePins()
{

    set_mode(pigpioHost, rearTrig, PI_OUTPUT);
    set_mode(pigpioHost, frontTrig, PI_OUTPUT);

    set_mode(pigpioHost, rearEcho, PI_INPUT);
    set_pull_up_down(pigpioHost, rearEcho, PI_PUD_UP);

    set_mode(pigpioHost, frontEcho, PI_INPUT);
    set_pull_up_down(pigpioHost, frontEcho, PI_PUD_UP);

    set_mode(pigpioHost,rearLeftInfra, PI_INPUT);
    set_mode(pigpioHost, frontLeftInfra, PI_INPUT);
    set_mode(pigpioHost, rearRightInfra, PI_INPUT);
    set_mode(pigpioHost, frontRightInfra, PI_INPUT);

    set_pull_up_down(pigpioHost, rearLeftInfra, PI_PUD_UP);
    set_pull_up_down(pigpioHost, frontLeftInfra, PI_PUD_UP);
    set_pull_up_down(pigpioHost, rearRightInfra, PI_PUD_UP);
    set_pull_up_down(pigpioHost, frontRightInfra, PI_PUD_UP);


    set_mode(pigpioHost, leftEncoder, PI_INPUT);
    set_mode(pigpioHost, rightEncoder, PI_INPUT);
    set_pull_up_down(pigpioHost, leftEncoder, PI_PUD_UP);
    set_pull_up_down(pigpioHost, rightEncoder, PI_PUD_UP);
}

// Setting the pins to control Sonars (rear and front)
void SensorsModule::setSonarPins(unsigned char rearTrig, unsigned char frontTrig, unsigned char rearEcho, unsigned char frontEcho)
{
    this->rearTrig = rearTrig;
    this->frontTrig = frontTrig;
    this->rearEcho = rearEcho;
    this->frontEcho = frontEcho;
    updatePins();
}

// Setting the pins of input of Infra Red sensors (collision in corners)
void SensorsModule::setInfraSensorPins(unsigned char rearLeftInfra, unsigned char rearRightInfra, unsigned char frontLeftInfra, unsigned char frontRightInfra)
{
    this->rearLeftInfra = rearLeftInfra;
    this->rearRightInfra = rearRightInfra;
    this->frontLeftInfra = frontLeftInfra;
    this->frontRightInfra = frontRightInfra;
    updatePins();
}

// Setting the pins of encoders (the IR interupt encoders)
void SensorsModule::setEncoderPins(unsigned char leftEncoder, unsigned char rightEncoder)
{
    this->leftEncoder = leftEncoder;
    this->rightEncoder = rightEncoder;
    updatePins();
}
