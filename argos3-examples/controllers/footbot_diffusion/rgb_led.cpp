//
// Created by eli on 11/29/19.
//

#include "rgb_led.h"

void RGBLed::write(uint8_t red_val,
                   uint8_t green_val,
                   uint8_t blue_val)
{
    if ( (red_val | green_val | blue_val) ) {
        m_led.SetAllIntensities(0.7);
        m_led.SetAllColors(
                argos::CColor{red_val, green_val, blue_val}
        );
    } else {
        m_led.SetAllIntensities(0.0);
        m_led.SetAllColors(
                argos::CColor::BLACK
        );
    }

}