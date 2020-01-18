//
// Created by eli on 1/16/20.
//

#include "particle_observer.h"

#include "../krembot/utils.h"

void ParticleObserver::publish(const String & eventName, const String & content, int flags) {
    if (m_name.empty()) {
        return;
    }
    char dateBuff[utils::datetime::ISO_8601_TIME_DATE_SIZE];
    utils::datetime::getDateTime(dateBuff);
    printf("{\"data\":\"%s\",\"ttl\":\"60\",\"published_at\":\"%s\",\"coreid\":\"%s\"}",
            content.str().c_str(),
           dateBuff,
            m_name.c_str());
}
void ParticleObserver::publish(const char * eventName, int flags) {
    publish(eventName, "null", flags);
}