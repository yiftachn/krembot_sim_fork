# Krembot Simulator

A physics-based 3D simulator for Robotican's Krembot robot.  Original code by 
Elhay Rauper for Bar Ilan University and the [ISF Smart Swarms](http://www.smart-swarms.org) center.  Uses and modifies (and adds to) the [Argos multi-robot simulator](https://www.argos-sim.info/).

![](demo.gif)

## Notes:

* This simulation was tested and intended to work under Linux Ubuntu 16.04.6 LTS/Mint 18.4

* Whenever `krembot_sim` directory mentioned in this README file, it referes to the root directory of this package.

## Directories Tree

There are 3 main directories in the package:

1. ***argos3*** - contain argos simulation files
2. ***krembot*** - contain krembot library simulation files
3. ***krembot_ws*** - this folder is an example workspace for creating krembot programs. You copy it to your own workspace (see [Creating New Programs](docs/new_program.md).

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

## Open Source License

[MIT License](LICENSE)

## Where Do I Go From Here?

The [docs/](docs/) folder contains documentation. Including the following topics:

1. [Install Krembot Woekspace](docs/install_workspace.md)
2. [Create and run new krembot program](krembot_ws/README.md)
3. [Use multiple controllers in the same program](docs/multi_controllers.md)
4. [Porting files from real Krembot to simulator, and vice-versa](docs/porting.md) 
5. [Calibrating wheels speed](docs/wheels_calib.md) 
6. [Contribute](docs/CONTRIBUTE.md)
7. [Known issues](docs/known_issues.md)

To learn more about controllers, configuration files and how argos works, refer to [Argos documentation](https://www.argos-sim.info/documentation.php), the [Argos github repository](https://github.com/ilpincy/argos3), and the [Argos robot examples](https://github.com/ilpincy/argos3-examples).

































