/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VY                                                        */
/*    Created:      Fri Dec 1 2023                                            */
/*    Description:  Over Under 95070B :)                                      */
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
#include "functions.hpp"
using namespace vex;
using namespace std;

// A global instance of competition
competition Competition;

/*   __   ______     __    ________    __   ____      
 /'_ `\/\  ___\  /'__`\ /\_____  \ /'__`\/\  _`\    
/\ \L\ \ \ \__/ /\ \/\ \\/___//'/'/\ \/\ \ \ \L\ \  
\ \___, \ \___``\ \ \ \ \   /' /' \ \ \ \ \ \  _ <' 
 \/__,/\ \/\ \L\ \ \ \_\ \/' /'    \ \ \_\ \ \ \L\ \
      \ \_\ \____/\ \____/\_/       \ \____/\ \____/
       \/_/\/___/  \/___/\//         \/___/  \/___/ 
*/

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
  timer t; // timing auton for practice
  t.clear();
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
  cout << t.time() << endl;
  // ..........................................................................
}

bool a = 0; // auton selector boolean
bool poopy = 1; // driving selection
bool morepoopy = 1; // calibration
int drivemode = 0; // driving mode



/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
  thread arcade = thread(dcode);
  // User control code here, inside the loop
  if (morepoopy) {
    inert.calibrate();
    waitUntil(!inert.isCalibrating());
    morepoopy = 0;
    gamers.rumble(rumbleLong);
  }
  while (!a) {
    if (poopy) {
      autonslctr();
    } else {
      if (gamers.ButtonA.pressing()) {
        drivemode = 0; 
        printing("arcade");
      } 
      if (gamers.ButtonY.pressing()) {
        drivemode = 1;
        printing("tank");
      }
      if (gamers.ButtonX.pressing()) {
        drivemode = 2;
        printing("IM VENGEANCE");
      } 
      if (gamers.ButtonDown.pressing()) cin >> drivemode;
    }
    if (gamers.ButtonB.pressing()) {
      a = 1;
    }
  }
  while (a) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    
    // arcade
    if (drivemode == 0) {
      dcode();
    } else if (drivemode == 1) {
      dtcode();
    } else if (drivemode == 2) {
      batmobile();
    }

    // wings
    gamers.ButtonY.pressed(wingaction);
    gamers.ButtonY.released(flap);

    // lifting
    gamers.ButtonUp.pressed(up);
    gamers.ButtonDown.pressed(down);

    // new matchloading
    gamers.ButtonX.pressed(punching);
    gamers.ButtonX.released(notpunching);

    // ........................................................................
    wait(10,msec);  // Sleep the task for a short amount of time to
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
    wait(10,msec);
  }
}