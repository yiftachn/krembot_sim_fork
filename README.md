# Krembot Simulator

A physics-based 3D simulator for Robotican's Krembot robot.  Original code by 
Elhay Rauper for Bar Ilan University and the [ISF Smart Swarms](http://www.smart-swarms.org) center.  Uses and modifies (and adds to) the [Argos multi-robot simulator](https://www.argos-sim.info/).

![](demo.gif)

## Notes:

* This simulation was tested and intended to work under Linux Ubuntu 16.04.6 LTS/Mint 18.4

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

## Open Source License

[MIT License](LICENSE)

## Where Do I Go From Here?

The [docs/](docs/) folder contains documentation. Including the following topics:

1. [Create and run new krembot program](docs/new_program.md)
2. [Use multiple controllers in the same program](docs/multi_controllers.md)
3. [Porting files from real Krembot to simulator, and vice-versa](docs/porting.md) 
4. [Calibrating wheels speed](docs/wheels_calib.md) 
5. [Contribute](docs/CONTRIBUTE.md)
6. [Known issues](docs/known_issues.md)

To learn more about controllers, configuration files and how argos works, refer to [Argos documentation](https://www.argos-sim.info/documentation.php), the [Argos github repository](https://github.com/ilpincy/argos3), and the [Argos robot examples](https://github.com/ilpincy/argos3-examples).

































