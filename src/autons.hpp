#include "vex.h"
#include "odom.hpp"



bool c = 0;

//stop is hold
void sethold() {
  ml.setStopping(hold);
  mr.setStopping(hold);
  fr.setStopping(hold);
  fl.setStopping(hold);
  bl.setStopping(hold);
  br.setStopping(hold);
}

//stop is coast
void setcoast() {
  ml.setStopping(coast);
  mr.setStopping(coast);
  fr.setStopping(coast);
  fl.setStopping(coast);
  bl.setStopping(coast);
  br.setStopping(coast);
}

//stop is brake
void setbrake() {
  ml.setStopping(brake);
  mr.setStopping(brake);
  fr.setStopping(brake);
  fl.setStopping(brake);
  bl.setStopping(brake);
  br.setStopping(brake);
}

//stop
void stoop() {
  ml.stop();
  mr.stop();
  fr.stop();
  fl.stop();
  bl.stop();
  br.stop();
}

//Forward function
void For(double joe, double joey) {
    fl.spin(fwd,joe,pct);

}

//Backward function
void Rev(double joe, double joey) {
    fl.spin(reverse,joe,pct);
    fr.spin(reverse,joe,pct);
    ml.spin(reverse,joe,pct);
    mr.spin(reverse,joe,pct);
    bl.spin(reverse,joe,pct);
    br.spin(reverse,joe,pct);
    wait(joey,msec);
}

//Left function
void Left(double joe) {
    fl.spinFor(reverse,joe,degrees,false);
    fr.spinFor(fwd,joe,degrees,false);
    ml.spinFor(reverse,joe,degrees,false);
    mr.spinFor(fwd,joe,degrees,false);
    bl.spinFor(fwd,joe,degrees,false);
    br.spinFor(reverse,joe,degrees);
}

//Right function
void Right(double joe) {
    fl.spinFor(fwd,joe,degrees,false);
    fr.spinFor(reverse,joe,degrees,false);
    ml.spinFor(reverse,joe,degrees,false);
    mr.spinFor(fwd,joe,degrees,false);
    bl.spinFor(reverse,joe,degrees,false);
    br.spinFor(fwd,joe,degrees);
}


//going to starting position from an easily accessible position
void go1 () {
    
}

void go2 () {
    
}

void go3 () {
    
}


void shoot() {
  intake.spin(fwd,100,pct);
  wait(100,msec);
  flex.set(1);
  wait(500,msec);
  flex.set(0);
  intake.stop();
}


//Right side AWP
void auton1 () {

    setbrake();

    setcoast();
    c = 1;
}

//Left Side AWP
void auton2 () {
    setcoast();

    fl.spin(fwd,100,pct);

    setcoast();
    c = 1;
}


//Left Side Getting as many tri-balls as possible
void auton3 () {
    
    setbrake();
    cata.spin(fwd,25,pct);

    setcoast();
    c = 1;
}