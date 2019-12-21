/*******************************************************************************
* Copyright (c) 2019, Elhay Rauper.
* All rights reserved.
*
* This code API is based on Robotican's Krembot library, which can be found here:
 * https://github.com/robotican/krembot
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* * Redistributions of source code must retain the above copyright notice, this
*   list of conditions and the following disclaimer.
*
* * Redistributions in binary form must reproduce the above copyright notice,
*   this list of conditions and the following disclaimer in the documentation
*   and/or other materials provided with the distribution.
*
* * Neither the name of Elhay Rauper nor the names of its
*   contributors may be used to endorse or promote products derived from
*   this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#ifndef FOOTBOT_DIFFUSION_RGBA_SENSOR_H
#define FOOTBOT_DIFFUSION_RGBA_SENSOR_H


#include <stdint.h>
#include <string>

#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>
#include <argos3/plugins/robots/generic/control_interface/ci_colored_blob_omnidirectional_camera_sensor.h>
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_light_sensor.h>


/* RGBA sensor location and ID number:
 *
 *           0
 *        1     7
 *      2         6
 *        3     5
 *           4
 */


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

    argos::CRange<argos::CRadians> m_ColorSensorAngularRange;
    argos::CCI_FootBotProximitySensor & m_cProximity;
    argos::CCI_FootBotLightSensor & m_Light;
    argos::CCI_ColoredBlobOmnidirectionalCameraSensor & m_ColorCam;
    argos::CRange<float> m_ProxRange;
    argos::CRange<float> m_DistRange;

    enum class ProxState {
        NEAR,
        FAR
    };

    ProxState m_ProxState {ProxState::FAR};


public:

    RGBASensor(const std::string name,
               uint8_t index,
               argos::CCI_FootBotProximitySensor & proximity,
               argos::CCI_FootBotLightSensor & light,
               argos::CCI_ColoredBlobOmnidirectionalCameraSensor & colorCam);

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
