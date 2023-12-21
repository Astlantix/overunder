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

//climbing stuff
// ........................................................................

//lifting stays down or very strong pullup
void down() {climb.open();}

//im tall
void up() {climb.open();}

// ........................................................................


//intake
// ........................................................................

//intake thing
void intaking() {
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
void dtcode(double x, double y) {
  double rightspeed, leftspeed;

  if (fabs(gamers.Axis3.position()) < 10 && fabs(gamers.Axis4.position()) > 10) {
    // If Axis3 is 0 and Axis4 is non-zero, make the robot turn in place
    leftspeed = gamers.Axis4.position() * x;
    rightspeed = gamers.Axis4.position() * -x;
  } else {
    double avgSpeed = ((fabs(gamers.Axis3.position()) > 10 ? gamers.Axis3.position() * y : 0) + (fabs(gamers.Axis4.position()) > 10 ? gamers.Axis4.position() * x : 0)) / 2;
    leftspeed = avgSpeed + (fabs(gamers.Axis4.position()) > 10 ? gamers.Axis4.position() * x : 0);
    rightspeed = avgSpeed - (fabs(gamers.Axis4.position()) > 10 ? gamers.Axis4.position() * x : 0);
  }

  L.spin(fwd, leftspeed, pct);
  R.spin(fwd, rightspeed, pct);
  
}

//auton stuff
// ........................................................................

int auton = 1; //selected auton
int numofautons = 6; //number of autons
//auton selector
void autonslctr() {
  if (auton < 1) {
    auton = numofautons;
  } else if (auton > numofautons) {
    auton = 1;
  }
  if (auton == 1) {
    printing("drivetrain test");
  } else if (auton == 2) {
    printing("RAWP");
  } else if (auton == 3) {
    printing("skills");
  } else if (auton == 4) {
    printing("LAWP");
  } else if (auton == 5) {
    printing("RNAWP");
  } else if (auton == 6) {
    printing("LNAWP");
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
    gamers.Screen.print(modes);
    gamers.Screen.setCursor(2,1);
    gamers.Screen.print((fr.temperature(celsius) + fl.temperature(celsius) + mr.temperature(celsius) + ml.temperature(celsius) + br.temperature(celsius) + bl.temperature(celsius))/6);
    gamers.Screen.setCursor(3,1);
    gamers.Screen.print(cata.temperature(celsius));
}