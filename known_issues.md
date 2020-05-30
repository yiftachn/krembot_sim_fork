### Known Issues

#### Particle Library

Particle library contain lots of APIs. It's impossible (nor necessary) to support all of them as part of the scope of this project. Hence, this simulator supports only few basic features of it.

#### delay() function

delay shouldn't be used (on both real hardware and simulator) because during the delay time the robot can't keep sensing or acting on the inviorment. Instead, a timer should be used (each delay can be easily replaced by a timer). Further more, implementation of such function in Argos simulation will cause more issues like frozen GUI, and eventually unresponsive application. Therefore delay() function is not supported by the simulator. Instead, a timer library called "Sand Timer" is provided, and can be used in the same way it is used in real Krembot.

#### Particle.publish()

***tl;dr***
```Particle.publish()``` API is only accessible from krembot.ino.cpp file.

In real Photon chip, a single instance of Particle object is created, which contains information about the Photon chip. Each robot have its own memory space, which isn't shared with other robots. Argos achieves similar results by creating and running controller instances. Particle's API to publish message is ```Particle.publish```, this means that we have to create a global Particle object in order to allow all client's code to call this API. Doing this will cause all controller's (and in turn Krembot) instances to use the same Particle object, which is incorrect since Particle have to hold internal data about a specific krembot instance (such as ID). 

However, it's possible to create Particle object as part of the controller, such that for each instance a new Particle instance will be created with a specific krembot data. This implemetation solves the problem, but also means the user is limited to use this API only inside krembot.ino.cpp file.

### Sensors Behavior 

Some of the Krembot sensors behave diffrently in reality than normally expected. Those sensors are simulated in the same way (This is not a simulation limitation, but a requirement)

#### Proximity (IR) Sensor 

Normally, this sensor should measure the distance to the closest object in front of it. Real Krembot hardware return maximum distance when another krembot is in front of the sensor, and distance to object for something other than krembot. The same behavior is implemented in the simulator. 

Argos bug - Proximity sensor will not detect intersection with another object if it is too close to it (passed contact point). This influence both proximity and bumpers which are implemented based on this sensor.

#### Bumpers 

Normally, this sensor should return "true" whenever the bumper is close enough to an object. Real Krembot hardware bumper is only pressed when a certain amount of force is applied to it. The same behavior is implemented in the simulator. 