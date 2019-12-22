set (CMAKE_CXX_STANDARD 11)

#todo user: rename program
set(PROGRAM_NAME "program_template")

add_definitions(-DKREMBOT_PROGRAM_NAME="${PROGRAM_NAME}_controller")

add_library(${PROGRAM_NAME} MODULE
        controller.h
        controller.cpp
        krembot_main.h)

#todo user: rename library
target_link_libraries(${PROGRAM_NAME}
        krembot
  argos3core_simulator
  argos3plugin_simulator_footbot
  argos3plugin_simulator_genericrobot)
