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

#ifndef KREMBOT_CBUMPERS_RESULT_H
#define KREMBOT_CBUMPERS_RESULT_H


#include <string>
#include <vector>

class BumperState
{
private:
    uint8_t m_state = UNDEFINED;
    std::string m_name {};
    uint8_t m_index = 0;

public:

    static const uint8_t UNDEFINED = 0;
    static const uint8_t PRESSED = 1;
    static const uint8_t UNPRESSED = 2;

    BumperState() = default;

    BumperState(const std::string & bumperName, uint8_t ringIndex) :
            m_name{bumperName},
            m_index{ringIndex} { }

    BumperState(const uint8_t state) : m_state {state} { }

    bool operator==(const BumperState & other) {
        return (this->m_state == other.m_state);
    }

    void operator=(const uint8_t state) {
        this->m_state = state;
    }

    inline const std::string & getName() const {
        return m_name;
    }

    inline uint8_t getIndex() const {
        return m_index;
    }

    inline bool isPressed() const {
        return (m_state == PRESSED);
    }
};

struct BumpersRes
{
private:

    std::vector<BumperState *> m_bumpers;

    friend class CBumpers;

public:

    static const uint8_t NUM_OF_BUMPERS = 8;

    /*
     * The following members are left here despite the fact
     * we have vector representing them, to support real
     * krembot API
     */
    BumperState front { "|   FRONT   |", 0};
    BumperState front_right { "|FRONT RIGHT|", 1};
    BumperState right { "|   RIGHT   |", 2};
    BumperState rear_right { "|REAR  RIGHT|", 3};
    BumperState rear { "|   REAR    |", 4};
    BumperState rear_left { "| REAR LEFT |", 5};
    BumperState left { "|   LEFT    |", 6};
    BumperState front_left { "|FRONT LEFT |", 7};

    BumpersRes();

    bool isAnyPressed() const ;
};


#endif //KREMBOT_CBUMPERS_RESULT_H
