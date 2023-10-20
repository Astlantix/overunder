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
void For(double joe) {
    fl.spinFor(fwd,joe*36,degrees,false);
    fr.spinFor(fwd,joe*36,degrees,false);
    ml.spinFor(fwd,joe*36,degrees,false);
    mr.spinFor(fwd,joe*36,degrees,false);
    bl.spinFor(fwd,joe*36,degrees,false);
    br.spinFor(fwd,joe*36,degrees);
}

//Backward function
void Rev(double joe) {
    fl.spinFor(reverse,joe*36,degrees,false);
    fr.spinFor(reverse,joe*36,degrees,false);
    ml.spinFor(reverse,joe*36,degrees,false);
    mr.spinFor(reverse,joe*36,degrees,false);
    bl.spinFor(reverse,joe*36,degrees,false);
    br.spinFor(reverse,joe*36,degrees);
}

//Left function
void Left(double joe) {
    fl.spinFor(reverse,joe*3.3515,degrees,false);
    fr.spinFor(fwd,joe*3.3515,degrees,false);
    ml.spinFor(reverse,joe*3.3515,degrees,false);
    mr.spinFor(fwd,joe*3.3515,degrees,false);
    bl.spinFor(reverse,joe*3.3515,degrees,false);
    br.spinFor(reverse,joe*3.3515,degrees);
}

//Right function
void Right(double joe) {
    fl.spinFor(fwd,joe*3.3515,degrees,false);
    fr.spinFor(reverse,joe*3.3515,degrees,false);
    ml.spinFor(fwd,joe*3.3515,degrees,false);
    mr.spinFor(reverse,joe*3.3515,degrees,false);
    bl.spinFor(fwd,joe*3.3515,degrees,false);
    br.spinFor(reverse,joe*3.3515,degrees);
}

void setv(double joe) {
    fl.setVelocity(joe,pct);
    fr.setVelocity(joe,pct);
    ml.setVelocity(joe,pct);
    mr.setVelocity(joe,pct);
    bl.setVelocity(joe,pct);
    br.setVelocity(joe,pct);
}


//Right side AWP
void auton1 () {

    setbrake();
    setv(70);
    fly.close();
    Rev(15);
    Right(60);
    fly.open();
    Rev(22);
    For(15);
    Left(55);

    setcoast();
    c = 1;
}

//Left Side AWP
void auton2 () {

    setbrake();
    setv(100);
    For(42);
    wings.close();
    Right(90);
    intake.spin(reverse,100,pct);
    For(24);
    intake.stop(coast);

    setcoast();
    c = 1;
}


//Left Side Getting as many tri-ball  s as possible
void auton3 () {
    
    setbrake();

    cata.spin(fwd,75,pct);

    setcoast();
    c = 1;
}