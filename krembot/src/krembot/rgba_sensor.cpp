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

#include "rgba_sensor.h"
#include "utils.h"
#include "../application.h"

using namespace argos;

//using intersect_t = CCI_ProximitySensor::intersec_t;

Real RGBASensor::DISTANCE_RATIO_KREMBOT;

RGBASensor::RGBASensor() :
// sensors limits in cm (according to Robotican)
        m_ProxRange{20, 255},
        m_DistRange{6.96, 25.51} { }

void RGBASensor::init(const std::string name,
                      uint8_t index,
                      CCI_FootBotProximitySensor * proximity,
                      CCI_FootBotLightSensor * light,
                      CCI_ColoredBlobOmnidirectionalCameraSensor * colorCam)
{
    m_name = name;
    m_index = index;
    m_cProximity = proximity;
    m_Light = light;
    m_ColorCam = colorCam;

    // create virtual boundaries for each sensor
    // sensors are located around Krembot, seperated by 45 degrees from each other
    // so, upper and lower boundaries for each sensor is its location +- 22.5 degrees (half spacing)
    const Real rgbaSensorSpacing = index * (M_PI / 4.0f); //45 deg
    const Real rangeOffset = (M_PI / 8.0f); //22.5 deg

    CRadians boundary1( utils::WrapToPi( rgbaSensorSpacing + rangeOffset ) );
    CRadians boundary2( utils::WrapToPi( rgbaSensorSpacing - rangeOffset ) );

    if (boundary1 > boundary2) {
        m_ColorSensorAngularRange.Set(boundary2, boundary1);
    } else {
        m_ColorSensorAngularRange.Set(boundary1, boundary2);
    }
}

RGBAResult RGBASensor::readRGBA()
{
    if (m_cProximity == nullptr) {
        throw std::invalid_argument("m_cProximity wasn't initialized");
    }
    if (m_Light == nullptr) {
        throw std::invalid_argument("m_Light wasn't initialized");
    }
    if (m_ColorCam == nullptr) {
        throw std::invalid_argument("m_ColorCam wasn't initialized");
    }

    RGBAResult result;

    /*
     * Calculate Krembot distance out of Footbot proximity sensor:
     * The foot bot proximity sensor measure distance to closest object in range.
     * The range is defined in the argos3 footbot_entity.cpp file, and is currently set to MAX_DISTANCE.
     * The reading from the footbot proximity sensor shows -1 when there's no intersection in sesnor's range
     * In the real krembot this process is done the opposite way (distance is calculated out of proximity)
     */
    const auto rawProximity = m_cProximity->GetReadings()[m_index];

    result.Distance = rawProximity.Value * 100; // convert meters to cm
    //divide by DISTANCE_RATIO_KREMBOT in order to return it to the proportions of the original sensor
    if (rawProximity.IsRobot == true)
    {
        result.Distance = 25.5f;
    }
    else
    {
        result.Distance = (float)(result.Distance / DISTANCE_RATIO_KREMBOT);
        if (result.Distance > 25.6f)
        {
            fprintf(stderr,"=============result.Distance = %f ==== > 25.5f\n=============", result.Distance);
            throw ("result.Distance > 25.6f");
        }
    }

    /*
     * Calculate proximity out of distance using the following rules:
     * 1. Krembot's proximity max value is read when distance is at min value
     * 2. Krembot's proximity min value is read when distance is at max value
     * 3. The max and min values are located on the first lines of this file
     */
    Real krembotProx = {
            (result.Distance - m_DistRange.GetMin()) *
            (m_ProxRange.GetMax() - m_ProxRange.GetMin()) /
            (m_DistRange.GetMax() - m_DistRange.GetMin()) +
            m_ProxRange.GetMin()
    };

    result.Proximity = (uint16_t)krembotProx;

    // Calculate ambient

    result.Ambient = (uint8_t)(m_Light->GetReadings()[m_index].Value * 100);

    // Calculate colors
    const auto & cameraBlobReadings = m_ColorCam->GetReadings().BlobList;
    Real prevDistance = 1000;
    for (const auto & reading : cameraBlobReadings) {

        bool updateColors = false;
        // handle front (0) and back (4) sensor
        if (m_index == 0)
        {
            if ( (reading->Angle >= CRadians(0) && reading->Angle < m_ColorSensorAngularRange.GetMax()) ||
                 (reading->Angle <= CRadians(0) && reading->Angle > m_ColorSensorAngularRange.GetMin()) ) {

                if(prevDistance > reading->Distance) //this blob is closer
                {
                    updateColors = true;
                }
            }
        } else if (m_index == 4) {
            if ( (reading->Angle >= -CRadians(ARGOS_PI) && reading->Angle < m_ColorSensorAngularRange.GetMin()) ||
                 (reading->Angle <= CRadians(ARGOS_PI) && reading->Angle > m_ColorSensorAngularRange.GetMax()) ) {
                if(prevDistance > reading->Distance) //this blob is closer
                {
                    updateColors = true;
                }
            }
        } else if (m_ColorSensorAngularRange.WithinMinBoundIncludedMaxBoundIncluded(reading->Angle)) {

            if(prevDistance > reading->Distance) //this blob is closer
            {
                updateColors = true;
            }
        }

        if (updateColors) {

            result.Green = (uint16_t)reading->Color.GetGreen();
            result.Red = (uint16_t)reading->Color.GetRed();
            result.Blue = (uint16_t)reading->Color.GetBlue();
            prevDistance = reading->Distance;
        }
    }

    return result;
}

