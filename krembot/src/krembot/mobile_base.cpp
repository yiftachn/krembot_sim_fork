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

#include "mobile_base.h"
#include <argos3/core/utility/math/angles.h>

void MobileBase::init(argos::CCI_DifferentialSteeringActuator* wheels) {
    m_pcWheels = wheels;
}

bool MobileBase::drive(int8_t linear_spd, int8_t angular_spd) {
    argos::CRange<int> speedRange(-100, 100);

    if ( ! speedRange.WithinMinBoundIncludedMaxBoundIncluded(linear_spd) ||
         ! speedRange.WithinMinBoundIncludedMaxBoundIncluded(angular_spd))
    {
        return false;
    }

    // convert speed to 0-100 percentage
    const float range_max = static_cast<float>(speedRange.GetMax());
    int linear_scale = int((linear_spd / range_max) * MAX_ARGOS_SPEED);
    int angular_scale = int((angular_spd / range_max) * MAX_ARGOS_SPEED);

    int left_cmd = linear_scale - angular_scale;
    int right_cmd = linear_scale + angular_scale;

    if (m_pcWheels != nullptr) {
        m_pcWheels->SetLinearVelocity(left_cmd, right_cmd);
        return true;
    }

    return false;
}

void MobileBase::stop() {
    drive(0, 0);      
}