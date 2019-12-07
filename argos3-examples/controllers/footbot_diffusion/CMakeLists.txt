set (CMAKE_CXX_STANDARD 11)

add_library(footbot_diffusion MODULE footbot_diffusion.h footbot_diffusion.cpp krembot.h krembot_main.h mobile_base.h rgba_sensor.cpp rgba_sensor.h rgb_led.cpp rgb_led.h)
target_link_libraries(footbot_diffusion
  argos3core_simulator
  argos3plugin_simulator_footbot
  argos3plugin_simulator_genericrobot)
