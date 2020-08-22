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

#ifndef MOBILE_BASE_H
#define MOBILE_BASE_H

#include <cstdint>
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>

class MobileBase
{

private:
    /*
     * According to lab experiment with real Krembots hardware, it took about ~500 millis
     * in full speed (100%) to complete a 180 degrees turn.
     * The wheels speed below was calibrated accordingly
     */
    const uint8_t MAX_ARGOS_SPEED_LINEAR = 25 ;
    const uint8_t MAX_ARGOS_SPEED_ANGULAR = 22 ;

    argos::CCI_DifferentialSteeringActuator * m_pcWheels = nullptr;

    int8_t m_linear = 0;
    int8_t m_angular = 0;

public:

    void init(argos::CCI_DifferentialSteeringActuator* wheel);

    bool drive(int8_t linear_spd, int8_t angular_spd);

    void stop();

    /*
     * Mock-up functions
     */
    void standby() {};

    int8_t linearSpeed() const { return m_linear; }
    int8_t angularSpeed() const { return m_angular; }

};

#endif
