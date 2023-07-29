/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// fl                   motor         1               
// fr                   motor         2               
// bl                   motor         3               
// br                   motor         4               
// Controller1          controller                    
// intake               motor_group   6, 5            
// flex                 digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "autons.hpp"
#include "odom.hpp"

using namespace vex;

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


bool a = 0;

int numofautons = 3;

void printing(std::string text) {
  gamers.Screen.clearScreen();
  gamers.Screen.setCursor(1,1);
  gamers.Screen.print(text.c_str());
}

int auton = 1;
void autonslctr() {
  if(auton < 1) {
    auton = numofautons;
  }
  if(auton > numofautons) {
    auton = 1;
  }
  if(auton == 1) {
    printing("Auton 1");
  }
  if(auton == 2) {
    printing("Auton 2");
  }
  if(auton == 3) {
    printing("Auton 3");
  }
  if(gamers.ButtonRight.pressing()) {
    auton++;
    wait(200,msec);
  }
  else if(gamers.ButtonLeft.pressing()) {
    auton--;
    wait(200,msec);
  }
}

void autonomous(void) {

  // ..........................................................................
  // Insert autonomous user code here.

  if(auton == 1) {
    auton1();
  }
  else if(auton == 2) {
    auton2();
  }
  else if(auton == 3) {
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

void dtcode(double x, double y) {
  double rightspeed = (gamers.Axis3.position() * y) + (gamers.Axis4.position() * -x); //calculate the right speed
  double leftspeed = (gamers.Axis3.position() * y) - (gamers.Axis4.position() * -x); //calculate the left speed
  fl.spin(forward, leftspeed, percent); //set the left motor speed
  ml.spin(forward,leftspeed,percent); //set the left motor speed
  bl.spin(forward, leftspeed, percent); //set the left motor speed
  fr.spin(forward, rightspeed, percent); //set the right motor speed
  mr.spin(forward,rightspeed,percent); //set the right motor speed
  br.spin(forward, rightspeed, percent); //set the right motor speed
}

void usercontrol(void) {
  // User control code here, inside the loop

  while (!a) {
    // go to auton position
    autonslctr();
    if(gamers.ButtonB.pressing()) {
      a = 1;
      wait(200,msec);
    }

    if(gamers.ButtonA.pressing()) {
      if(auton == 1) {
        go1();
      }
      else if(auton == 2) {
        go2();
      }
      else if(auton == 3) {
        go3();
      }
      wait(200,msec);
    }

  }

  while (a) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    dtcode(1,1);
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}