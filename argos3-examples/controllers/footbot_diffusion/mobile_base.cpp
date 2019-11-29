
#include "mobile_base.h"

MobileBase::MobileBase(argos::CCI_DifferentialSteeringActuator& wheels) : m_pcWheels(wheels) {};

bool MobileBase::drive(int8_t linear_spd, int8_t angular_spd){ 

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

void MobileBase::stop() {
    drive(0, 0);      
}