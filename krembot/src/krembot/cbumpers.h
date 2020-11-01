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

/*
 * This class simulates physical bumper buttons by reading proximity to objects
 */

#ifndef CBUMPERS_H
#define CBUMPERS_H

#include <cstdint>
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>
#include "cbumpers_result.h"
#include "bumper_state.h"
#include "mobile_base.h"

/* footbot width is 17 cm  and krembot width is 6.5 cm
 * -> that cause different behavior when the robots based on this information
 * a temporary solution - sense the distance in the same proportion
 * and then, return it to the proportions of the original sensor
 * (so that the robots' code works in the same way)
 * */
#define DISTANCE_RATIO_KREMBOT 3.846153846

class CBumpers
{

private:

    enum class BumperPosition {
        SIDES,
        FRONT,
        REAR
    };

    std::vector<BumperState *> m_bumpers;

    argos::CCI_FootBotProximitySensor * m_cProximity = nullptr;
    const MobileBase * m_base = nullptr;

    static const uint8_t NUM_OF_BUMPERS = 8;

    /*
     * The following members are left here despite the fact
     * we have vector representing them, to support real
     * krembot API
     */
    BumperState m_bump_front {"|   FRONT   |", 0};
    BumperState m_bump_front_left {"|FRONT LEFT|", 1};
    BumperState m_bump_left {"|   LEFT   |", 2};
    BumperState m_bump_rear_left {"|REAR  LEFT|", 3};
    BumperState m_bump_rear {"|   REAR    |", 4};
    BumperState m_bump_rear_right {"| REAR RIGHT |", 5};
    BumperState m_bump_right {"|   RIGHT    |", 6};
    BumperState m_bump_front_right {"|FRONT RIGHT |", 7};

    /*
     * Calculate bumper's state based on proximity sensor
     */
    void CalcNewBumperStateBasedOnProximity(const argos::Real & proximity, BumperState & bumper) const ;

    BumperPosition GetBumperPosition(const BumperState & bumper) const ;

public:

    CBumpers();

    void init(argos::CCI_FootBotProximitySensor * proximity, const MobileBase & base);

    BumpersRes read();
    void print();
    void countDown(uint8_t duration);

    // mockup functions
    void publish() {};
    void printCalib() {};
    bool calib() {return true; };
    uint16_t readRaw() { return 0; };

};





#endif //FOOTBOT_DIFFUSION_CBUMPERS_H
