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
// fl                   motor         1
// fr                   motor         2
// ml                   motor         9
// mr                   motor         10
// bl                   motor         3
// br                   motor         4
// L                    motor_group
// R                    motor_group
// intake               motor         6
// D                    rotation      16
// inert                inertial      11
// wings                pneumatics    A
// fly                  pneumatics    B
// cata                 motor         13
// flywheel             motor         12
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "autons.hpp"

using namespace vex;

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
  setcoast();
  wingactionb();
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
  } else if( auton == 3) {
    auton3();
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

//user control
void usercontrol(void) {
  //User control code here, inside the loop
  while (!a) {
    // select auton
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
    if (modes) {
      dtcode(0.27,-2);
    } else if (!modes) {
      dtcode(0.27,2);
    }

    //toggle flywheel
    if(gamers.ButtonX.pressing()) airborne = !airborne;

    //wings
    gamers.ButtonL1.pressed(wingactiona);
    gamers.ButtonL2.pressed(wingactionb);

    //change brake modes
    if (gamers.ButtonB.pressing()) modes = !modes;

    //change driving modes
    gamers.ButtonA.pressed(modechange);

    //other stuff
    liftoff();
    catamoving();
    tempcheck();
    intakecontrol();
    // ........................................................................
    wait(20,msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

// Main will set up the competition functions and callbacks.
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  Competition.disable(autonslctr);
  
  // Run the pre-autonomous function.
  pre_auton();
  // Prevent main from exiting with an infinite loop.
  while (1) wait(100,msec);
}