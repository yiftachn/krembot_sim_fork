//
// Created by eli on 1/16/20.
//

#ifndef KREMBOT_PARTICLE_OBSERVER_H
#define KREMBOT_PARTICLE_OBSERVER_H

#include "particle_string.h"


#define PRIVATE 0 // definition of publish flags

class ParticleObserver {
private:
    std::string m_name {};

    inline void setName(const std::string & name) { m_name = name; }

    friend class Krembot;

public:
    //todo: if eden's code doesn't compile with const & String, try only String
    void publish(const String & eventName, const String & content, int flags);
    void publish(const char * eventName, int flags);
};


#endif //KREMBOT_PARTICLE_OBSERVER_H
