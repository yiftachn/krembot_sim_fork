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


#include "particle_observer.h"

#include "../krembot/utils.h"

#include <iostream>

/**
 * Simulate Particle.Publish() - generate a similar message to the one that
 * is printed in Particle cloud platform.
 * @param eventName
 * @param content - stub field - does nothing
 * @param flags - stub field - does nothing
 */
void ParticleObserver::publish(const String & eventName, const String & content, int flags) {
    if (m_name.empty()) {
        return;
      }
    int sim_clock = millis();
    int milisec = sim_clock;
    //3600000 milliseconds in an hour
    int hours = sim_clock / 3600000;
    milisec = milisec - 3600000 * hours;
    //60000 milliseconds in a minute
    int min = milisec / 60000;
    milisec = milisec - 60000 * min;
    //1000 milliseconds in a second
    int sec = milisec / 1000;
    milisec = milisec - 1000 * sec;

//    int milisec = sim_clock % 10;
//    sim_clock = sim_clock / 10;
//    int sec = sim_clock % 60;
//    int min = (sim_clock / 60) % 60;
//    int hours = (sim_clock / 60) / 60;
    char dateBuff[30];
    snprintf(dateBuff, sizeof(dateBuff), "2020-07-01T%02d:%02d:%02d.%d00Z", hours, min, sec, milisec);
    //the wanted format: 2019-04-10T13:15:52.087Z
    fprintf(stderr,"event: %s\ndata: {\"data\":\"%s\",\"ttl\":\"60\",\"published_at\":\"%s\",\"coreid\":\"%s\"}\n",
            eventName.str().c_str(),
            content.str().c_str(),
            dateBuff,
            m_name.c_str()
    );
}

/**
 * Same as publish function above, but content field will be printed as "null"
 * @param eventName
 * @param flags
 */
void ParticleObserver::publish(const char * eventName, int flags) {
    publish(eventName, "null", flags);
}

/**
 * Stub function
 * @param topic
 * @param func
 */
void ParticleObserver::subscribe(const String & topic, std::function<void(const char*, const char*)> & func) {

}
