

/*******************************************************************************
* Copyright (c) 2018, RoboTICan, LTD.
* All rights reserved.
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
* * Neither the name of RoboTICan nor the names of its
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

/* Author: Elhay Rauper */


#include "imu_sensor.h"


using namespace argos;

IMUSensor::IMUSensor(CCI_FootBotImuSensor & imu) :
        m_Imu{imu} {}

// get latest IMU fused data
ImuData IMUSensor::read()
{

    // assing readings to the correct real world axes
//    data.roll = imu_.pitch;
//    data.pitch = imu_.roll;
//    data.yaw = imu_.yaw;

//    data.ax = imu_.ax;
//    data.ax = imu_.ay;
//    data.ax = imu_.az;
//
//    data.ax = imu_.gx;
//    data.ax = imu_.gy;
//    data.ax = imu_.gz;

    const auto readings = m_Imu.GetReadings();
    return ImuData(
            ToDegrees(readings.Roll).GetValue(),
            ToDegrees(readings.Pitch).GetValue(),
            ToDegrees(readings.Yaw).GetValue()
    );
}




void IMUSensor::print()
{
//    Serial.print("[IMU]: Roll, Pitch, Yaw");
//    Serial.print(imu_.roll, 2);
//    Serial.print(", ");
//    Serial.print(imu_.pitch, 2);
//    Serial.print(", ");
//    Serial.println(imu_.yaw, 2);
}


void IMUSensor::printRaw()
{
//    print();
//
//    Serial.print("ax: ");Serial.print(imu_.ax);
//    Serial.print(", ay: ");Serial.print(imu_.ay);
//    Serial.print(", az: ");Serial.println(imu_.az);
//    Serial.print(" gx: ");Serial.print(imu_.gx);
//    Serial.print(", gy: ");Serial.print(imu_.gy);
//    Serial.print(", gz: ");Serial.println(imu_.gz);

}
