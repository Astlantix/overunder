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
// ml                   motor         9
// mr                   motor         10        
// bl                   motor         3               
// br                   motor         4               
// gamers               controller                    
// intake               motor         6         
// flex                 digital_out   A    
// muscle               digital_out   B
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


/*



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
  wings.open();
  fly.open();
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




int numofautons = 3;

void printing(std::string strin) {
  gamers.Screen.clearScreen();
  gamers.Screen.setCursor(1,1);
  gamers.Screen.print(strin.c_str());
}

int auton = 1;
void autonslctr() {
  if (auton < 1) {
    auton = numofautons;
  }
  if (auton > numofautons) {
    auton = 1;
  }
  if (auton == 1) {
    printing("LAWP");
  }
  if (auton == 2) {
    printing("RAWP");
  }
  if (auton == 3) {
    gamers.Screen.clearScreen();
    gamers.Screen.setCursor(1,1);
    gamers.Screen.print("  O  ");
    gamers.Screen.setCursor(2,1);
    gamers.Screen.print(" /|\\ ");
    gamers.Screen.setCursor(3,1);
    gamers.Screen.print(" / \\ ");
  }
  if (gamers.ButtonRight.pressing()) {
    auton++;
    wait(200,msec);
  } else if (gamers.ButtonLeft.pressing()) {
    auton--;                        
    wait(200,msec);
  }
}

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

// Adjust this value to control the smoothness

void dtcode(double x, double y) {

  double rightspeed, leftspeed;

  if (abs(gamers.Axis3.position()) < 10 && abs(gamers.Axis4.position()) > 10) {
    // If Axis3 is 0 and Axis4 is non-zero, make the robot turn in place
    leftspeed = gamers.Axis4.position() * x;
    rightspeed = gamers.Axis4.position() * -x;
  } else {
    double avgSpeed = ((abs(gamers.Axis3.position()) > 10 ? gamers.Axis3.position() * y : 0) + (abs(gamers.Axis4.position()) > 10 ? gamers.Axis4.position() * x : 0)) / 2;
    leftspeed = avgSpeed + (abs(gamers.Axis4.position()) > 10 ? gamers.Axis4.position() * x : 0);
    rightspeed = avgSpeed - (abs(gamers.Axis4.position()) > 10 ? gamers.Axis4.position() * x : 0);
  }
  L.spin(fwd,leftspeed,pct);
  R.spin(fwd,rightspeed,pct);
}


int b = 0;
bool stupid = 0;
bool modes = 1;
bool dumb = 0;
std::string mode = "coast";
void usercontrol(void) {
   //User control code here, inside the loop

  while (!a) {
    // select auton
    autonslctr();
    if (gamers.ButtonB.pressing()) {
      a = 1;
      wait(200,msec);
    }
  }
   while (a) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    //(turn,fwdrev)
    if (modes) {
      dtcode(0.27,2);
    } else if (!modes) {
      dtcode(0.27,-2);
    }
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    


    //toggle intake
    if (b==0) {
      if (gamers.ButtonR1.pressing()) {
       intake.spin(fwd,100,pct);
       wait(2,msec);
       b = 1;
      } else if (gamers.ButtonR2.pressing()) {
        intake.spin(reverse,100,pct);
        wait(2,msec);
        b = 2;
      }
    } else if (b==1) {
      if(gamers.ButtonR1.pressing()) {
        intake.stop(coast);
        wait(2,msec);
        b = 0;
      } else if (gamers.ButtonR2.pressing()) {
        intake.spin(reverse,100,pct);
        wait(2,msec);
        b = 2;
      }
    }
    else if (b==2) {
      if (gamers.ButtonR2.pressing()) {
        intake.stop(coast);
        wait(2,msec);
        b = 0;
      }
      else if (gamers.ButtonR1.pressing()) {
        intake.spin(fwd,100,pct);
        wait(2,msec);
        b = 1;
      }
    }


    //clamp and pulling
 

    if (gamers.ButtonL1.pressing()) {
      wings.open();
      fly.open();
    }

    if (gamers.ButtonL2.pressing()) {
      wings.close();
      fly.close();
    }

    if (gamers.ButtonB.pressing()) {
      modes = !modes;
    }

    if (gamers.Axis2.position() < -10) {
      stupid = 1;
    } else if( gamers.Axis2.position() > 10) {
      stupid = 0;
    }

    if (stupid) {
      cata.spin(fwd,3600,rpm);
    } else {
      cata.stop(coast);
    }

    if (gamers.ButtonA.pressing()) {
      if (!dumb) {
        sethold();
        wait(200,msec);
        gamers.rumble(rumbleLong);
        mode = "hold";
        dumb = 1;
      } else {
        setcoast();
        wait(200,msec);
        gamers.rumble(rumblePulse);
        mode = "coast";
        dumb = 0;
      }
    }

    //printing intake and drivetrain temperature
    gamers.Screen.clearScreen();
    gamers.Screen.setCursor(1,1);
    gamers.Screen.print(intake.temperature(celsius));
    gamers.Screen.setCursor(2,1);
    gamers.Screen.print((fr.temperature(celsius) + fl.temperature(celsius) + mr.temperature(celsius) + ml.temperature(celsius) + br.temperature(celsius) + bl.temperature(celsius))/6);
    gamers.Screen.setCursor(3,1);
    gamers.Screen.print(cata.temperature(celsius));
    gamers.Screen.setCursor(3,6);
    gamers.Screen.print(mode.c_str());

    

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
  while (1) {
    wait(100,msec);
  }
}
