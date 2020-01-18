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

#include "cbumpers_result.h"

BumpersRes::BumpersRes() {
    m_bumpers.reserve(NUM_OF_BUMPERS);
    m_bumpers.push_back(&front);
    m_bumpers.push_back(&front_right);
    m_bumpers.push_back(&right);
    m_bumpers.push_back(&rear_right);
    m_bumpers.push_back(&rear);
    m_bumpers.push_back(&rear_left);
    m_bumpers.push_back(&left);
    m_bumpers.push_back(&front_left);
}

bool BumpersRes::isAnyPressed() const
{
    for (const auto & bumper : m_bumpers) {
        if (bumper->isPressed()) {
            return true;
        }
        return false;
    }
}