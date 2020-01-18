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

#include "imu_sensor.h"
#include "utils.h"
#include "../particle_app/application.h"

using namespace argos;

void IMUSensor::init(CCI_FootBotImuSensor * imu) {
    m_Imu = imu;
}

// get latest IMU fused data
ImuData IMUSensor::read()
{
    if (m_Imu == nullptr) {
        throw std::invalid_argument("IMUSensor::m_Imu wasn't initialized");
    }

    // Get radians readings
    const auto readings =       m_Imu->GetReadings();

    // Convert to degrees and multiply by -1 to flip circle
    // from anti clock-wise positive to clock-wise positive
    const float rollDeg =       -1 * ToDegrees(readings.Roll).GetValue();
    const float pitchDeg =      -1 * ToDegrees(readings.Pitch).GetValue();
    const float yawDeg =        -1 * ToDegrees(readings.Yaw).GetValue();

    // Convert data from -180-180 to 0-360 range and return
    return ImuData(
            utils::ConvertToAllPositiveCircleRange(rollDeg),
            utils::ConvertToAllPositiveCircleRange(pitchDeg),
            utils::ConvertToAllPositiveCircleRange(yawDeg)
    );
}

void IMUSensor::print()
{
    const auto rpy = read();
    Serial.Print("[IMU]: Roll, Pitch, Yaw");
    Serial.Print(std::to_string(rpy.roll)); Serial.Print(", ");
    Serial.Print(std::to_string(rpy.pitch)); Serial.Print(", ");
    Serial.Println(std::to_string(rpy.yaw)); Serial.Print(", ");
}

void IMUSensor::printRaw()
{
    print();

    const auto rpy = read();
    Serial.Print("ax: "); Serial.Print(std::to_string(rpy.ax));
    Serial.Print("ay: "); Serial.Print(std::to_string(rpy.ay));
    Serial.Println("az: "); Serial.Print(std::to_string(rpy.az));

    Serial.Print("gx: "); Serial.Print(std::to_string(rpy.gx));
    Serial.Print("gy: "); Serial.Print(std::to_string(rpy.gy));
    Serial.Println("gz: "); Serial.Print(std::to_string(rpy.gz));
}
