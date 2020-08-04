## Calibrating Wheels Maximum Speed
The wheels speed was calibrated according to lab experiment with real Krembots hardware: it took the Krembot about ~500 millis in full speed (100%) to complete a 180 degrees turn.

Currently the max wheels speed is set to 36 cm/sec in order to match the experiment results.
You can change this value if needed in the following file:

```
.../krembot_sim/krembot/src/krembot/mobile_base.h
```

The variable is called 

```
MAX_ARGOS_SPEED
```

After changing the value, you must compile the Krembot directory code again by entering the build directory
```
cd .../krembot_sim/krembot/src/krembot/build
```

and running 
```
sudo make install 
```


