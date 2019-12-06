//
// Created by eli on 11/29/19.
//

#ifndef FOOTBOT_DIFFUSION_RGBA_SENSOR_H
#define FOOTBOT_DIFFUSION_RGBA_SENSOR_H


#include <stdint.h>
#include <string>

#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>
#include <argos3/plugins/robots/generic/control_interface/ci_colored_blob_omnidirectional_camera_sensor.h>
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_light_sensor.h>

enum class RGBAAddr
{
    Front = 0,
    FrontRight = 1,
    Right = 2,
    RearRight = 3,
    Rear = 4,
    RearLeft = 5,
    Left = 6,
    FrontLeft = 7
};

struct RGBAResult
{
    uint16_t Ambient = 0;   /**< The Ambience of the light, (0-65535)*/
    uint16_t Red = 0;       /**< The Red value of the light, (0-65535)*/
    uint16_t Green = 0;     /**< The Green value of the light, (0-65535)*/
    uint16_t Blue = 0;      /**< The Blue value of the light, (0-65535)*/
    uint8_t Proximity = 0;  /**< The Raw value of the proximity sensor, (0-255)*/
    float Distance = 0;     /**< The calculated distance to the object, in cm*/
    bool AmbientError = false;
    bool RedError = false;
    bool GreenError = false;
    bool BlueError = false;
    bool ProximityError = false;
};

struct HSVResult
{
    double H, S, V;
};

enum Colors
{
    Red,
    Green,
    Blue,
    None
};

class RGBASensor
{
private:

    uint8_t m_index = 0;
    std::string m_name = "";

    argos::CCI_FootBotProximitySensor & m_cProximity;
    argos::CCI_FootBotLightSensor & m_Light;
    argos::CCI_ColoredBlobOmnidirectionalCameraSensor & m_ColorCam;


public:
//todo: get colors sensor in ctor
    RGBASensor(const std::string name,
               uint8_t index,
               argos::CCI_FootBotProximitySensor & proximity,
               argos::CCI_FootBotLightSensor & light,
               argos::CCI_ColoredBlobOmnidirectionalCameraSensor & colorCam) :
            m_name(name),
            m_index(index),
            m_cProximity(proximity),
            m_Light(light),
            m_ColorCam(colorCam){};

    inline void init(uint8_t addr) { }

    RGBAResult readRGBA();

    HSVResult readHSV();

    Colors readColor();

    static HSVResult rgbToHSV(RGBAResult in);

    void printRGBA();

    void printHSV();

    void printColor();

    void print();

    inline void publish() { }

};


#endif //FOOTBOT_DIFFUSION_RGBA_SENSOR_H
