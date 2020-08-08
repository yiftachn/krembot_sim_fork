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


#ifndef FOOTBOT_DIFFUSION_H
#define FOOTBOT_DIFFUSION_H


#include <argos3/core/control_interface/ci_controller.h>
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>
#include <argos3/plugins/robots/generic/control_interface/ci_leds_actuator.h>
#include <argos3/plugins/robots/generic/control_interface/ci_colored_blob_omnidirectional_camera_sensor.h>
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_light_sensor.h>
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_imu_sensor.h>


#include "../krembot.h"
#include "../particle_app/particle_observer.h"
#include "../particle_app/serial.h"
#include "../particle_app/particle_string.h"
#include "../particle_app/timing.h"

using namespace argos;


class KrembotController : public CCI_Controller {

public:

    virtual ~KrembotController() = default;

    /*
     * This function initializes the controller.
     * The 't_node' variable points to the <parameters> section in the XML
     * file in the <controllers><footbot_diffusion_controller> section.
     */
    virtual void Init(TConfigurationNode& t_node);

    /*
     * This function is called once every time step.
     * The length of the time step is set in the XML file.
     */
    virtual void ControlStep() = 0;

    /*
     * This function resets the controller to its state right after the
     * Init().
     * It is called when you press the reset button in the GUI.
     * In this example controller there is no need for resetting anything,
     * so the function could have been omitted. It's here just for
     * completeness.
     */
    virtual void Reset() {}

    /*
     * Called to cleanup what done by Init() when the experiment finishes.
     * In this example controller there is no need for clean anything up,
     * so the function could have been omitted. It's here just for
     * completeness.
     */
    virtual void Destroy() {}


   inline Krembot* getKrembotPtr() { return &krembot; }

private:


    /* Pointer to the differential steering actuator */
    CCI_DifferentialSteeringActuator* m_pcWheels = nullptr;
    /* Pointer to the foot-bot proximity sensor */
    CCI_FootBotProximitySensor* m_pcProximity = nullptr;
    /* Pointer to the foot-bot light sensor */
    CCI_FootBotLightSensor* m_pcLight = nullptr;
    /* Pointer to the LEDs actuator */
    CCI_LEDsActuator* m_pcLEDs = nullptr;
    /* Pointer to the omnidirectional camera sensor */
    CCI_ColoredBlobOmnidirectionalCameraSensor* m_pcCamera = nullptr;
    /* Pointer to the imu sensor */
    CCI_FootBotImuSensor* m_pcImu = nullptr;

protected:
    Krembot krembot;
};


#define KREMBOT_CONTROLLER_HEADER(CLASS_NAME) \
    class CLASS_NAME : public KrembotController{

#define KREMBOT_CONTROLLER_FOOTER(CLASS_NAME, PROGRAM_NAME) \
public: \
ParticleObserver Particle; \
~CLASS_NAME() = default; \
void Init(TConfigurationNode& t_node) override { \
KrembotController::Init(t_node); \
if ( ! krembot.isInitialized() ) { \
throw std::runtime_error("krembot.ino.cpp: krembot wasn't initialized in controller"); \
} \
Particle.setName(krembot.getName()); \
setup(); \
} \
void ControlStep() override { loop(); } \
};\
/* \
 * This statement notifies ARGoS of the existence of the controller. \
 * It binds the class passed as first argument to the string passed as \
 * second argument. \
 * The string is then usable in the configuration file to refer to this \
 * controller. \
 * When ARGoS reads that string in the configuration file, it knows which \
 * controller class to instantiate. \
 * See also the configuration files for an example of how this is used. \
 */\
REGISTER_CONTROLLER(CLASS_NAME, PROGRAM_NAME)



#endif



