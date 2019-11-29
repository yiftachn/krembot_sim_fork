#ifndef MOBILE_BASE_H
#define MOBILE_BASE_H

#include <cstdint>
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>


class MobileBase
{
private:
const uint8_t MAX_ARGOS_SPEED = 5;
argos::CCI_DifferentialSteeringActuator& m_pcWheels;
  
public:
 MobileBase(argos::CCI_DifferentialSteeringActuator& wheels) : m_pcWheels(wheels) {};

  bool drive(int8_t linear_spd, int8_t angular_spd){ 

    if ((linear_spd < -100 || linear_spd > 100) ||
        (angular_spd < -100 || angular_spd > 100))
        return false;

    // scale from speed to 0-100 percentage
    int linear_scale = int((linear_spd / 100.0) * MAX_ARGOS_SPEED);
    int angular_scale = int((angular_spd / 100.0) * MAX_ARGOS_SPEED);

    int left_cmd = linear_scale + angular_scale;
    int right_cmd = linear_scale - angular_scale;

    m_pcWheels.SetLinearVelocity(left_cmd, right_cmd);

    return true;
  }

  void standby();

  void stop() {
      
  }

};

#endif