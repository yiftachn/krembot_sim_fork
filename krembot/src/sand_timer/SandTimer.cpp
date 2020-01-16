
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


#include "SandTimer.h"

using namespace std::chrono;

SandTimer::SandTimer()
{
    started_ = false;
    period_ = 1000;
}

void SandTimer::setPeriod(unsigned long period)
{
    period_ = period;
}

/* start timer. if already started, do nothing */
void SandTimer::start(unsigned long period)
{
    if (!started_)
    {
        period_ = period;
        start_time_ = steady_clock::now();
        started_ = true;
    }
}

void SandTimer::start()
{
    if (!started_)
    {
        start_time_ = steady_clock::now();
        started_ = true;
    }
}
/* override original start time, and start timer again */
void SandTimer::startOver()
{
    start_time_ = steady_clock::now();
    if (!started_)
        started_ = true;
}

/* return true if timer has finished */
bool SandTimer::finished()
{
    if (started_)
    {
        end_time_ = steady_clock::now();
        const float elaspedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end_time_ - start_time_).count();
        if (elaspedTime >= period_)
        {
            started_ = false;
        }
    }
    return !started_;
}

void SandTimer::reset() {started_ = false;}

bool SandTimer::isRunning()
{
    return started_;
}