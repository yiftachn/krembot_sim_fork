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

//Krembot::Krembot(const std::string & id,
//                 CCI_DifferentialSteeringActuator& wheels,
//                 CCI_FootBotProximitySensor& proximity,
//                 CCI_LEDsActuator & leds,
//                 CCI_FootBotLightSensor & light,
//                 CCI_ColoredBlobOmnidirectionalCameraSensor & colorCam,
//                 CCI_FootBotImuSensor & imu)  :
//        m_name(id),
//        Base(wheels),
//        Bumpers(proximity),
//        Imu(imu),
//        Led(leds),
//        RgbaFront("RgbaFront", 0, proximity, light, colorCam),
//        RgbaFrontLeft("RgbaFrontLeft", 1, proximity, light, colorCam),
//        RgbaLeft("RgbaLeft", 2, proximity, light, colorCam),
//        RgbaRearLeft("RgbaRearLeft", 3, proximity, light, colorCam),
//        RgbaRear("RgbaRear", 4,  proximity, light, colorCam),
//        RgbaRearRight("RgbaRearRight", 5, proximity, light, colorCam),
//        RgbaRight("RgbaRight", 6, proximity, light, colorCam),
//        RgbaFrontRight("RgbaFrontRight", 7, proximity, light, colorCam)
//        {
//            Particle.setName(m_name);
//        }

void Krembot::init(const std::string & id,
          CCI_DifferentialSteeringActuator* wheels,
          CCI_FootBotProximitySensor& proximity,
          CCI_LEDsActuator & leds,
          CCI_FootBotLightSensor & light,
          CCI_ColoredBlobOmnidirectionalCameraSensor & colorCam,
          CCI_FootBotImuSensor & imu)
{
    fprintf(stderr, "init");
    m_name = id;
    Base.init(wheels);
//    Bumpers.init(proximity);
//    Imu.init(imu);
//    Led.init(leds);
//    RgbaFront.init("RgbaFront", 0, proximity, light, colorCam);
//    RgbaFrontLeft.init("RgbaFrontLeft", 1, proximity, light, colorCam);
//    RgbaLeft.init("RgbaLeft", 2, proximity, light, colorCam);
//    RgbaRearLeft.init("RgbaRearLeft", 3, proximity, light, colorCam);
//    RgbaRear.init("RgbaRear", 4,  proximity, light, colorCam);
//    RgbaRearRight.init("RgbaRearRight", 5, proximity, light, colorCam);
//    RgbaRight.init("RgbaRight", 6, proximity, light, colorCam);
//    RgbaFrontRight.init("RgbaFrontRight", 7, proximity, light, colorCam);

    Particle.setName(m_name);
}

std::string Krembot::getId() {
    return std::to_string(std::tr1::hash<std::string>()(m_name));
}

void Krembot::test() {
    //    std::cout << "---" << getName() << "---" << std::endl;
//
//    std::cout << "y: " << Imu.read().yaw;
//        Bat.print();

//        Bumpers.read();
//        Bumpers.print();

    //RgbaFront.readRGBA() ;
//    std::cout << "[" << getName() << ", 0] dist:" << RgbaFront.readRGBA().Distance << "| prox: " << RgbaFront.readRGBA().Proximity << std::endl;
//         std::cout << "[" << getName() << ", 0] " << RgbaFront.readRGBA().Ambient << " " << RgbaFront.readRGBA().Proximity << "{r:" << RgbaFront.readRGBA().Red<< " g:" << RgbaFront.readRGBA().Green<< " b:" << RgbaFront.readRGBA().Blue<< "}"<< std::endl;
//        std::cout << "[" << getName() << ", 1] " << RgbaFrontLeft.readRGBA().Ambient  << " " << RgbaFrontLeft.readRGBA().Proximity << "{r:" << RgbaFrontLeft.readRGBA().Red<< " g:" << RgbaFrontLeft.readRGBA().Green<< " b:" << RgbaFrontLeft.readRGBA().Blue<< "}" << std::endl;
//        std::cout << "[" << getName() << ", 2] " << RgbaLeft.readRGBA().Ambient  << " " << RgbaLeft.readRGBA().Proximity << "{r:" << RgbaLeft.readRGBA().Red<< " g:" << RgbaLeft.readRGBA().Green<< " b:" << RgbaLeft.readRGBA().Blue<< "}" << std::endl;
//        std::cout << "[" << getName() << ", 3] " << RgbaRearLeft.readRGBA().Ambient  << " " << RgbaRearLeft.readRGBA().Proximity << "{r:" << RgbaRearLeft.readRGBA().Red<< " g:" << RgbaRearLeft.readRGBA().Green<< " b:" << RgbaRearLeft.readRGBA().Blue<< "}" << std::endl;
//        std::cout << "[" << getName() << ", 4] " << RgbaRear.readRGBA().Ambient  << " " << RgbaRear.readRGBA().Proximity << "{r:" << RgbaRear.readRGBA().Red<< " g:" << RgbaRear.readRGBA().Green<< " b:" << RgbaRear.readRGBA().Blue<< "}" << std::endl;
//        std::cout << "[" << getName() << ", 5] " << RgbaRearRight.readRGBA().Ambient  << " " << RgbaRearRight.readRGBA().Proximity << "{r:" << RgbaRearRight.readRGBA().Red<< " g:" << RgbaRearRight.readRGBA().Green<< " b:" << RgbaRearRight.readRGBA().Blue<< "}" << std::endl;
//        std::cout << "[" << getName() << ", 6] " << RgbaRight.readRGBA().Ambient  << " " << RgbaRight.readRGBA().Proximity << "{r:" << RgbaRight.readRGBA().Red<< " g:" << RgbaRight.readRGBA().Green<< " b:" << RgbaRight.readRGBA().Blue<< "}" << std::endl;
//        std::cout << "[" << getName() << ", 7] " << RgbaFrontRight.readRGBA().Ambient  << " " << RgbaFrontRight.readRGBA().Proximity << "{r:" << RgbaFrontRight.readRGBA().Red<< " g:" << RgbaFrontRight.readRGBA().Green<< " b:" << RgbaFrontRight.readRGBA().Blue<< "}" << std::endl;

}

void Krembot::setup() { }

void Krembot::loop() { }


