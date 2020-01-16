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


#include "cbumpers.h"

using namespace argos;

CBumpers::CBumpers(CCI_FootBotProximitySensor & proximity) :
        m_cProximity(proximity) {}

BumperState CBumpers::CalcBumperState(const Real &proximity, const BumperState & prevState) {
    if (proximity >= 0 && proximity <= 0.009) { // we have proximity intersection, and inside bumper's range
        return BumperState::PRESSED;
    }
    if (proximity > 0.005) {
        return BumperState::UNPRESSED;
    }
    // in case of no intersection return prev state
    // to deal with cases where footbot is too close to object
    // and reading is -1
    if (proximity == -1) {
        return prevState;
    }
}

BumpersRes CBumpers::read()
{
    m_results.front = CalcBumperState(m_cProximity.GetReadings()[0].Value, m_results.front);
    m_results.front_left = CalcBumperState(m_cProximity.GetReadings()[1].Value, m_results.front_left);
    m_results.left = CalcBumperState(m_cProximity.GetReadings()[2].Value, m_results.left);
    m_results.rear_left = CalcBumperState(m_cProximity.GetReadings()[3].Value, m_results.rear_left);
    m_results.rear = CalcBumperState(m_cProximity.GetReadings()[4].Value, m_results.rear);
    m_results.rear_right = CalcBumperState(m_cProximity.GetReadings()[5].Value, m_results.rear_right);
    m_results.right = CalcBumperState(m_cProximity.GetReadings()[6].Value, m_results.right);
    m_results.front_right = CalcBumperState(m_cProximity.GetReadings()[7].Value, m_results.front_right);

    return m_results;
}

void CBumpers::print()
{
    std::cout << "[Bumpers] Bumpers Pressed: " << std::endl;

    if (m_results.front == BumperState::PRESSED)
        std::cout << "|   FRONT   |";

    if (m_results.front_right == BumperState::PRESSED)
        std::cout << "|FRONT RIGHT|";

    if (m_results.right == BumperState::PRESSED)
        std::cout << "|   RIGHT   |";

    if (m_results.rear_right == BumperState::PRESSED)
        std::cout << "|REAR  RIGHT|";

    if (m_results.rear == BumperState::PRESSED)
        std::cout << "|   REAR    |";

    if (m_results.rear_left == BumperState::PRESSED)
        std::cout << "| REAR LEFT |";

    if (m_results.left == BumperState::PRESSED)
        std::cout << "|   LEFT    |";

    if (m_results.front_left == BumperState::PRESSED)
        std::cout << "|FRONT LEFT|";

    std::cout << std::endl;
}