/*******************************************************************************
* Copyright (c) 2019, Elhay Rauper.
* All rights reserved.
*
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

#ifndef ARGOS3_SIMULATOR_CI_FOOTBOT_IMU_SENSOR_H
#define ARGOS3_SIMULATOR_CI_FOOTBOT_IMU_SENSOR_H

/*
 * @brief This file provides the definition of the footbot imu sensor.
 *
 * This file provides the definition of the footbot imu sensor
 * This sensor provide footbot orientation (yaw, pitch and roll) readings
 * Currently this sensor only provide a mockup readings for accelerations
 */

namespace argos {
    class CCI_FootBotImuSensor;
}

#include <argos3/core/utility/math/angles.h>
#include <argos3/core/control_interface/ci_sensor.h>

namespace argos {

    class CCI_FootBotImuSensor : public CCI_Sensor {

    public:
        struct SReading {
            CRadians Roll  {0};
            CRadians Yaw   {0};
            CRadians Pitch {0};
        };

        virtual ~CCI_FootBotImuSensor() {}

        inline const SReading & GetReadings() const { return m_tReadings; }

#ifdef ARGOS_WITH_LUA
        virtual void CreateLuaState(lua_State* pt_lua_state);

        virtual void ReadingsToLuaState(lua_State* pt_lua_state);
#endif

    protected:

        SReading m_tReadings;
    };

}


#endif //ARGOS3_SIMULATOR_CI_FOOTBOT_IMU_SENSOR_H
