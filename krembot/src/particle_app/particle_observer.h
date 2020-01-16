//
// Created by eli on 1/16/20.
//

#ifndef KREMBOT_PARTICLE_OBSERVER_H
#define KREMBOT_PARTICLE_OBSERVER_H

#include "particle_string.h"


#define PRIVATE 0 // definition of publish flags

class ParticleObserver {
    void publish(String eventName, String content, int flags);
    void publish(const char * eventName, int flags);
};


#endif //KREMBOT_PARTICLE_OBSERVER_H
