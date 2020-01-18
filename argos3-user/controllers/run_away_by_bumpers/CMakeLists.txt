#todo user: rename program
set(PROGRAM_NAME "run_away_by_bumpers")

add_definitions(-DKREMBOT_PROGRAM_NAME="${PROGRAM_NAME}_controller")

add_library(${PROGRAM_NAME} MODULE
        controller.h
        controller.cpp
        krembot_main.h)

#todo user: rename library
target_link_libraries(${PROGRAM_NAME}
        Krembot
        argos3core_simulator
        argos3plugin_simulator_footbot
        argos3plugin_simulator_genericrobot)
