

#
# Krembot headers
#
# argos3/plugins/robots/krembot/control_interface
set(ARGOS3_HEADERS_PLUGINS_ROBOTS_KREMBOT_CONTROLINTERFACE
        control_interface/ci_krembot_base_ground_sensor.h
        control_interface/ci_krembot_distance_scanner_actuator.h
        control_interface/ci_krembot_distance_scanner_sensor.h
        control_interface/ci_krembot_encoder_sensor.h
        control_interface/ci_krembot_light_sensor.h
        control_interface/ci_krembot_motor_ground_sensor.h
        control_interface/ci_krembot_proximity_sensor.h
        control_interface/ci_krembot_turret_actuator.h
        control_interface/ci_krembot_turret_encoder_sensor.h)
# argos3/plugins/robots/krembot/simulator
if(ARGOS_BUILD_FOR_SIMULATOR)
  set(ARGOS3_HEADERS_PLUGINS_ROBOTS_KREMBOT_SIMULATOR
          simulator/dynamics2d_krembot_model.h
    simulator/pointmass3d_krembot_model.h
    # simulator/physx_krembot_model.h
          simulator/krembot_base_ground_rotzonly_sensor.h
          simulator/krembot_distance_scanner_default_actuator.h
          simulator/krembot_distance_scanner_equipped_entity.h
          simulator/krembot_distance_scanner_rotzonly_sensor.h
          simulator/krembot_entity.h
          simulator/krembot_light_rotzonly_sensor.h
          simulator/krembot_motor_ground_rotzonly_sensor.h
          simulator/krembot_proximity_default_sensor.h
          simulator/krembot_turret_default_actuator.h
          simulator/krembot_turret_encoder_default_sensor.h
          simulator/krembot_turret_entity.h)
endif(ARGOS_BUILD_FOR_SIMULATOR)

#
# Foot-bot sources
#
set(ARGOS3_SOURCES_PLUGINS_ROBOTS_KREMBOT
  ${ARGOS3_HEADERS_PLUGINS_ROBOTS_KREMBOT_CONTROLINTERFACE}
        control_interface/ci_krembot_base_ground_sensor.cpp
        control_interface/ci_krembot_distance_scanner_actuator.cpp
        control_interface/ci_krembot_distance_scanner_sensor.cpp
        control_interface/ci_krembot_encoder_sensor.cpp
        control_interface/ci_krembot_light_sensor.cpp
        control_interface/ci_krembot_motor_ground_sensor.cpp
        control_interface/ci_krembot_proximity_sensor.cpp
        control_interface/ci_krembot_turret_actuator.cpp
        control_interface/ci_krembot_turret_encoder_sensor.cpp)

if(ARGOS_BUILD_FOR_SIMULATOR)
  set(ARGOS3_SOURCES_PLUGINS_ROBOTS_KREMBOT
    ${ARGOS3_SOURCES_PLUGINS_ROBOTS_KREMBOT}
    ${ARGOS3_HEADERS_PLUGINS_ROBOTS_KREMBOT_SIMULATOR}
          simulator/dynamics2d_krembot_model.cpp
    simulator/pointmass3d_krembot_model.cpp
    # simulator/physx_krembot_model.cpp
          simulator/krembot_base_ground_rotzonly_sensor.cpp
          simulator/krembot_distance_scanner_default_actuator.cpp
          simulator/krembot_distance_scanner_equipped_entity.cpp
          simulator/krembot_distance_scanner_rotzonly_sensor.cpp
          simulator/krembot_entity.cpp
          simulator/krembot_light_rotzonly_sensor.cpp
          simulator/krembot_motor_ground_rotzonly_sensor.cpp
          simulator/krembot_proximity_default_sensor.cpp
          simulator/krembot_turret_default_actuator.cpp
          simulator/krembot_turret_encoder_default_sensor.cpp
          simulator/krembot_turret_entity.cpp)
  # Compile the graphical visualization only if the necessary libraries have been found
  if(ARGOS_COMPILE_QTOPENGL)
    set(ARGOS3_HEADERS_PLUGINS_ROBOTS_KREMBOT_SIMULATOR
      ${ARGOS3_HEADERS_PLUGINS_ROBOTS_KREMBOT_SIMULATOR}
      simulator/qtopengl_krembot.h)
    set(ARGOS3_SOURCES_PLUGINS_ROBOTS_KREMBOT
      ${ARGOS3_SOURCES_PLUGINS_ROBOTS_KREMBOT}
      simulator/qtopengl_krembot.h
      simulator/qtopengl_krembot.cpp)
  endif(ARGOS_COMPILE_QTOPENGL)
endif(ARGOS_BUILD_FOR_SIMULATOR)

#
# Create krembot plugin
#
add_library(argos3plugin_${ARGOS_BUILD_FOR}_krembot SHARED ${ARGOS3_SOURCES_PLUGINS_ROBOTS_KREMBOT})
target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_krembot
  argos3plugin_${ARGOS_BUILD_FOR}_genericrobot
  argos3plugin_${ARGOS_BUILD_FOR}_dynamics2d
  argos3plugin_${ARGOS_BUILD_FOR}_pointmass3d)
  # argos3plugin_${ARGOS_BUILD_FOR}_physx)
if(ARGOS_COMPILE_QTOPENGL)
  target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_krembot argos3plugin_${ARGOS_BUILD_FOR}_qtopengl)
endif(ARGOS_COMPILE_QTOPENGL)

install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_KREMBOT_CONTROLINTERFACE} DESTINATION include/argos3/plugins/robots/krembot/control_interface)

if(ARGOS_BUILD_FOR_SIMULATOR)
  install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_KREMBOT_SIMULATOR}      DESTINATION include/argos3/plugins/robots/krembot/simulator)
endif(ARGOS_BUILD_FOR_SIMULATOR)

install(TARGETS argos3plugin_${ARGOS_BUILD_FOR}_krembot
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib/argos3
  ARCHIVE DESTINATION lib/argos3)
