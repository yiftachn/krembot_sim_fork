

#ifndef ARGOS3_SIMULATOR_CI_FOOTBOT_IMU_SENSOR_H
#define ARGOS3_SIMULATOR_CI_FOOTBOT_IMU_SENSOR_H

/*
 * @brief This file provides the definition of the footbot light sensor.
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
