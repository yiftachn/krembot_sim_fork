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

#include "src/krembot.h"


Krembot::Krembot(SerialSim &serial)  :
        Serial {serial},
        RgbaFront {serial},
        RgbaRear{serial},
        RgbaRight{serial},
        RgbaLeft{serial},
        RgbaFrontRight{serial},
        RgbaFrontLeft{serial},
        RgbaRearRight{serial},
        RgbaRearLeft{serial},
        Bumpers{serial},
        Bat{serial},
        Imu{serial},
        Base{serial}
{

}
void Krembot::init(const std::string & id,
          CCI_DifferentialSteeringActuator * wheels,
          CCI_FootBotProximitySensor * proximity,
          CCI_LEDsActuator * leds,
          CCI_FootBotLightSensor * light,
          CCI_ColoredBlobOmnidirectionalCameraSensor * colorCam,
          CCI_FootBotImuSensor * imu)
{
    m_name = id;
    Base.init(wheels);
    Bumpers.init(proximity);
    Imu.init(imu);
    Led.init(leds);
    RgbaFront.init("RgbaFront", 0, proximity, light, colorCam);
    RgbaFrontLeft.init("RgbaFrontLeft", 1, proximity, light, colorCam);
    RgbaLeft.init("RgbaLeft", 2, proximity, light, colorCam);
    RgbaRearLeft.init("RgbaRearLeft", 3, proximity, light, colorCam);
    RgbaRear.init("RgbaRear", 4,  proximity, light, colorCam);
    RgbaRearRight.init("RgbaRearRight", 5, proximity, light, colorCam);
    RgbaRight.init("RgbaRight", 6, proximity, light, colorCam);
    RgbaFrontRight.init("RgbaFrontRight", 7, proximity, light, colorCam);

    m_initialized = true;
}

std::string Krembot::getId() {
    return std::to_string(std::tr1::hash<std::string>()(m_name));
}


