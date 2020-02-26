/**
 * @file <argos3/plugins/robots/generic/control_interface/ci_proximity_sensor.h>
 *
 * @author Carlo Pinciroli <ilpincy@gmail.com>
 */

#ifndef CCI_PROXIMITY_SENSOR_H
#define CCI_PROXIMITY_SENSOR_H

namespace argos {
   class CCI_ProximitySensor;
}

#include <argos3/core/control_interface/ci_sensor.h>

namespace argos {

   class CCI_ProximitySensor : public CCI_Sensor {

   public:
       struct intersec_t {
           enum Type {
               NONE = 0,
               ROBOT,
               OTHER
           };
           Real prox = 0;
           /**
            * true if intersected entity is robot
            */
           Type type = NONE;

           void operator=(const intersec_t & other) {
               this->prox = other.prox;
               this->type = other.type;
           }
       };

      virtual ~CCI_ProximitySensor() {}

      const std::vector<intersec_t>& GetReadings() const;

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);

      virtual void ReadingsToLuaState(lua_State* pt_lua_state);
#endif

   protected:

      std::vector<intersec_t> m_tReadings;

   };

}

#endif
