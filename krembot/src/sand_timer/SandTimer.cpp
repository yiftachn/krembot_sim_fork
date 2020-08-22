/*******************************************************************************
* Copyright (c) 2018 Elhay Rauper
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted (subject to the limitations in the disclaimer
* below) provided that the following conditions are met:
*
*     * Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*     * Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the
*     documentation and/or other materials provided with the distribution.
*
*     * Neither the name of the copyright holder nor the names of its
*     contributors may be used to endorse or promote products derived from this
*     software without specific prior written permission.
*
* NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY
* THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
* IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/


#include <cstdio>
#include <argos3/core/simulator/simulator.h>
#include "SandTimer.h"

using namespace argos;

millis_time_t SandTimer::ticks_per_sec_{0};

SandTimer::SandTimer() {
    // get the number of simulation ticks per second
    ticks_per_sec_ = CSimulator::GetInstance().GetTicksPerSec();
}

/**
 * Convert simulation ticks to millis. If simulation is in fast forward, this function
 * will return shorter times accordingly to allow for identical physical behaviour
 * @return simulation time milliseconds
 */
millis_time_t SandTimer::millis() {
    const float sim_clock = CSimulator::GetInstance().GetSimulationClock();
    return sim_clock * (1000.0f / ticks_per_sec_);
}

/* start timer. if already started, do nothing */
void SandTimer::start(millis_time_t period)
{
    if (!started_)
    {
        // calibrating “period”
        setPeriod(period);
        start_time_ = millis();
        started_ = true;
    }
}

void SandTimer::start()
{
    if (!started_)
    {
        start_time_ = millis();
        started_ = true;
    }
}

/* override original start time, and start timer again */
void SandTimer::startOver()
{
    start_time_ = millis();
    if (!started_)
        started_ = true;
}

/* return true if timer has finished */
bool SandTimer::finished()
{
    if (started_)
    {
        end_time_ = millis();
        const float elaspedTime = end_time_ - start_time_;
//        fprintf(stderr, "start: %f, end: %f, elapsed: %f, period: %f\n", start_time_, end_time_, elaspedTime, period_);
        if (elaspedTime >= period_)
        {
            started_ = false;
        }
    }
    return !started_;
}
