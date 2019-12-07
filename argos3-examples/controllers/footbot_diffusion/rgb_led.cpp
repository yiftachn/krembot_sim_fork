//
// Created by eli on 11/29/19.
//

#include "rgb_led.h"

void RGBLed::write(uint8_t red_val,
                   uint8_t green_val,
                   uint8_t blue_val)
{
    m_led.SetAllIntensities(3.0);
    m_led.SetAllColors(
            argos::CColor{red_val, green_val, blue_val}
    );
}