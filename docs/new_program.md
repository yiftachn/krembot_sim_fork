## Creating New Krembot Program
To create a new program, you'll need to create a new controller, and configuration file.

### Controller
This plugin was designed to be as close as possible to working on real hardware both in terms of simulation and code architecture. Coming from real Krembot hardware, you probably know that .ino file is used as a "main" file. In Argos the main file is called "controller". This plugin hides most of the controller boiler plate code, and makes the controller file look very similar to an ordinary .ino file. 
Go into ```./krembot_sim/argos3-user/controllers``` and check out the example controllers.

### Configuration Files
Argos simulation allows the user to configure the simulation environment, this is done inside a ```.argos``` configuration file. Some configuration are mandatory (e.g. what controllers should the simulator load), and some are not (e.g. the names of the robots). Go inside ```./krembot_sim/argos3-user/config/``` and check out the example configuration files.

The simulator execution command include the configuration file to use. This enables the simulator to load a specific set of user configuration.

## Directories Tree
There are 3 main directories in the package:
1. ***argos3*** - contain argos simulation files
2. ***krembot*** - contain krembot library simulation files
3. ***argos3-user*** - this folder is for your use, and for most cases, it should be the only one you deal with during development

The controller and configuration files are stored in a dedicated directories inside ```argos3-user``` directory:
- config - contain configuration files
- controllers - contain controllers


### Creating New Controller
1. Go into ```./krembot_sim/argos3-user/controllers```
2. Inside that directory, you will find ```program_template``` directory, that contains a template code files for krembot program. Those code files will be executed by the simulation the same way as ino file does on real krembot.
3. Create a copy of the ```program_template``` directory, and give it a name that describes your program.
4. Go inside the directory created in step 3, open CMakeList and change line 4 - replace "program_template" with the name you gave this directory in step 3. If your program contain more cpp files than just the ino, this is also the place to list them - go head and write those files under line 10. Save and close. 
5. Go into krembot.ino.cpp file. You can treat this as your .ino file. Add your code to this file. The places where you should put your code in are marked with "todo:" tags.
6. Go into the controllers directory again (step 1), open CMakeLists.txt inside that directory, and add your directory name to the list with ```add_subdirectory``` command. Save and close.

### Compiling the Controller
We are ready to compile your code, so go into ```./krembot_sim/argos3-user/build```, and write ```make``` in the termial

### Creating New Argos Configuration File
1. Cd into  ```./krembot_sim/argos3-user/config/```
2. Create a copy of the ```program_template.argos``` file, and give it the same name you gave your program inside your controllers CMakeFiles.txt
3. Replace ```program_template``` everywhere in the file with your program name from step 2
4. In line 53 provide full path to your controller .so file. This file can be found in ```argos3-user/build/your_program``` directory after building your code.
5. Further changes in this file can be made to configure simulation. The file is well-documented, so it should be relavily easy. More documentation can be found at https://www.argos-sim.info/documentation.php

### Running Your Controller
In order to run argos simulation, your should use ```argos3``` command along with ```-c``` flag and the path to your program .argos configuration file. Before you use this command, make sure you sourced the setup_env.sh file (see instructions above). 

```
argos3 -c path/to/your/argos/file.argos
```

In case you see an error telling you that ```libyour_program.so``` could'nt be found, make sure the path you provided to the .so file inside the configuration file is correct. If it is, then read the error carefully - sometimes code linking errors are hiding in this error message, and you might miss them at first glance.

### Editing Krembot Library Code
For some cases, you may want to edit the krembot library code. After editing the code, cd into krembot/build directory, and compile using

```
sudo make install
```

This will compile the code, and then install the updated header files under /usr/local/include/ , and the .so file under /usr/local/bin/