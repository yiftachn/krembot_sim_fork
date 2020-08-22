## Calibrating Wheels Maximum Speed
The wheels speed was calibrated according to lab experiment with real Krembots hardware.

## Angular speed
A Krembot complete a 180 degrees turn if it turn at full speed (100) for 480 millis.
The two parameters that affect this wanted behavior are - the angular-speed ratio and the time ratio. 

The angular-speed ratio determine by a variable called 
```
MAX_ARGOS_SPEED_ANGULAR
```
which is currently set to 22.
You can change this value if needed in the following file:

```
/krembot_sim/krembot/src/krembot/mobile_base.h
```

### Time calibration
The time ratio determine by a variable called 
```
TIME_RATIO
```
which is currently set to 50.
You can change this value if needed in the following file:

```
/krembot_sim/krembot/src/sant_timer/SandTimer.h
```


## Linear speed
The linear-speed ratio determine by a variable called 
```
MAX_ARGOS_SPEED_LINEAR
```
which is currently set to 25.
You can change this value if needed in the following file:

```
/krembot_sim/krembot/src/krembot/mobile_base.h
```


## Rebuild after 
After changing these values, you must compile the Krembot directory code again by entering the build directory
```
cd /krembot_sim/krembot/src/krembot/build
```

and running 
```
sudo make install 
```


