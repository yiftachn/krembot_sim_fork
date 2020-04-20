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
#include <argos3/core/utility/math/angles.h>
#include "../application.h"

using namespace argos;

CBumpers::CBumpers() {
    m_bumpers.reserve(NUM_OF_BUMPERS);
    m_bumpers.push_back(&m_bump_front);
    m_bumpers.push_back(&m_bump_front_left);
    m_bumpers.push_back(&m_bump_left);
    m_bumpers.push_back(&m_bump_rear_left);
    m_bumpers.push_back(&m_bump_rear);
    m_bumpers.push_back(&m_bump_rear_right);
    m_bumpers.push_back(&m_bump_right);
    m_bumpers.push_back(&m_bump_front_right);
}


void CBumpers::init(CCI_FootBotProximitySensor * proximity, const MobileBase & base) {
    m_cProximity = proximity;
    m_base = &base;
}

CBumpers::BumperPosition CBumpers::GetBumperPosition(const BumperState &bumper) const {
    switch(bumper.getIndex()) {
        case 0: return BumperPosition ::FRONT;
        case 1: return BumperPosition ::FRONT;
        case 2: return BumperPosition ::SIDES;
        case 3: return BumperPosition ::REAR;
        case 4: return BumperPosition ::REAR;
        case 5: return BumperPosition ::REAR;
        case 6: return BumperPosition ::SIDES;
        case 7: return BumperPosition ::FRONT;
        default:
            throw std::runtime_error("CBumpers: invalid bumper index");
    }
}

void CBumpers::CalcNewBumperStateBasedOnProximity(const Real &proximity, BumperState & bumper) const {
    static const CRange<double> intersectionRange {0, 0.027};

    /**
     * in cases where footbot is too close to an object (pass the contact point)
     * bumper will not press (argos bug)
     *
     * Bumper is considered to be pressed iff one of the following conditions
     * are met:
     * 1. linear speed is not 0, and side bumper is pressed
     * 2. linear speed is positive and front bumper is pressed
     * 3. linear speed is negative and rear bumper is pressed
     */

    bumper = BumperState::UNPRESSED;
    auto bumpPos = GetBumperPosition(bumper);
    if (intersectionRange.WithinMinBoundIncludedMaxBoundIncluded(proximity) &&
            (m_base->linearSpeed() != 0))
    { // we have proximity intersection, and inside bumper's range
        if (bumpPos == BumperPosition::SIDES) {
            bumper = BumperState::PRESSED;
        } else if (m_base->linearSpeed() > 0 && bumpPos == BumperPosition::FRONT) {
            bumper = BumperState::PRESSED;
        } else if (m_base->linearSpeed() < 0 && bumpPos == BumperPosition::REAR) {
            bumper = BumperState::PRESSED;
        }
    }
}

BumpersRes CBumpers::read()
{
    if (m_cProximity == nullptr) {
        throw std::invalid_argument("CBumpers::m_cProximity wasn't initialized");
    }

    for (int bumper_idx = 0; bumper_idx < NUM_OF_BUMPERS; ++bumper_idx) {
        auto & bumper = m_bumpers.at(bumper_idx);
        CalcNewBumperStateBasedOnProximity(
                m_cProximity->GetReadings()[bumper_idx].Value, *bumper
        );
    }

    BumpersRes results;
    results.fillFromStates(m_bumpers);
    return results;
}

void CBumpers::print()
{
    Serial.Println("[Bumpers] Bumpers Pressed: ");

    for (const auto & bumper : m_bumpers) {
        if (bumper->isPressed()) {
            Serial.Print(bumper->getName());
        }
    }
    Serial.Println("");
}