/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Fri Dec 1 2023                                            */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// gamers               controller
// fl                   motor         15
// fr                   motor         17
// bl                   motor         5
// br                   motor         10
// ml                   motor         7
// mr                   motor         4
// L                    motor_group
// R                    motor_group
// intake               motor         16
// D                    rotation      6
// inert                inertial      3
// wings                pneumatics    A
// fly                  pneumatics    B
// cata                 motor         2
// flywheel             motor         12
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "autons.hpp"
#include "pid.hpp"
using namespace vex;
using namespace std;

/*   __   ______     __    ________    __   ____      
 /'_ `\/\  ___\  /'__`\ /\_____  \ /'__`\/\  _`\    
/\ \L\ \ \ \__/ /\ \/\ \\/___//'/'/\ \/\ \ \ \L\ \  
\ \___, \ \___``\ \ \ \ \   /' /' \ \ \ \ \ \  _ <' 
 \/__,/\ \/\ \L\ \ \ \_\ \/' /'    \ \ \_\ \ \ \L\ \
      \ \_\ \____/\ \____/\_/       \ \____/\ \____/
       \/_/\/___/  \/___/\//         \/___/  \/___/ 
                                                    
*/

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  setv(100);
  setcoast();
  wingactionb();
  D.setPosition(0,turns);
  E.setPosition(0,turns);
  climb.close();
  inert.calibrate();
  if(inert.isCalibrating()) gamers.rumble(rumblePulse);
  cout << "hi" << endl;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  if (auton == 1) {
    auton1();
  } else if (auton == 2) {
    auton2();
  } else if (auton == 3) {
    auton3();
  } else if (auton == 4) {
    auton4();
  } else if (auton == 5) {
    auton5();
  } else if (auton == 6) {
    auton6();
  }
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

bool a = 0;
double sen = 1;
//user control
void usercontrol(void) {
  //User control code here, inside the loop
  while (!a) {
    autonslctr();
    if (gamers.ButtonB.pressing()) a = 1;
  }
  while (a) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    
    //(turn,fwdrev)
    if(gamers.ButtonL1.pressing()) {
      sen = 0.35;
    } else if (gamers.ButtonL2.pressing()) {
      sen = 0.7;
    } else {
      sen = 1;
    }

    if (modes) {
      dtcode(0.2*sen,-2*sen);
    } else if (!modes) {
      dtcode(0.2*sen,2*sen);
    }

    //toggle flywheel
    if(gamers.ButtonX.pressing()) airborne = !airborne;

    //wings
    gamers.ButtonX.pressed(wingactiona);
    gamers.ButtonY.pressed(wingactionb);

    //lifting
    gamers.ButtonUp.pressed(up);
    gamers.ButtonDown.pressed(down);

    //change brake modes
    if (gamers.ButtonB.pressing()) modes = !modes;

    modechange();

    //other stuff
    liftoff();
    catamoving();
    tempcheck();
    intaking();
    // ........................................................................
    wait(11,msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

// Main will set up the competition functions and callbacks.
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  
  
  // Run the pre-autonomous function.
  pre_auton();
  // Prevent main from exiting with an infinite loop.
  while (1) {
    /*if(Competition.DISABLE) {
      printing("you better be ready");
    }*/
    wait(10,msec);
  }
}