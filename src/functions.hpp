#include "vex.h"

int b = 0;
bool catamode = 0; //catapult spin or coast
bool modes = 1; //reverse or forward

//general stuff
// ........................................................................


//spin motor (motor, dir, speed)
void msp(motor m, bool x = 0, double speed = 100) {
    if (x) {
        m.spin(fwd,speed,pct);
    } else {
        m.spin(rev,speed,pct);
    }
}
//coast motor
void msc(motor m) {m.stop(coast);}
// ........................................................................

//wings stuff
// ........................................................................

//open wings
void wingactiona() {
    wings.open();
    fly.open();
}
//close wings
void wingactionb() {
    wings.close();
    fly.close();
}
// ........................................................................

//intake stuff
// ........................................................................

//toggle intake
void intakecontrol() {
    if (b==0) {
      if (gamers.ButtonR1.pressing()) {
       intake.spin(fwd,100,pct);
       wait(2,msec);
       b = 1;
      } else if (gamers.ButtonR2.pressing()) {
        intake.spin(rev,100,pct);
        wait(2,msec);
        b = 2;
      }
    } else if (b==1) {
      if(gamers.ButtonR1.pressing()) {
        intake.stop(coast);
        wait(2,msec);
        b = 0;
      } else if (gamers.ButtonR2.pressing()) {
        intake.spin(rev,100,pct);
        wait(2,msec);
        b = 2;
      }
    } else if (b==2) {
      if (gamers.ButtonR2.pressing()) {
        intake.stop(coast);
        wait(2,msec);
        b = 0;
      } else if (gamers.ButtonR1.pressing()) {
        intake.spin(fwd,100,pct);
        wait(2,msec);
        b = 1;
      }
    }
}
// ........................................................................

//flywheel stuff
// ........................................................................

bool airborne = 1; //toggle flywheel
//flying
void flies(bool c = 0) {
    if (c==0) {
        flywheel.spin(fwd,100,pct);
    } else if (c==1) {
        flywheel.stop(coast);
    }
}
//toggle flywheel
void liftoff() {
  flies(airborne);
}

// ........................................................................

//drivetrain stuff
// ........................................................................

//stop is  coast
void setcoast() {
  ml.setStopping(coast);
  mr.setStopping(coast);
  bl.setStopping(coast);
  br.setStopping(coast);
  fl.setStopping(coast);
  fr.setStopping(coast);
}

//stop is hold
void sethold() {
  ml.setStopping(hold);
  mr.setStopping(hold);
  bl.setStopping(hold);
  br.setStopping(hold);
  fl.setStopping(hold);
  fr.setStopping(hold);
}
// ........................................................................

//printing function
void printing(std::string string) {
  gamers.Screen.clearScreen();
  gamers.Screen.setCursor(1,1);
  gamers.Screen.print(string.c_str());
}

//drivecode
double currentlspeed = 0;
double currentrspeed = 0;
void dtcode(double x, double y) {
  double rightspeed, leftspeed;

  if (fabs(gamers.Axis3.position()) < 10 && fabs(gamers.Axis4.position()) > 10) {
    // If Axis3 is 0 and Axis4 is non-zero, make the robot turn in place
    leftspeed = gamers.Axis4.position() * x;
    rightspeed = gamers.Axis4.position() * -x;
  }
  else {
    double avgSpeed = ((fabs(gamers.Axis3.position()) > 10 ? gamers.Axis3.position() * y : 0) + (fabs(gamers.Axis4.position()) > 10 ? gamers.Axis4.position() * x : 0)) / 2;
    leftspeed = avgSpeed + (fabs(gamers.Axis4.position()) > 10 ? gamers.Axis4.position() * x : 0);
    rightspeed = avgSpeed - (fabs(gamers.Axis4.position()) > 10 ? gamers.Axis4.position() * x : 0);
  }
// Ramp up or down to the target speeds
  while (currentlspeed != leftspeed || currentrspeed != rightspeed) {
    if (currentlspeed < leftspeed) currentlspeed++;
    else if (currentlspeed > leftspeed) currentlspeed--;

    if (currentrspeed < rightspeed) currentrspeed++;
    else if (currentrspeed > rightspeed) currentrspeed--;

    L.spin(fwd, currentlspeed, pct);
    R.spin(fwd, currentrspeed, pct);

    // Delay to allow the motors to catch up
    wait(20,msec);
  }
}

//auton stuff
// ........................................................................
int auton = 1;
int numofautons = 3;
void autonslctr() {
  if (auton < 1) {
    auton = numofautons;
  } else if (auton > numofautons) {
    auton = 1;
  }
  if (auton == 1) {
    printing("LAWP");
  } else if (auton == 2) {
    printing("RAWP");
  } else if (auton == 3) {
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
// ........................................................................

//changind modes
void modechange() {
  if (gamers.ButtonB.pressing()) {
    sethold();
  } else {
    setcoast();
  }
}

//catapult movement
void catamoving() {
  if (gamers.Axis2.position() < -10) {
    catamode = 1;
  } else if( gamers.Axis2.position() > 10) {
    catamode = 0;
  }

  if (catamode) {
    cata.spin(fwd,100,pct);
  } else {
    cata.stop(coast);
  }    
}

//printing intake and drivetrain temperature
void tempcheck() {
    gamers.Screen.clearScreen();
    gamers.Screen.setCursor(1,1);
    gamers.Screen.print(intake.temperature(celsius));
    gamers.Screen.setCursor(2,1);
    gamers.Screen.print((fr.temperature(celsius) + fl.temperature(celsius) + mr.temperature(celsius) + ml.temperature(celsius) + br.temperature(celsius) + bl.temperature(celsius))/6);
    gamers.Screen.setCursor(3,1);
    gamers.Screen.print(cata.temperature(celsius));
    gamers.Screen.setCursor(3,6);
}