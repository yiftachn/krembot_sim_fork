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

#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_imu_sensor.h>

#ifdef ARGOS_WITH_LUA
#include <argos3/core/wrappers/lua/lua_utility.h>
#endif

namespace argos {

#ifdef ARGOS_WITH_LUA
    void CCI_FootBotImuSensor::CreateLuaState(lua_State* pt_lua_state) {
        CLuaUtility::OpenRobotStateTable(pt_lua_state, "imu");
        CLuaUtility::StartTable(pt_lua_state, 1                           );
        CLuaUtility::AddToTable(pt_lua_state, "roll",  m_tReadings.Roll);
        CLuaUtility::AddToTable(pt_lua_state, "pitch",  m_tReadings.Pitch);
        CLuaUtility::AddToTable(pt_lua_state, "yaw",  m_tReadings.Yaw);
        CLuaUtility::EndTable  (pt_lua_state                                );
        CLuaUtility::CloseRobotStateTable(pt_lua_state);
    }
#endif

    /****************************************/
    /****************************************/

#ifdef ARGOS_WITH_LUA
    void CCI_FootBotImuSensor::ReadingsToLuaState(lua_State* pt_lua_state) {}
#endif

}