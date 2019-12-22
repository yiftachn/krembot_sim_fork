INSTALLATION:

1. install argos3:

cd /YOUR_HOME_DIR/krembot_sim/argos3/
mkdir build && cd build
cmake ..
sudo make install

souce setup_env.sh file:
source /YOUR_HOME_DIR/krembot_sim/argos3/setup_env.sh

* you can add this command to your .cshrc file in order to execute it automatically for each shell you open

2. install krembot:

cd /YOUR_HOME_DIR/krembot_sim/krembot/
mkdir build && cd build
cmake ..
sudo make install

3. compile argos3-user
cd /YOUR_HOME_DIR/krembot_sim/argos3-user/
mkdir build && cd build
cmake ..
make

DOCUMENTATION:
Argos3-user is the only folder you should be dealing with. You will find a documentation inside that folder (in the README files).

more argos related documentation can be found at the following URLs:
https://www.argos-sim.info/user_manual.php

https://github.com/ilpincy/argos3

https://github.com/ilpincy/argos3-examples

