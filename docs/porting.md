## Coding for Simulator

To better explain the following principals, let's look at the ```porting_example``` controller located under the controllers folder.
As you can see, this is the ```porting_example``` files tree:
```
$HOME/krembot_ws/controllers/porting_example
                             |-krembot.ino.cpp
                             '-my_code
                                   |-MyCode.h
                                   |-MyCode.cpp
```
The name "MyCode" / "my_code" represents your code directory and files.

### Minimal Code in Main File
It is recommended that the main ```krembot.ino.cpp``` will contain only small number of code lines. Most of the code should be written into a separate files (preferably in a separate directory). Let's see how it's done in the ```porting_example/krembot.ino.cpp```:

```
MyCode myCode{krembot};

void setup() {
    krembot.setup();

}

void loop() {
    krembot.loop();

    myCode.doSomething();
}
```

As you can see, in this example the main file contain only the mandatory ```krembot.setup()``` and ```krembot.loop()``` lines, and another line to execute the example code: ```myCode.doSomething();```. The majority of the code is written inside the ```my_code``` directory. This results in a more modular and "main independent" code.

## Moving to Real Krembot 

### Method 1:
After some simulation testing, we're now ready to run our code on the real robot. To do so, follow these steps:
- Change the ```krembot.ino.cpp``` file name into ```krembot.ino```. This file contain CPP macros that add/remove code according to the compilation environment (simulator / real hardware).
- Change the path in line 43: ```#include "Krembot/krembot.h"``` to the path of the Robotican's (real hardware) Krembot repository. For example: if Robotican's Krembot repository was installed under ```/home/```, you should change this line to  ```#include "/.../.../.../.../krembot/Src/Krembot/krembot.h"```
- Flash ```porting_example/krembot.ino``` to the Krembot

### Method 2:
- Go to the ```krembot_main.ino``` file inside Robotican's Krembot repository
- Copy the code from ```porting_example/krembot.ino.cpp``` into ```krembot_main.ino```
- Change the ```#include``` paths in ```krembot_main.ino``` to point to your files under ```porting_example``` directory.

