set (CMAKE_CXX_STANDARD 11)

#todo user: rename library
add_library(run_away_by_bumpers MODULE
        controller.h
        controller.cpp
        krembot_main.h)

#todo user: rename library
target_link_libraries(run_away_by_bumpers
        krembot
  argos3core_simulator
  argos3plugin_simulator_footbot
  argos3plugin_simulator_genericrobot)
