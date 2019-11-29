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

/*
 * All the ARGoS stuff in the 'argos' namespace.
 * With this statement, you save typing argos:: every time.
 */
using namespace argos;


class Krembot {

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
//    RGBLed Led;
//    IMUSensor Imu;
    CCI_FootBotProximitySensor& proximity;
    Krembot(CCI_DifferentialSteeringActuator& wheels,
            CCI_FootBotProximitySensor& proximity)  :
            proximity(proximity),
            Base(wheels),
            RgbaFront("RgbaFront", proximity.GetReadings()[0]),
            RgbaFrontRight("RgbaFrontRight", proximity.GetReadings()[1]),
            RgbaRight("RgbaRight", proximity.GetReadings()[2]),
            RgbaRearRight("RgbaRearRight", proximity.GetReadings()[3]),
            RgbaRear("RgbaRear", proximity.GetReadings()[4]),
            RgbaRearLeft("RgbaRearLeft", proximity.GetReadings()[5]),
            RgbaLeft("RgbaLeft", proximity.GetReadings()[6]),
            RgbaFrontLeft("RgbaFrontLeft", proximity.GetReadings()[7])
    {

    }

    
    void setup() {

    }


    void loop() {

        std::cout << RgbaFront.readRGBA().Proximity << "| " << proximity.GetReadings()[0].Value << std::endl;
    }
};

#endif