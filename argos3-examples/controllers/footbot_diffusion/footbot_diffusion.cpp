/* Include the controller definition */
#include "footbot_diffusion.h"
/* Function definitions for XML parsing */
#include <argos3/core/utility/configuration/argos_configuration.h>

/****************************************/
/****************************************/

CFootBotDiffusion::CFootBotDiffusion() {}

/****************************************/
/****************************************/

void CFootBotDiffusion::Init(TConfigurationNode& t_node) {
    //actuators
    m_pcWheels    = GetActuator<CCI_DifferentialSteeringActuator>("differential_steering");

    m_pcLEDs   = GetActuator<CCI_LEDsActuator                          >("leds");

    //seonsors
    m_pcProximity = GetSensor  <CCI_FootBotProximitySensor      >("footbot_proximity"    );
    m_pcLight  = GetSensor  <CCI_FootBotLightSensor                    >("footbot_light");
    m_pcImu = GetSensor  <CCI_FootBotImuSensor                    >("footbot_imu");
    m_pcCamera = GetSensor  <CCI_ColoredBlobOmnidirectionalCameraSensor>("colored_blob_omnidirectional_camera");
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

/****************************************/
/****************************************/

void CFootBotDiffusion::ControlStep() {
    m_pKrembotMain->loop();
}

/****************************************/
/****************************************/

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
REGISTER_CONTROLLER(CFootBotDiffusion, "footbot_diffusion_controller")
