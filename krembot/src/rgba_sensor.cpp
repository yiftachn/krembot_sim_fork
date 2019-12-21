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

using namespace argos;

RGBASensor::RGBASensor(const std::string name,
                        uint8_t index,
                        CCI_FootBotProximitySensor &proximity,
                       CCI_FootBotLightSensor &light,
                       CCI_ColoredBlobOmnidirectionalCameraSensor &colorCam) :
                        m_name(name),
                        m_index(index),
                        m_cProximity(proximity),
                        m_Light(light),
                        m_ColorCam(colorCam),

                        // sensors limits in cm (according to Robotican)
                        m_ProxRange{20, 255},
                        m_DistRange{6.96, 25.51}
{
    // create virtual boundaries for each sensor
    // sensors are located around Krembot, seperated by 45 degrees from each other
    // so, upper and lower boundaries for each sensor is its location +- 22.5 degrees (half spacing)
    const float rgbaSensorSpacing = index * (M_PI / 4.0f); //45 deg
    const float rangeOffset = (M_PI / 8.0f); //22.5 deg

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
    RGBAResult result;

    /*
     * Calculate Krembot distance out of Footbot proximity sensor:
     * The foot bot proximity sensor measure distance to closest object in range.
     * The range is defined in the argos3 footbot_entity.cpp file, and is currently set to MAX_DISTANCE.
     * The reading from the footbot proximity sensor shows -1 when there's no intersection in sesnor's range
     * In the real krembot this process is done the opposite way (distance is calculated out of proximity)
     */
    const Real rawProximity = m_cProximity.GetReadings()[m_index].Value;
    /*
     * No proximity intersection. In other words: no object in sensor's range
     * This can happend in 2 cases:
     * 1. We are too close to an object (simulator bug)
     * 2. We are too far from an object
     * To identify which case we are dealing with, a check is made for each calculation to tell if we
     * are in a "far" or "near" range relative to the closest object. If we are in the near range and then
     * see -1, it means we are in case 1. , otherwise case 2. The same principal is applied for CBumpers
     * This method assumes that krembot is place at least 1 cm from any other object at the very beginning
     * of the simulation run. Otherwise the first m_ProxState=FAR is not correct
     */
    if (rawProximity == -1) {
        if (m_ProxState == ProxState::NEAR) {
            result.Distance = m_DistRange.GetMin();
        } else { // far
            result.Distance = m_DistRange.GetMax();
        }
    } else { // intersection in sensor's range
        result.Distance = rawProximity * 100; // convert meters to cm
        const float halfDistRange = m_DistRange.GetMax()/2.0;
        if (result.Distance >= halfDistRange) {
            m_ProxState = ProxState::FAR;
        } else {
            m_ProxState = ProxState::NEAR;
        }
        // truncate value to min and max boundaries
        m_DistRange.TruncValue(result.Distance);
    }

    /*
     * Calculate proximity out of distance using the following rules:
     * 1. Krembot's proximity max value is read when distance is at min value
     * 2. Krembot's proximity min value is read when distance is at max value
     * 3. The max and min values are located on the first lines of this file
     */
    float krembotProx = {
            (result.Distance - m_DistRange.GetMin()) *
            (m_ProxRange.GetMax() - m_ProxRange.GetMin()) /
            (m_DistRange.GetMax() - m_DistRange.GetMin()) +
            m_ProxRange.GetMin()
    };
    result.Proximity = krembotProx;

    // Calculate ambient
    result.Ambient = m_Light.GetReadings()[m_index].Value * 100;

    // Calculate colors
    const auto & cameraBlobReadings = m_ColorCam.GetReadings().BlobList;

    for (const auto & reading : cameraBlobReadings) {

        bool updateColors = false;
        // handle front (0) and back (4) sensor
        if (m_index == 0)
        {
            if ( (reading->Angle >= CRadians(0) && reading->Angle < m_ColorSensorAngularRange.GetMax()) ||
                 (reading->Angle <= CRadians(0) && reading->Angle > m_ColorSensorAngularRange.GetMin()) ) {
                updateColors = true;
            }
        } else if (m_index == 4) {
            if ( (reading->Angle >= -CRadians(ARGOS_PI) && reading->Angle < m_ColorSensorAngularRange.GetMin()) ||
                 (reading->Angle <= CRadians(ARGOS_PI) && reading->Angle > m_ColorSensorAngularRange.GetMax()) ) {
                updateColors = true;
            }
        } else if (m_ColorSensorAngularRange.WithinMinBoundIncludedMaxBoundIncluded(reading->Angle)) {
            updateColors = true;
        }

        if (updateColors) {

            result.Green = reading->Color.GetGreen();
            result.Red = reading->Color.GetRed();
            result.Blue = reading->Color.GetBlue();
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
    double min, max, delta;

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
    std::cout << "------------ " << m_name << " RGBA Sensor Values------------" << std::endl;
    std::cout << "Ambient: " << result.Ambient << std::endl;
    std::cout << "Red: " << result.Red << std::endl;
    std::cout << "Green: " << result.Green << std::endl;
    std::cout << "Blue: " << result.Blue << std::endl;
    std::cout << "Distance: " << result.Distance << std::endl;
}


void RGBASensor::printHSV()
{
    const HSVResult hsv = readHSV();
    std::cout << "------------ " << m_name << " HSV Values------------" << std::endl;
    std::cout << "Hue: " << hsv.H << std::endl;
    std::cout << "Saturation: " << hsv.S << std::endl;
    std::cout << "Value: " << hsv.V << std::endl;
}

void RGBASensor::printColor() {
    std::cout << m_name << " Color: ";
    Colors color = readColor();
    switch (color)
    {
        case Colors::Red:
        {
            std::cout << " Red ";
            break;
        }

        case Colors::Green:
        {
            std::cout << " Green ";
            break;
        }

        case Colors::Blue:
        {
            std::cout << " Blue ";
            break;
        }
        default:
            std::cout << " None ";
            break;
    }
}

void RGBASensor::print() {
    printRGBA();
    printHSV();
    printColor();
}