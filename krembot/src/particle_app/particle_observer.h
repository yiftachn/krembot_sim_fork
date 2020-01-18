//
// Created by eli on 1/16/20.
//

#ifndef KREMBOT_PARTICLE_OBSERVER_H
#define KREMBOT_PARTICLE_OBSERVER_H

#include "particle_string.h"

#include <functional>
// definition of publish flags
#define PRIVATE 0

// definision of subscription flags
#define ALL_DEVICES 0
#define MY_DEVICES 1


class ParticleObserver {
private:
    std::string m_name {};

    inline void setName(const std::string & name) { m_name = name; }

    friend class Krembot;

public:
    //todo: if eden's code doesn't compile with const & String, try only String
    void publish(const String & eventName, const String & content, int flags);
    void publish(const char * eventName, int flags);

    void subscribe(const String & topic, std::function<void(const char*, const char*)> & func);
};


#endif //KREMBOT_PARTICLE_OBSERVER_H
