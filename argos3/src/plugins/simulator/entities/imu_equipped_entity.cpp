//
// Created by elhay rauper
//

#include <argos3/plugins/simulator/entities/imu_equipped_entity.h>
#include <argos3/core/simulator/space/space.h>


namespace argos {

    /****************************************/
    /****************************************/

    CImuEquippedEntity::CImuEquippedEntity(CComposableEntity* pc_parent) :
            CEntity(pc_parent) {}

    /****************************************/
    /****************************************/

    CImuEquippedEntity::CImuEquippedEntity(CComposableEntity* pc_parent,
                                 const std::string& str_id) :
            CEntity(pc_parent, str_id) {}

    /****************************************/
    /****************************************/

    REGISTER_STANDARD_SPACE_OPERATIONS_ON_ENTITY(CImuEquippedEntity);

    /****************************************/
    /****************************************/
}