//
// Created by eli on 11/29/19.
//

#include "rgba_sensor.h"

/*******************************************************************************
* Copyright (c) 2018, RoboTICan, LTD.
* All rights reserved.
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
* * Neither the name of RoboTICan nor the names of its
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

/* Author: Elhay Rauper */

#include "rgba_sensor.h"
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
                        m_ColorCam(colorCam)
{
    const float rgbaSensorSpacing = index * (M_PI / 4.0f); //45 deg
    const float rangeOffset = (M_PI / 8.0f); //22.5 deg

    CRadians boundary1( wrapToPi( rgbaSensorSpacing + rangeOffset ) );
    CRadians boundary2( wrapToPi( rgbaSensorSpacing - rangeOffset ) );

    if (boundary1 > boundary2) {
        m_ColorSensorAngularRange.Set(boundary2, boundary1);
    } else {
        m_ColorSensorAngularRange.Set(boundary1, boundary2);
    }
}



RGBAResult RGBASensor::readRGBA()
{
    RGBAResult result;

    const Real rawProximity = m_cProximity.GetReadings()[m_index].Value;
    if (rawProximity == -1) { // no proximity intersection
        result.Proximity = 0;
    } else { // intersection in sensor range
        result.Proximity = rawProximity * 100; // todo: scale this according to real robot
    }

    result.Ambient = m_Light.GetReadings()[m_index].Value * 100; // todo: scale this according to real robot

    const auto & cameraBlobReadings = m_ColorCam.GetReadings().BlobList;

    //float numOfInBoundReadings = 0;
    for (const auto & reading : cameraBlobReadings) {
        // handle front and back sensor
        bool updateColors = false;
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
            //result.Ambient += reading->Color.GetAlpha() / floatNumOfReadings; //we already getting a more precise reading from light sensor
            //++numOfInBoundReadings;
        }
    }

//    for (int i=0; i<m_ColorCam.GetReadings().BlobList.size(); i++) {
//
//        std::cout << "color: " <<(int)m_ColorCam.GetReadings().BlobList[i]->Color.GetAlpha() <<"| angle: " << m_ColorCam.GetReadings().BlobList[i]->Angle << "| dist: " << m_ColorCam.GetReadings().BlobList[i]->Distance<< std::endl;
//    }


    return result;


//    for (int i=0; i< m_Light.GetReadings().size(); ++i) {
//
//    std::cout << "[" << i << "]" << m_Light.GetReadings()[i].Value << std::endl;
//    }



    //const CCI_FootBotLightSensor::TReadings& tReadings = m_Light.GetReadings();

//    if (!apds_.readAmbientLight(result.Ambient))
//    {
//        result.AmbientError = true;
//        Serial.print("[RGBA sensor] - Ambient sensor error");
//    }
//    if(!apds_.readRedLight(result.Red))
//    {
//        result.RedError = true;
//        Serial.print("[RGBA sensor] - Red sensor error");
//    }
//    if(!apds_.readGreenLight(result.Green))
//    {
//        result.GreenError = true;
//        Serial.print("[RGBA sensor] - Green sensor error");
//    }
//    if(!apds_.readBlueLight(result.Blue))
//    {
//        result.BlueError = true;
//        Serial.print("[RGBA sensor] - Blue sensor error");
//    }
//    if(!apds_.readProximity(result.Proximity))
//    {
//        result.ProximityError = true;
//        Serial.print("[RGBA sensor] - Proximity sensor error");
//    }
//    else
//    {
//        //convert proximity to distance (cm)
//        if (result.Proximity < 20) //min bound - read below it is not reliable
//            result.Proximity = 20;
//        result.Distance = 117.55 * pow(result.Proximity, -0.51); //result min val is 6, and max is 25 cm
//    }
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