HSVResult RGBASensor::readHSV()
{
    RGBAResult in = readRGBA();
    HSVResult out = rgbToHSV(in);
    return out;
}

Colors RGBASensor::readColor()
{
    RGBAResult rgbaIn = readRGBA();
    HSVResult hsvIn = rgbToHSV(rgbaIn);

    if(hsvIn.S < 0.5)
    {
        return Colors::None;
    }
    else if(rgbaIn.Distance < 12 && rgbaIn.Ambient < 200)
    {
        return Colors::None;
    }

    else
    {
        if(hsvIn.H > 85 && hsvIn.H < 165)
        {
            return Colors::Green;
        }
        else if(hsvIn.H > 175 && hsvIn.H < 270)
        {
            return Colors::Blue;
        }

        else if(hsvIn.H > 330 || hsvIn.H < 30)
        {
            return Colors::Red;
        }

    }
    return Colors::None;
}


HSVResult RGBASensor::rgbToHSV(RGBAResult in)
{
    HSVResult out;
    Real min, max, delta;

    min = in.Red < in.Green ? in.Red : in.Green;
    min = min  < in.Blue ? min  : in.Blue;

    max = in.Red > in.Green ? in.Red : in.Green;
    max = max  > in.Blue ? max  : in.Blue;

    out.V = max;
    delta = max - min;

    if (delta < 0.00001)
    {
        out.S = 0;
        out.H = 0;
        return out;
    }

    if( max > 0.0 )
    {
        out.S = (delta / max);
    }
    else
    {
        out.S = 0.0;
        out.H = NAN;
        return out;
    }

    if( in.Red >= max )
    {
        out.H = ( in.Green - in.Blue ) / delta;
    }
    else
    {
        if( in.Green >= max )
        {
            out.H = 2.0 + ( in.Blue - in.Red ) / delta;
        }
        else
        {
            out.H = 4.0 + ( in.Red - in.Green ) / delta;
        }
    }

    out.H *= 60.0;

    if( out.H < 0.0 )
    {
        out.H += 360.0;
    }

    return out;
}


void RGBASensor::printRGBA()
{
    const RGBAResult result = readRGBA();
    Serial.Print("------------ "); Serial.Print(m_name); Serial.Println(" RGBA Sensor Values------------");
    Serial.Print("Ambient: "); Serial.Println(std::to_string(result.Ambient));
    Serial.Print("Red: "); Serial.Println(std::to_string(result.Red));
    Serial.Print("Green: "); Serial.Println(std::to_string(result.Green));
    Serial.Print("Blue: "); Serial.Println(std::to_string(result.Blue));
    Serial.Print("Distance: "); Serial.Println(std::to_string(result.Distance));
}


void RGBASensor::printHSV()
{
    const HSVResult hsv = readHSV();
    Serial.Print("------------ "); Serial.Print(m_name); Serial.Println(" HSV Values------------");
    Serial.Print("Hue: "); Serial.Println(std::to_string(hsv.H));
    Serial.Print("Saturation: "); Serial.Println(std::to_string(hsv.S));
    Serial.Print("Value: "); Serial.Println(std::to_string(hsv.V));
}

void RGBASensor::printColor() {
    Serial.Print(m_name); Serial.Print(" Color: ");
    Colors color = readColor();
    switch (color)
    {
        case Colors::Red:
        {
            Serial.Print(" Red ");
            break;
        }

        case Colors::Green:
        {
            Serial.Print(" Green ");
            break;
        }

        case Colors::Blue:
        {
            Serial.Print(" Blue ");
            break;
        }
        default:
            Serial.Print(" None ");
            break;
    }
    Serial.Println("");
}

void RGBASensor::print() {
    printRGBA();
    printHSV();
    printColor();
}


void RGBASensor::set_DISTANCE_RATIO_KREMBOT(Real _DISTANCE_RATIO_KREMBOT)
{
    DISTANCE_RATIO_KREMBOT = _DISTANCE_RATIO_KREMBOT;
}