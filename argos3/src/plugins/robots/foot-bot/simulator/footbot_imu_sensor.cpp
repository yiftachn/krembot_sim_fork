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
#include <argos3/core/simulator/entity/composable_entity.h>
#include <argos3/plugins/robots/foot-bot/simulator/footbot_imu_sensor.h>
#include <argos3/core/simulator/simulator.h>



namespace argos{
    CFootBotImuSensor::CFootBotImuSensor() :
            m_pcEmbodiedEntity(NULL),
            m_cSpace(CSimulator::GetInstance().GetSpace()) {}

    void CFootBotImuSensor::SetRobot(CComposableEntity& c_entity) {
        try {
            m_pcEmbodiedEntity = &(c_entity.GetComponent<CEmbodiedEntity>("body"));
            m_pcControllableEntity = &(c_entity.GetComponent<CControllableEntity>("controller"));
        }
        catch(CARGoSException& ex) {
            THROW_ARGOSEXCEPTION_NESTED("Can't set robot for the foot-bot imu sensor", ex);
        }
    }

    void CFootBotImuSensor::Update() {
        /* Get foot-bot orientation */
        m_pcEmbodiedEntity->GetOriginAnchor().Orientation.ToEulerAngles(
                m_tReadings.Yaw,
                m_tReadings.Pitch,
                m_tReadings.Roll
        );
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