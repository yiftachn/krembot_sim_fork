#ifndef KREMBOT_BRIDGE_H
#define KREMBOT_BRIDGE_H



#include <argos3/core/control_interface/ci_controller.h>
/* Definition of the differential steering actuator */
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
/* Definition of the foot-bot proximity sensor */
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>
#include <argos3/core/utility/math/vector2.h>
#include "mobile_base.h"
#include "rgba_sensor.h"
#include "rgb_led.h"

/*
 * All the ARGoS stuff in the 'argos' namespace.
 * With this statement, you save typing argos:: every time.
 */
using namespace argos;


class Krembot {

private:

    void test() {
        //todo: implement tests of all components here
    }

public:

    RGBASensor RgbaFront;
    RGBASensor RgbaRear;
    RGBASensor RgbaRight;
    RGBASensor RgbaLeft;
    RGBASensor RgbaFrontRight;
    RGBASensor RgbaFrontLeft;
    RGBASensor RgbaRearRight;
    RGBASensor RgbaRearLeft;

    MobileBase Base;
//    CBumpers Bumpers;
//    Battery Bat;
    RGBLed Led;
//    IMUSensor Imu;
    Krembot(CCI_DifferentialSteeringActuator& wheels,
            CCI_FootBotProximitySensor& proximity,
            CCI_LEDsActuator & leds)  :
            Base(wheels),
            RgbaFront("RgbaFront", 0, proximity),
            RgbaFrontRight("RgbaFrontRight", 1, proximity),
            RgbaRight("RgbaRight", 2, proximity),
            RgbaRearRight("RgbaRearRight", 3, proximity),
            RgbaRear("RgbaRear", 4,  proximity),
            RgbaRearLeft("RgbaRearLeft", 5, proximity),
            RgbaLeft("RgbaLeft", 6, proximity),
            RgbaFrontLeft("RgbaFrontLeft", 7, proximity),
            Led(leds)
    {

    }

    
    void setup() {
        Led.write(0,255,0);
    }


    void loop() {


    }
};

#endif