
// created by elhay rauper

#ifndef ARGOS3_SIMULATOR_FOOTBOT_IMU_SENSOR_H
#define ARGOS3_SIMULATOR_FOOTBOT_IMU_SENSOR_H

namespace argos {
    class CFootBotImuSensor;
}

#include <argos3/core/simulator/sensor.h>
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_imu_sensor.h>
#include <argos3/core/simulator/space/space.h>
#include <argos3/core/simulator/sensor.h>

namespace argos {

    class CFootBotImuSensor : public CSimulatedSensor,
                              public CCI_FootBotImuSensor {

    public:

        CFootBotImuSensor();

        virtual ~CFootBotImuSensor() {}

        virtual void SetRobot(CComposableEntity& c_entity);

        virtual void Init(TConfigurationNode& t_tree);

        virtual void Update();

        virtual void Reset();

    protected:

        /** Reference to embodied entity associated to this sensor */
        CEmbodiedEntity* m_pcEmbodiedEntity;

        /** Reference to controllable entity associated to this sensor */
        CControllableEntity* m_pcControllableEntity;

        /** Reference to the space */
        CSpace& m_cSpace;
    };
}

#endif //ARGOS3_SIMULATOR_FOOTBOT_IMU_SENSOR_H
