#ifndef KREMBOT_BRIDGE_H
#define KREMBOT_BRIDGE_H



#include <argos3/core/control_interface/ci_controller.h>
/* Definition of the differential steering actuator */
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
/* Definition of the foot-bot proximity sensor */
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>
/* Definition of the omnidirectional camera sensor */
#include <argos3/plugins/robots/generic/control_interface/ci_colored_blob_omnidirectional_camera_sensor.h>
/* Definition of the foot-bot light sensor */
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_light_sensor.h>
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

    //todo: add distance and light sensor to RGBASensor
    RGBASensor RgbaFront;
    RGBASensor RgbaRear;
    RGBASensor RgbaRight;
    RGBASensor RgbaLeft;
    RGBASensor RgbaFrontRight;
    RGBASensor RgbaFrontLeft;
    RGBASensor RgbaRearRight;
    RGBASensor RgbaRearLeft;

    MobileBase Base; // done
//    CBumpers Bumpers; // todo: simulate bumpers with prox sensor
//    Battery Bat;
    RGBLed Led; // dont
//    IMUSensor Imu;
    Krembot(CCI_DifferentialSteeringActuator& wheels,
            CCI_FootBotProximitySensor& proximity,
            CCI_LEDsActuator & leds,
            CCI_FootBotLightSensor & light,
            CCI_ColoredBlobOmnidirectionalCameraSensor & colorCam)  :
            Base(wheels),
            RgbaFront("RgbaFront", 0, proximity, light, colorCam),
            RgbaFrontRight("RgbaFrontRight", 1, proximity, light, colorCam),
            RgbaRight("RgbaRight", 2, proximity, light, colorCam),
            RgbaRearRight("RgbaRearRight", 3, proximity, light, colorCam),
            RgbaRear("RgbaRear", 4,  proximity, light, colorCam),
            RgbaRearLeft("RgbaRearLeft", 5, proximity, light, colorCam),
            RgbaLeft("RgbaLeft", 6, proximity, light, colorCam),
            RgbaFrontLeft("RgbaFrontLeft", 7, proximity, light, colorCam),
            Led(leds)
    {

    }

    
    void setup() {
        Led.write(0,255,0);
    }


    void loop() {

         RgbaFront.readRGBA().Proximity ;


    }
};

#endif