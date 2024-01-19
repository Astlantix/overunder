#include "vex.h"
#include "functions.hpp"
#include <string>

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

int b = 0; // intaking thingy
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
using namespace chrono;

bool flapping = 0; // wings open or close
steady_clock::time_point lastFlap; // time last flap

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
// toggle wings
void wingaction() {
  if (flapping) {
    wingactionb();
    cout << "close" << endl;
  } else {
    wingactiona();
    cout << "open" << endl;
  }
}

// change flapping value
void flap() {
  auto now = steady_clock::now(); // current
  auto durLastFlap = duration_cast<milliseconds>(now-lastFlap).count(); // duration

  // Only allow flap function to be called at least 200 ms have passed since the last call
  if (durLastFlap > 200) {
    flapping = !flapping;
    lastFlap = now;
  }
}
// .......................................................................


// ........................................................................
// climbing stuff
// ........................................................................

// lifting stays down or very strong pullup
void down() {climb.close();}

// im tall
void up() {climb.open();}

// ........................................................................


// intake
// ........................................................................

steady_clock::time_point printake; // time last intake pressing

// intake thing
void intaking() {
  auto now = steady_clock::now(); // current time
  auto durLastTake = duration_cast<milliseconds>(now-printake).count();
  if(durLastTake > 150) {
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
    printake = now;
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
  L.spinFor(fwd,dist*18,deg,0);
  R.spinFor(fwd,dist*18,deg);
}

// Backward function
void Rev(double dist, double adjust) {
  L.spinFor(rev,dist*18,deg,0);
  R.spinFor(rev,dist*18,deg);
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
void printing(string text) {
  gamers.Screen.clearScreen();
  gamers.Screen.setCursor(1,1);
  gamers.Screen.print("------------------------------");
  gamers.Screen.setCursor(4,1);
  gamers.Screen.print("------------------------------");
  gamers.Screen.setCursor(2,1);
  gamers.Screen.print(text.c_str());
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

// drivetrain code tank drive
void dtcode(double x) {
  if(gamers.ButtonL1.pressing() && gamers.ButtonL2.pressing()) {
    L.spin(fwd,100,pct);
    R.spin(fwd,100,pct);
  }
  else if(gamers.ButtonL1.pressing()) {
    L.spin(fwd,100,pct);
    R.spin(fwd,0,pct);
  } else if (gamers.ButtonL2.pressing()) {
    L.spin(fwd,0,pct);
    R.spin(fwd,100,pct);
  }
  else {
   double leftspeed = gamers.Axis3.position(); // speed of left side controlled by left joystick
    double rightspeed = gamers.Axis2.position(); // speed of right side controlled by right joystick
    L.spin(fwd,leftspeed*x,pct);
    R.spin(fwd,rightspeed*x,pct);
  }
}

// drivetrain code arcade drive
void dcode(double x, double y) {
  if(gamers.ButtonL1.pressing() && gamers.ButtonL2.pressing()) {
    L.spin(fwd,100,pct);
    R.spin(fwd,100,pct);
  }
  else if(gamers.ButtonL1.pressing()) {
    L.spin(fwd,100,pct);
    R.spin(fwd,0,pct);
  } else if (gamers.ButtonL2.pressing()) {
    L.spin(fwd,0,pct);
    R.spin(fwd,100,pct);
  }  
  else {
    double leftspeed = (gamers.Axis3.value()*y) + (gamers.Axis4.value()*x);
    double rightspeed = (gamers.Axis3.value()*y) - (gamers.Axis4.value()*x);
    L.spin(fwd,leftspeed,pct);
    R.spin(fwd,rightspeed,pct);
  }
}

// aaron goofy drive
void batmobile() {
  double vel = 0;
  bool keep = 0;
  if (gamers.ButtonL2.pressing()) {
    keep = 1;
  } else {
    keep = 0;
  }
  if (gamers.ButtonL1.pressing()) {
    vel = 50;
    if (!keep) {
      if (vel < 1) {
        vel += 0.5;
      } else {
        vel *= 1.25;
      }
    }
  } else if (gamers.ButtonB.pressing()) {
    vel = -50;
      if (!keep) {
        if (vel > -1) {
         vel -= 0.5;
        } else {
         vel *= 1.25;
        }
      }
    } else {
      vel = 0;
    }
  if (vel > 100) {
    vel = 100;
  } else if (vel < -100) {
    vel = -100;
  }

  if (vel == 0) {
    L.spin(fwd,gamers.Axis4.position()/4,pct);
    R.spin(rev,gamers.Axis4.position()/4,pct);
  } else {
    L.spin(fwd,vel + gamers.Axis4.position()/4,pct);
    R.spin(rev,vel - gamers.Axis4.position()/4,pct);
  }

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
    printing("L Sabotage");
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

// changing brake modes
void modechange() {
  if (gamers.ButtonA.pressing()) {
    sethold();
  } else {
    setcoast();
  }
}

// printing intake and drivetrain temperature
void tempcheck() {
  gamers.Screen.clearScreen();
  gamers.Screen.setCursor(1,1);
  gamers.Screen.print(modes);
  gamers.Screen.setCursor(2,1);
  gamers.Screen.print((fl.temperature(celsius) + fr.temperature(celsius) + ml.temperature(celsius) + mr.temperature(celsius) + br.temperature(celsius) + bl.temperature(celsius))/6);
  gamers.Screen.setCursor(3,1);
  gamers.Screen.print((fl.temperature(celsius) + fr.temperature(celsius))/2);
  gamers.Screen.setCursor(3,6);
  gamers.Screen.print((ml.temperature(celsius) + mr.temperature(celsius) + br.temperature(celsius) + bl.temperature(celsius))/4);
  
  if (ml.temperature(celsius) > 55 || mr.temperature(celsius) > 55 || fl.temperature(celsius) > 55 || fr.temperature(celsius) > 55 || bl.temperature(celsius) > 55 || br.temperature(celsius) > 55 || cata.temperature(celsius) > 55 || flywheel.temperature(celsius) > 55) {
    gamers.rumble("...");
    wait(5, sec);
  }
  else if (ml.temperature(celsius) > 50 || mr.temperature(celsius) > 50 || fl.temperature(celsius) > 50 || fr.temperature(celsius) > 50 || bl.temperature(celsius) > 50 || br.temperature(celsius) > 50 || cata.temperature(celsius) > 50 || flywheel.temperature(celsius) > 50) {
    gamers.rumble("---");
    wait(5, sec);
  }
}
// ........................................................................

steady_clock::time_point fist;
bool flying = 1; // flywheel on or off
// puncher and flywheel
void punching() {
  if (flying) {
    msp(cata);
    msp(flywheel);
  } else {
    msc(cata);
    msc(flywheel);
  }
}

void notpunching() {
  auto now = steady_clock::now();
  auto durLastHit = duration_cast<milliseconds>(now-fist).count();
  if (durLastHit > 200){
    flying = !flying;
    fist = now;
  }
}
// ........................................................................