// This code based on Robotican's demo - "RunAwayByBumpers"

/*
 * This file simulates the .ino file of the krembot.
 * The original structure of this file must be maintained
 * for the simulator to work correctly
 */

#ifndef IKREMBOT_LOOP_H
#define IKREMBOT_LOOP_H

#include <krembot/krembot.h>
#include <argos3/core/control_interface/ci_controller.h>
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>

#include <krembot/SandTimer.h>
#include <krembot/SerialSim.h>

using namespace argos;

class KrembotMain {
protected:
    Krembot & krembot;
    SerialSim Serial;

public:
    KrembotMain(Krembot & krembot_in) : krembot(krembot_in) {}


    SandTimer backTimer;
    SandTimer turnTimer;


    BumpersRes lastResults;

    const int FORWARD_SPEED = 60;
    const int BACKWARD_SPEED = -60;


    const int LEFT_SPEED = 75;
    const int RIGHT_SPEED = -75;

    const int BACK_INTERVAL = 450;
    const int TURN_INTERVAL = 800;

    bool drivingForward = false;
    bool drivingBack = false;
    bool turning = false;

    virtual void setup() {
        krembot.setup();

        // start driving forward
        krembot.Base.drive(FORWARD_SPEED, 0);
        backTimer.start(BACK_INTERVAL);
        turnTimer.start(TURN_INTERVAL);

    }

    virtual void loop() {
        krembot.loop();

        krembot.loop();

        // read bumpre states
        BumpersRes results = krembot.Bumpers.read();
        if (results.isAnyPressed())
        {
            // if one of the bumpers was pressed check which one was pressed. based on the
            // bumper that was pressed. if it was one of the front bumpers - switch to
            // drivingBack mode for 450 miliseconds
            if(results.front == BumperState::PRESSED || results.front_left == BumperState::PRESSED || results.front_right == BumperState::PRESSED)
            {
                krembot.Base.drive(BACKWARD_SPEED, 0);
                backTimer.startOver();
                drivingBack = true;
                turning = false;
                krembot.Led.write(255,0,0);

                krembot.Bumpers.print();

            }
                //if the pressed bumper is not one of the front ones
                // switch to turn mode for 450 miliseconds
            else
            {
                drivingBack = false;
                turning = true;
                turnTimer.startOver();
            }

            lastResults = results;

        }


        //if the finished turning disable turning mode
        if(turnTimer.finished() && turning)
        {
            turning = false;
            drivingBack = false;
            krembot.Led.write(0,255,0);

        }

        // if finished driving back, switch to turning mode
        if(backTimer.finished() && drivingBack)
        {
            drivingBack = false;
            turning = true;
            turnTimer.startOver();
            krembot.Led.write(0,0,255);

        }


        //decide the turning direction based on the pressed BUMPER_REAR_LEFT
        // if it was on the right side (or the front bumper) turn left.
        // if it was one of the left side - turn right
        if(turning)
        {
            krembot.Led.write(255,255,255);

            if(lastResults.front == BumperState::PRESSED)
            {
                // we chose to turn left
                krembot.Base.drive(0, LEFT_SPEED);
            }
            else if(lastResults.front_right == BumperState::PRESSED)
            {
                // we chose to turn left
                krembot.Base.drive(0, LEFT_SPEED);
            }
            else if(lastResults.right == BumperState::PRESSED)
            {
                krembot.Base.drive(0, LEFT_SPEED);
            }
            else if(lastResults.rear_right == BumperState::PRESSED)
            {
                krembot.Base.drive(0, LEFT_SPEED);
            }
            else if(lastResults.rear == BumperState::PRESSED)
            {
                krembot.Base.drive(FORWARD_SPEED, 0);
            }
            else if(lastResults.rear_left == BumperState::PRESSED)
            {
                krembot.Base.drive(0, RIGHT_SPEED);
            }
            else if(lastResults.left == BumperState::PRESSED)
            {
                krembot.Base.drive(0, RIGHT_SPEED);
            }
            else if(lastResults.front_left == BumperState::PRESSED)
            {
                krembot.Base.drive(0, RIGHT_SPEED);
            }

        }

        //if not turning and not driving - drive forward
        if(!turning && !drivingBack)
        {
            krembot.Base.drive(FORWARD_SPEED, 0);
            krembot.Led.write(0,0,0);
        }
    }
};

#endif 