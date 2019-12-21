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

#include "controller.h"
#include <argos3/core/utility/configuration/argos_configuration.h>

#include <krembot/krembot.h>


CFootBotDiffusion::CFootBotDiffusion() {}

void CFootBotDiffusion::Init(TConfigurationNode& t_node) {
    //actuators
    m_pcWheels = GetActuator<CCI_DifferentialSteeringActuator>("differential_steering");

    m_pcLEDs = GetActuator<CCI_LEDsActuator>("leds");

    //seonsors
    m_pcProximity = GetSensor<CCI_FootBotProximitySensor>("footbot_proximity");
    m_pcLight = GetSensor<CCI_FootBotLightSensor>("footbot_light");
    m_pcImu = GetSensor<CCI_FootBotImuSensor>("footbot_imu");
    m_pcCamera = GetSensor<CCI_ColoredBlobOmnidirectionalCameraSensor>("colored_blob_omnidirectional_camera");
    m_pcCamera->Enable();

    m_pKrembot = new Krembot(
            GetId(),
            *m_pcWheels,
            *m_pcProximity,
            *m_pcLEDs,
            *m_pcLight,
            *m_pcCamera,
            *m_pcImu
    );
    m_pKrembotMain = new KrembotMain(*m_pKrembot);
    m_pKrembotMain->setup();
}

void CFootBotDiffusion::ControlStep() {
    m_pKrembotMain->loop();
}

/*
 * This statement notifies ARGoS of the existence of the controller.
 * It binds the class passed as first argument to the string passed as
 * second argument.
 * The string is then usable in the configuration file to refer to this
 * controller.
 * When ARGoS reads that string in the configuration file, it knows which
 * controller class to instantiate.
 * See also the configuration files for an example of how this is used.
 */
//todo user: change the name of the controller
REGISTER_CONTROLLER(CFootBotDiffusion, "run_away_by_bumpers")
