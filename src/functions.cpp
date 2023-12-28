#include "vex.h"
#include "functions.hpp"

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

int b = 0;
bool catamode = 0; // catapult spin or coast
bool modes = 1; // reverse or forward

// general stuff
// ........................................................................


// spin motor (motor, dir, speed)
void msp(motor m, bool x, double speed) {
  if (x) {
      m.spin(fwd,speed,pct);
  } else {
      m.spin(rev,speed,pct);
  }
}
// coast motor
void msc(motor m) {m.stop(coast);}
// ........................................................................

// wings stuff
// ........................................................................

// open wings
void wingactiona() {
  wings.open();
  fly.open();
}
// close wings
void wingactionb() {
  wings.close();
  fly.close();
}
// .......................................................................


// ........................................................................

// flywheel stuff
// ........................................................................

bool airborne = 1; // toggle flywheel
// flying
void flies(bool c) {
  if (c==0) {
      flywheel.spin(fwd,100,pct);
  } else if (c==1) {
      flywheel.stop(coast);
  }
}
// toggle flywheel
void liftoff() {
  flies(airborne);
}

// ........................................................................

// climbing stuff
// ........................................................................

// lifting stays down or very strong pullup
void down() {climb.open();}

// im tall
void up() {climb.open();}

// ........................................................................


// intake
// ........................................................................

// intake thing
void intaking() {
  if (b==0) {
    if (gamers.ButtonR1.pressing()) {
      intake.spin(rev,100,pct);
      b = 1;
      wait(200,msec);
    } else if (gamers.ButtonR2.pressing()) {
      intake.spin(fwd,100,pct);
      b = 2;
      wait(200,msec);
    }
  } else if (b==1) {
    if(gamers.ButtonR1.pressing()) {
      intake.stop(coast);
      b = 0;
      wait(200,msec);
    } else if (gamers.ButtonR2.pressing()) {
      intake.spin(fwd,100,pct);
      b = 2;
      wait(200,msec);
    }
  } else if (b==2) {
    if (gamers.ButtonR2.pressing()) {
      intake.stop(coast);
      b = 0;
      wait(200,msec);
    } else if (gamers.ButtonR1.pressing()) {
      intake.spin(rev,100,pct);
      b = 1;
      wait(200,msec);
    }
  }
}

// ........................................................................

// drivetrain stuff
// ........................................................................
// stop is brake
void setbrake() {
  R.setStopping(brake);
  L.setStopping(brake);
}

// stop
void stoop() {
  R.stop(coast);
  L.stop(coast);
}

// Forward function
void For(double dist, double adjust) {
  L.spinFor(fwd,dist*adjust,degrees,false);
  R.spinFor(fwd,dist*adjust,degrees);
}

// Backward function
void Rev(double dist, double adjust) {
  L.spinFor(rev,dist*adjust,degrees,false);
  R.spinFor(rev,dist*adjust,degrees);
}

// Left function
void Left(double angle, double adjust) {
  inert.setRotation(0,deg);
  while (fabs(inert.rotation(degrees)) < angle) {
    double error = angle - fabs(inert.rotation(degrees));
    L.spin(rev,5 + adjust*error,pct);
    R.spin(fwd,5 + adjust*error,pct);
    wait(20,msec);
  }
  L.stop(brake);
  R.stop(brake);
}

// Right function
void Right(double angle, double adjust) {
  inert.setRotation(0,deg);
  while (fabs(inert.rotation(degrees)) < angle) {
    double error = angle - fabs(inert.rotation(degrees));
    L.spin(fwd,5 + adjust*error,pct);
    R.spin(rev,5 + adjust*error,pct);
    wait(20,msec);
  }
  L.stop(brake);
  R.stop(brake);
}

// set velocity
void setv(double vel) {
  L.setVelocity(vel,pct);
  R.setVelocity(vel,pct);
}
// stop is  coast
void setcoast() {
  ml.setStopping(coast);
  mr.setStopping(coast);
  bl.setStopping(coast);
  br.setStopping(coast);
  fl.setStopping(coast);
  fr.setStopping(coast);
}

// stop is hold
void sethold() {
  ml.setStopping(hold);
  mr.setStopping(hold);
  bl.setStopping(hold);
  br.setStopping(hold);
  fl.setStopping(hold);
  fr.setStopping(hold);
}
// ........................................................................

// printing function
void printing(std::string string) {
  gamers.Screen.clearScreen();
  gamers.Screen.setCursor(1,1);
  gamers.Screen.print("------------------------------");
  gamers.Screen.setCursor(4,1);
  gamers.Screen.print("------------------------------");
  gamers.Screen.setCursor(2,1);
  gamers.Screen.print(string.c_str());
}

// another printing function
void printer(double x) {
  gamers.Screen.clearScreen();
  gamers.Screen.setCursor(1,1);
  gamers.Screen.print("------------------------------");
  gamers.Screen.setCursor(4,1);
  gamers.Screen.print("------------------------------");
  gamers.Screen.setCursor(2,1);
  gamers.Screen.print(x);
}

// drivecode
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
  if (leftspeed > 85) leftspeed = 85;
  if (rightspeed > 85) rightspeed = 85;
  L.spin(fwd, leftspeed, pct);
  R.spin(fwd, rightspeed, pct);
}

// auton stuff
// ........................................................................

int auton = 1; // selected auton
int numofautons = 6; // number of autons
// auton selector
void autonslctr() {
  if (auton < 1) {
    auton = numofautons;
  } else if (auton > numofautons) {
    auton = 1;
  }
  if (auton == 1) {
    printing("RAWP");
  } else if (auton == 2) {
    printing("L(AWP)");
  } else if (auton == 3) {
    printing("eLim");
  } else if (auton == 4) {
    printing("RAWP2");
  } else if (auton == 5) {
    printing("Skills");
  } else if (auton == 6) {
    printing("Test");
  }
  if (gamers.ButtonRight.pressing()) {
    auton++;
    wait(200,msec);
  } else if (gamers.ButtonLeft.pressing()) {
    auton--;                        
    wait(200,msec);
  }
  if(gamers.ButtonUp.pressing()) {
    cin >> auton;
  }
}
// ........................................................................

// changind modes
void modechange() {
  if (gamers.ButtonA.pressing()) {
    sethold();
  } else {
    setcoast();
  }
}

// catapult movement
void catamoving() {
  if (gamers.Axis2.position() < -10) {
    catamode = 1;
  } else if( gamers.Axis2.position() > 10) {
    catamode = 0;
  }
  // one red one orange
  if (catamode) {
    msp(cata,1);
  } else {
      if(gamers.ButtonLeft.pressing() || gamers.ButtonRight.pressing()) {
        msp(cata,1,40);
      } else {
        msc(cata);
    }
  }
}

// printing intake and drivetrain temperature
void tempcheck() {
  gamers.Screen.clearScreen();
  gamers.Screen.setCursor(1,1);
  gamers.Screen.print(modes);
  gamers.Screen.setCursor(2,1);
  gamers.Screen.print((fr.temperature(celsius) + fl.temperature(celsius) + mr.temperature(celsius) + ml.temperature(celsius) + br.temperature(celsius) + bl.temperature(celsius))/6);
  gamers.Screen.setCursor(3,1);
  gamers.Screen.print(cata.temperature(celsius));
}
