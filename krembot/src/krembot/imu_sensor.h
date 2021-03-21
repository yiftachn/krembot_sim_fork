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


#ifndef IMUSENSOR_H
#define IMUSENSOR_H

/*
 * This class simulates IMU sensor by reading the foot-bot position
 */

#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_imu_sensor.h>

using namespace argos;

struct ImuData
{
    float roll = 0,
            pitch = 0,
            yaw = 0;

    float ax = 0,
            ay = 0,
            az = 0;

    float gx = 0,
            gy = 0,
            gz = 0;

    ImuData() = default;
    ImuData(float r, float p, float y) {
        roll = r;
        pitch = p;
        yaw = y;
    }
};

class IMUSensor
{
private:
    argos::CCI_FootBotImuSensor * m_Imu = nullptr;

public:

    void init(argos::CCI_FootBotImuSensor * imu);

    ImuData read();
    void print();
    void printRaw();

    /*
     * mock up functions
     */
    void init() { }
    void loop() { }
    void publish() { }

};

#endif
