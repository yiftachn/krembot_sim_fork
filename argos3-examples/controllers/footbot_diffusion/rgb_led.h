//
// Created by eli on 11/29/19.
//

#ifndef FOOTBOT_DIFFUSION_RGB_LED_H
#define FOOTBOT_DIFFUSION_RGB_LED_H


#include <stdint.h>
#include <argos3/plugins/robots/generic/control_interface/ci_leds_actuator.h>

class RGBLed
{
private:
    argos::CCI_LEDsActuator & m_led;
public:
    RGBLed(argos::CCI_LEDsActuator & led) : m_led(led) {}
    void write(uint8_t red_val,
               uint8_t green_val,
               uint8_t blue_val);
};


#endif //FOOTBOT_DIFFUSION_RGB_LED_H
