#!/bin/sh

KREMBOT_SIM_PATH="$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )"/../..

#echo "detected KREMBOT_SIM_PATH as $KREMBOT_SIM_PATH"; echo;

export ARGOS_PLUGIN_PATH=$KREMBOT_SIM_PATH/argos3/build_simulator/core:$KREMBOT_SIM_PATH/argos3/build_simulator/testing:$KREMBOT_SIM_PATH/argos3/build_simulator/plugins/robots/e-puck:$KREMBOT_SIM_PATH/argos3/build_simulator/plugins/robots/eye-bot:$KREMBOT_SIM_PATH/argos3/build_simulator/plugins/robots/foot-bot:$KREMBOT_SIM_PATH/argos3/build_simulator/plugins/robots/generic:$KREMBOT_SIM_PATH/argos3/build_simulator/plugins/robots/prototype:$KREMBOT_SIM_PATH/argos3/build_simulator/plugins/robots/spiri:$KREMBOT_SIM_PATH/argos3/build_simulator/plugins/simulator/visualizations/qt-opengl:$KREMBOT_SIM_PATH/argos3/build_simulator/plugins/simulator/entities:$KREMBOT_SIM_PATH/argos3/build_simulator/plugins/simulator/physics_engines/dynamics2d:$KREMBOT_SIM_PATH/argos3/build_simulator/plugins/simulator/physics_engines/dynamics3d:$KREMBOT_SIM_PATH/argos3/build_simulator/plugins/simulator/physics_engines/pointmass3d:$KREMBOT_SIM_PATH/argos3/build_simulator/plugins/simulator/media

export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${ARGOS_PLUGIN_PATH}:/usr/local/lib/
