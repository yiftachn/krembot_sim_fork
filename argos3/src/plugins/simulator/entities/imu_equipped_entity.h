//
// Created by eli on 12/18/19.
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


        inline const CRadians & GetRoll() const {
            return m_Roll; //todo: fix this
        }

        virtual std::string GetTypeDescription() const {
            return "footbot_imu";
        }

    protected:

        CRadians m_Roll;

    };

}


#endif //ARGOS3_SIMULATOR_IMU_EQUIPPED_ENTITY_H
