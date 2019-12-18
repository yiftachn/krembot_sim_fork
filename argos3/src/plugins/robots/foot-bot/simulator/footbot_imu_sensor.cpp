//
// Created by eli on 12/18/19.
//

#include <argos3/core/simulator/entity/composable_entity.h>
#include <argos3/plugins/robots/foot-bot/simulator/footbot_imu_sensor.h>
#include <argos3/plugins/simulator/entities/imu_equipped_entity.h>
#include <argos3/core/simulator/simulator.h>


//todo: build and include CImuSensorEquippedEntity

namespace argos{
    CFootBotImuSensor::CFootBotImuSensor() :
            m_pcEmbodiedEntity(NULL),
            m_cSpace(CSimulator::GetInstance().GetSpace()) {}

    void CFootBotImuSensor::SetRobot(CComposableEntity& c_entity) {
        try {
            m_pcEmbodiedEntity = &(c_entity.GetComponent<CEmbodiedEntity>("body"));
            m_pcControllableEntity = &(c_entity.GetComponent<CControllableEntity>("controller"));
            m_pcImuEntity = &(c_entity.GetComponent<CImuEquippedEntity>("footbot_imu"));
        }
        catch(CARGoSException& ex) {
            THROW_ARGOSEXCEPTION_NESTED("Can't set robot for the foot-bot imu sensor", ex);
        }
        m_cRobot = &c_entity;
    }

    void CFootBotImuSensor::Update() {
        /* Get foot-bot orientation */
        m_pcEmbodiedEntity->GetOriginAnchor().Orientation.ToEulerAngles(
                m_tReadings.Yaw,
                m_tReadings.Pitch,
                m_tReadings.Roll
        );

        //m_cRobot->G
    }

    void CFootBotImuSensor::Init(argos::TConfigurationNode &t_tree) {

    }

    void CFootBotImuSensor::Reset() {
        m_tReadings = SReading();
    }

    REGISTER_SENSOR(CFootBotImuSensor,
                    "footbot_imu", "rpy",
                    "Elhay Rauper",
                    "1.0",
                    "The foot-bot imu sensor",
                    "This sensor provide footbot orientation (yaw, pitch and roll) readings\n"
                    "Currently this sensor only provide a mockup readings for accelerations\n"
                    "REQUIRED XML CONFIGURATION\n\n"
                    "  <controllers>\n"
                    "    ...\n"
                    "    <my_controller ...>\n"
                    "      ...\n"
                    "      <sensors>\n"
                    "        ...\n"
                    "        <footbot_imu implementation=\"rpy\" />\n"
                    "        ...\n"
                    "      </sensors>\n"
                    "      ...\n"
                    "    </my_controller>\n"
                    "    ...\n"
                    "  </controllers>\n\n"
                    "OPTIONAL XML CONFIGURATION\n\n"
                    "None.\n"
                    "OPTIONAL XML CONFIGURATION\n\n"
                    "None.\n",
                    "Usable"
    );



}