/**
 * @file <argos3/plugins/robots/foot-bot/simulator/footbot_proximity_default_sensor.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef KREMBOT_PROXIMITY_DEFAULT_SENSOR_H
#define KREMBOT_PROXIMITY_DEFAULT_SENSOR_H

#include <string>
#include <map>

namespace argos {
   class CKrembotProximityDefaultSensor;
}

#include <argos3/plugins/robots/krembot/control_interface/ci_krembot_proximity_sensor.h>
#include <argos3/plugins/robots/generic/simulator/proximity_default_sensor.h>

namespace argos {

   class CKrembotProximityDefaultSensor : public CCI_KrembotProximitySensor,
                                          public CSimulatedSensor {

   public:

      CKrembotProximityDefaultSensor();

      virtual ~CKrembotProximityDefaultSensor();

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Update();

      virtual void Reset();

   private:

      CProximityDefaultSensor* m_pcProximityImpl;

   };

}

#endif
