# Krembot Simulator
An Argos-Sim based simulator for Robotican's Krembot robot 

![](demo.gif)

## Note:

* This simulation was tested and intended to work under Ubuntu 16.04.6 LTS

* Whenever `krembot_sim` directory mentioned in this README file, it referes to the root directory of this package.

## Installation

Run the installation script:

```
./krembot_sim/krembot/scripts/install.sh
```

## Uninstall

Run the uninstall script:

```
./krembot_sim/krembot/scripts/uninstall.sh
```


## Sourcing setup_env.sh

This file contain argos enviorment variables, and should be sourced before using argos3.
If installation script finished successfuly, it also automatically source setup_env.sh file for the first time.
After that, whenever you open new terminal, you have to source the file again. This can be done by writing:

```
source ./krembot_sim/krembot/scripts/setup_env.sh
```

To avoid sourcing the file for every new terminal manually, you can add the source command to your .bashrc file.

## Where Do I Go From Here?

1. [Create and run new krembot program](new_program.md)
2. [Use multiple controllers in the same program](multi_controllers.md)
3. [Porting files from real Krembot to simulator, and vice-versa](porting.md) 
4. [Calibrating wheels speed](wheels_calib.md) 
5. [Contribute](CONTRIBUTE.md)
6. [Known issues](known_issues.md)
7. To learn more about controllers, configuration files and how argos works, refer to Argos documentation:
https://www.argos-sim.info/documentation.php

https://github.com/ilpincy/argos3

https://github.com/ilpincy/argos3-examples

































