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

#include <iostream>
#include "battery.h"
#include "../application.h"

#define MAX_BAT_LVL 4.12
#define MIN_BAT_LVL 3.3
#define MAX_CHRG_LVL 5.0
#define MIN_CHRG_LVL 0.0
#define BATTERY_CAPACITY_MINUTES 30.0f

using namespace std::chrono;

Battery::Battery() {
    // register battery start time upon construction
    m_startTime = steady_clock::now();
}

float Battery::timeRatio() {
    const auto & elapsedMinutes = duration_cast<std::chrono::minutes>(steady_clock::now() - m_startTime).count();
    float timeLeftMinutes = (float)(BATTERY_CAPACITY_MINUTES - elapsedMinutes);
    if (timeLeftMinutes < 0 ) {
        timeLeftMinutes = 0;
    }
    return (timeLeftMinutes / BATTERY_CAPACITY_MINUTES);
}

float Battery::readBatLvl() {
    return (float)((timeRatio() * (MAX_BAT_LVL - MIN_BAT_LVL)) + MIN_BAT_LVL);
}

bool Battery::isFull() { return (timeRatio() == 1); }

uint8_t Battery::getBatLvl() { return timeRatio() * 100; }

float Battery::getBatVolt() { return (float)(timeRatio() * 100.0); }

void Battery::print()
{
    Serial.Println("------------Battery Values------------");
    Serial.Print("Raw Battery read: "); Serial.Print(std::to_string(timeRatio()));
    Serial.Print(" | Battery level: "); Serial.Print(std::to_string((int)getBatLvl()));
    Serial.Print(" | Charge Level: "); Serial.Print(std::to_string((int)getChargeLvl()));
    Serial.Print(" | Is Charging: "); Serial.Print((isCharging() == false ? "No" : "Yes"));
    Serial.Print(" | Is Full: "); Serial.Println((isFull() == false ? "No" : "Yes"));
}



