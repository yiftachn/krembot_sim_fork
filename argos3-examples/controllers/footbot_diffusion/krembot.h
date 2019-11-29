#ifndef KREMBOT_BRIDGE_H
#define KREMBOT_BRIDGE_H



#include <argos3/core/control_interface/ci_controller.h>
/* Definition of the differential steering actuator */
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
/* Definition of the foot-bot proximity sensor */
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>
#include <argos3/core/utility/math/vector2.h>
#include "mobile_base.h"
#include "rgba_sensor.h"

/*
 * All the ARGoS stuff in the 'argos' namespace.
 * With this statement, you save typing argos:: every time.
 */
using namespace argos;


class Krembot {

public:

    RGBASensor RgbaFront;
    RGBASensor RgbaRear;
    RGBASensor RgbaRight;
    RGBASensor RgbaLeft;
    RGBASensor RgbaFrontRight;
    RGBASensor RgbaFrontLeft;
    RGBASensor RgbaRearRight;
    RGBASensor RgbaRearLeft;

    MobileBase Base;
//    CBumpers Bumpers;
//    Battery Bat;
//    RGBLed Led;
//    IMUSensor Imu;

    Krembot(CCI_DifferentialSteeringActuator& wheels,
            CCI_FootBotProximitySensor& proximity)  :
            Base(wheels),
            RgbaFront("RgbaFront", proximity.GetReadings()[0]),
            RgbaFrontRight("RgbaFrontRight", proximity.GetReadings()[1]),
            RgbaRight("RgbaRight", proximity.GetReadings()[2]),
            RgbaRearRight("RgbaRearRight", proximity.GetReadings()[3]),
            RgbaRear("RgbaRear", proximity.GetReadings()[4]),
            RgbaRearLeft("RgbaRearLeft", proximity.GetReadings()[5]),
            RgbaLeft("RgbaLeft", proximity.GetReadings()[6]),
            RgbaFrontLeft("RgbaFrontLeft", proximity.GetReadings()[7])
//            m_pcProximity(proximity),
//            m_cAlpha(7.5f),
//            m_fDelta(0.1f),
//            m_fWheelVelocity(5.0f),
//            m_cGoStraightAngleRange(-ToRadians(m_cAlpha),
//                               ToRadians(m_cAlpha))
    {

    }

    
    void setup() {
//        m_cGoStraightAngleRange.Set(-ToRadians(m_cAlpha), ToRadians(m_cAlpha));
    }


    void loop() {

//        const CCI_FootBotProximitySensor::TReadings& tProxReads = m_pcProximity.GetReadings();
//        for(size_t i = 0; i < tProxReads.size(); ++i) {
//            std::cout << "{ i: " << i <<"| val: " << tProxReads[i].Value << "| ang: " << ((tProxReads[i].Angle.GetValue() * 180.0) / M_PI) << " }" << std::endl;
//        }

        std::cout << RgbaFront.readRGBA().Proximity << std::endl;


        // /* Get readings from proximity sensor */
        // const CCI_FootBotProximitySensor::TReadings& tProxReads = m_pcProximity.GetReadings();
        // /* Sum them together */
        // CVector2 cAccumulator;
        // for(size_t i = 0; i < tProxReads.size(); ++i) {
        //     cAccumulator += CVector2(tProxReads[i].Value, tProxReads[i].Angle);
        // }
        // cAccumulator /= tProxReads.size();
        // /* If the angle of the vector is small enough and the closest obstacle
        //     * is far enough, continue going straight, otherwise curve a little
        //     */
        // CRadians cAngle = cAccumulator.Angle();
        // if(m_cGoStraightAngleRange.WithinMinBoundIncludedMaxBoundIncluded(cAngle) &&
        //     cAccumulator.Length() < m_fDelta ) {
        //     /* Go straight */
        //     m_pcWheels.SetLinearVelocity(m_fWheelVelocity, m_fWheelVelocity);
        // }
        // else {
        //     /* Turn, depending on the sign of the angle */
        //     if(cAngle.GetValue() > 0.0f) {
        //         m_pcWheels.SetLinearVelocity(m_fWheelVelocity, 0.0f);
        //     }
        //     else {
        //         m_pcWheels.SetLinearVelocity(0.0f, m_fWheelVelocity);
        //     }
        // }
    }
};

#endif