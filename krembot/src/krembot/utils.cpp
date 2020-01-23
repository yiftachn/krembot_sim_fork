/*******************************************************************************
* Copyright (c) 2019, Elhay Rauper.
* All rights reserved.
*
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

#include "utils.h"

#include <stdexcept>
#include <sstream>
#include <math.h>
#include <ctime>

namespace utils {

    float ConvertToAllPositiveCircleRange(float value) {
        if ( value < -180 || value > 180 ) {
            std::ostringstream error;
            error << "invalid value: " << value << ". value must be in range of -180 -> 180.";
            throw std::runtime_error(error.str());
        }
        if (value < 0) {
            value  = 360 - abs(value);
        }
        return value;
    }

    float WrapToPi(float rads) {
        if (rads > M_PI) return (2 * -M_PI) + rads;
        else return rads;
    }

namespace datetime {

    void GetIso8601DateTime(char * buff, size_t size) {
        if (size < ISO_8601_TIME_DATE_SIZE) {
            return;
        }
        time_t now;
        time(&now);
        strftime(buff, size, "%FT%TZ", gmtime(&now));
    }
} // end of time

} // end of utils

