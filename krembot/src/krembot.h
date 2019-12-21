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

    void test();

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
            CCI_FootBotImuSensor & imu);

    void setup();

    void loop();

    /*
     * Simulated ID. This function assumes that each robot have a unique name.
     * The hash of the name's string is calculated to produce the ID
     */
    std::string getId();

    /*
     * Simulated name. This name is read from the .argos config file
     */
    inline std::string getName() { return m_name; }

    inline bool have_name() { return m_name.length() > 0; }
};

#endif