//
// Created by elhay rauper
//

#ifndef ARGOS3_SIMULATOR_IMU_EQUIPPED_ENTITY_H
#define ARGOS3_SIMULATOR_IMU_EQUIPPED_ENTITY_H

namespace argos {
    class CImuEquippedEntity;
}

#include <argos3/core/simulator/entity/entity.h>
#include <argos3/core/utility/math/angles.h>


namespace argos {

    class CImuEquippedEntity : public CEntity {
    public:
        ENABLE_VTABLE();

    public:

        CImuEquippedEntity(CComposableEntity* pc_parent);

        CImuEquippedEntity(CComposableEntity* pc_parent,
                            const std::string& str_id);

        virtual ~CImuEquippedEntity() {}

        virtual void Init(TConfigurationNode& t_tree) {};

        virtual void Reset() { };

        virtual std::string GetTypeDescription() const {
            return "footbot_imu";
        }

    };

}


#endif //ARGOS3_SIMULATOR_IMU_EQUIPPED_ENTITY_H
