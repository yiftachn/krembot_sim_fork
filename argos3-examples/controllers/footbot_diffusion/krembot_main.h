#ifndef IKREMBOT_LOOP_H
#define IKREMBOT_LOOP_H

#include "krembot.h"
#include <argos3/core/control_interface/ci_controller.h>
/* Definition of the differential steering actuator */
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
/* Definition of the foot-bot proximity sensor */
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>

/*
 * All the ARGoS stuff in the 'argos' namespace.
 * With this statement, you save typing argos:: every time.
 */
using namespace argos;

class KrembotMain {
protected:
    Krembot & krembot;
public:
    KrembotMain(Krembot & krembot_in) : krembot(krembot_in) {}

    virtual void setup() {
        krembot.setup();
    }

    virtual void loop() {
        krembot.loop();
        //your code here
        krembot.Base.drive(-50,0);
    }
};

#endif 