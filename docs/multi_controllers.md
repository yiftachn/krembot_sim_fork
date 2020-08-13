### Using Multiple Controllers in The Same Configuration File
To simulate flashing different .ino programs to different group of krembots it is possible to execute multiple controllers, where each Krembot or group of krembots execute a specific conroller. 

An example can be found in krembot_ws/config/mixed_controllers.argos file. 
Let's go over the lines in the configuration file that enable running multiple controllers:

The place to list our controllers is under the "controller" tag at line 17. In this example two controllers are listed: 
1. line 19: "simple_demo"
2. line 38: "run_away_by_bumpers"
Listing these controllers here is mandatory, so we set our Krembots to execute them later in this file.

Now that we have the controllers, all there's left to do is to specify what controller should be executed by the Krembots in the arena.
Under the "arena" tag at line 58, two Krembots are listed (krembot_0 at line 74 and krembot_1 at line 79). More Krembot can be created in the same way - copy and paste the krembot block, but pay attention and avoid copy-paste mistakes: the krembot ID (id tag) must be unique, so edit it accordingally. 

Under each of the Krembots (foot-bot tag) there is a "controller" tag. Under this tag you should specify the controller ID you wish to execute on this Krembot. In this example krembot_0 will execute controller "simple_demo" and krembot_1 execute "run_away_by_bumpers". You might set each of the listed Krembots to execute any of the listed controllers. Any combination of controllers and Krembots can be created this way.

Run this configuration file and notice how the two Krembots in the arena behave differntly based on the program they execute.
