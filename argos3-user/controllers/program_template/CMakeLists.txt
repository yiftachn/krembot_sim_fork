set (CMAKE_CXX_STANDARD 11)

#todo user: rename library
add_library(program_template MODULE
        controller.h
        controller.cpp
        krembot_main.h)

#todo user: rename library
target_link_libraries(program_template
        krembot
  argos3core_simulator
  argos3plugin_simulator_footbot
  argos3plugin_simulator_genericrobot)
