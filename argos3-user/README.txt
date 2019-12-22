Create a new program:

1. create a new controller inside contollers directory

2. create a new config file inside config directory

* detailed instructions for steps 1 and 2 are in each of the corresponding directories.

3. compile argos3-user (krembot and argos libraries must be compiled before this step)
cd /YOUR_HOME_DIR/krembot_sim/argos3-user/build/

if it's the first time, type:
cmake ..

than type:
make

4. run the simulation by executing the following line from command line:
argos3 -c path/to/your/argos/file.argos

