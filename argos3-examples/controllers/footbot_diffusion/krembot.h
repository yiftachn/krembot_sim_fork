#ifndef KREMBOT_BRIDGE_H
#define KREMBOT_BRIDGE_H


#include <tr1/functional>
#include <string>

#include <argos3/core/control_interface/ci_controller.h>
/* Definition of the differential steering actuator */
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
/* Definition of the foot-bot proximity sensor */
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>
/* Definition of the omnidirectional camera sensor */
#include <argos3/plugins/robots/generic/control_interface/ci_colored_blob_omnidirectional_camera_sensor.h>
/* Definition of the foot-bot light sensor */
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_light_sensor.h>
/* Definition of the foot-bot imu sensor */
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_imu_sensor.h>


#include <argos3/core/utility/math/vector2.h>
#include "mobile_base.h"
#include "rgba_sensor.h"
#include "rgb_led.h"
#include "cbumpers.h"
#include "battery.h"
#include "imu_sensor.h"

/*
 * All the ARGoS stuff in the 'argos' namespace.
 * With this statement, you save typing argos:: every time.
 */
using namespace argos;


class Krembot {

private:

    std::string m_name = "";

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
    CBumpers Bumpers;
    Battery Bat;
    RGBLed Led;
    IMUSensor Imu;

    Krembot(const std::string & id,
            CCI_DifferentialSteeringActuator& wheels,
            CCI_FootBotProximitySensor& proximity,
            CCI_LEDsActuator & leds,
            CCI_FootBotLightSensor & light,
            CCI_ColoredBlobOmnidirectionalCameraSensor & colorCam,
            CCI_FootBotImuSensor & imu)  :
            m_name(id),
            Base(wheels),
            Bumpers(proximity),
            Imu(imu),
            RgbaFront("RgbaFront", 0, proximity, light, colorCam),
            RgbaFrontLeft("RgbaFrontLeft", 1, proximity, light, colorCam),
            RgbaLeft("RgbaLeft", 2, proximity, light, colorCam),
            RgbaRearLeft("RgbaRearLeft", 3, proximity, light, colorCam),
            RgbaRear("RgbaRear", 4,  proximity, light, colorCam),
            RgbaRearRight("RgbaRearRight", 5, proximity, light, colorCam),
            RgbaRight("RgbaRight", 6, proximity, light, colorCam),
            RgbaFrontRight("RgbaFrontRight", 7, proximity, light, colorCam),


            Led(leds)
    {

    }

    std::string getId() {
        return std::to_string(std::tr1::hash<std::string>()(m_name));
    }

    inline std::string getName() {
        return m_name;
    }

    bool have_name() {
        return m_name.length() > 0;
    }

    
    void setup() {
        Led.write(0,255,0);
    }


    void loop() {

        std::cout << "---" << getName() << "---" << std::endl;

        std::cout << "y: " << Imu.read().yaw;
//        Bat.print();


//        Bumpers.read();
//        Bumpers.print();


         //RgbaFront.readRGBA() ;

//         std::cout << "[" << getName() << ", 0] " << RgbaFront.readRGBA().Ambient << " " << RgbaFront.readRGBA().Proximity << "{r:" << RgbaFront.readRGBA().Red<< " g:" << RgbaFront.readRGBA().Green<< " b:" << RgbaFront.readRGBA().Blue<< "}"<< std::endl;
//        std::cout << "[" << getName() << ", 1] " << RgbaFrontLeft.readRGBA().Ambient  << " " << RgbaFrontLeft.readRGBA().Proximity << "{r:" << RgbaFrontLeft.readRGBA().Red<< " g:" << RgbaFrontLeft.readRGBA().Green<< " b:" << RgbaFrontLeft.readRGBA().Blue<< "}" << std::endl;
//        std::cout << "[" << getName() << ", 2] " << RgbaLeft.readRGBA().Ambient  << " " << RgbaLeft.readRGBA().Proximity << "{r:" << RgbaLeft.readRGBA().Red<< " g:" << RgbaLeft.readRGBA().Green<< " b:" << RgbaLeft.readRGBA().Blue<< "}" << std::endl;
//        std::cout << "[" << getName() << ", 3] " << RgbaRearLeft.readRGBA().Ambient  << " " << RgbaRearLeft.readRGBA().Proximity << "{r:" << RgbaRearLeft.readRGBA().Red<< " g:" << RgbaRearLeft.readRGBA().Green<< " b:" << RgbaRearLeft.readRGBA().Blue<< "}" << std::endl;
//        std::cout << "[" << getName() << ", 4] " << RgbaRear.readRGBA().Ambient  << " " << RgbaRear.readRGBA().Proximity << "{r:" << RgbaRear.readRGBA().Red<< " g:" << RgbaRear.readRGBA().Green<< " b:" << RgbaRear.readRGBA().Blue<< "}" << std::endl;
//        std::cout << "[" << getName() << ", 5] " << RgbaRearRight.readRGBA().Ambient  << " " << RgbaRearRight.readRGBA().Proximity << "{r:" << RgbaRearRight.readRGBA().Red<< " g:" << RgbaRearRight.readRGBA().Green<< " b:" << RgbaRearRight.readRGBA().Blue<< "}" << std::endl;
//        std::cout << "[" << getName() << ", 6] " << RgbaRight.readRGBA().Ambient  << " " << RgbaRight.readRGBA().Proximity << "{r:" << RgbaRight.readRGBA().Red<< " g:" << RgbaRight.readRGBA().Green<< " b:" << RgbaRight.readRGBA().Blue<< "}" << std::endl;
//        std::cout << "[" << getName() << ", 7] " << RgbaFrontRight.readRGBA().Ambient  << " " << RgbaFrontRight.readRGBA().Proximity << "{r:" << RgbaFrontRight.readRGBA().Red<< " g:" << RgbaFrontRight.readRGBA().Green<< " b:" << RgbaFrontRight.readRGBA().Blue<< "}" << std::endl;


    }
};

#endif