//
// Created by elhay rauper
//

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