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
    fl.spinFor(fwd,joe,degrees,false);
    fr.spinFor(fwd,joe,degrees,false);
    bl.spinFor(fwd,joe,degrees,false);
    br.spinFor(fwd,joe,degrees);
}

//Backward function
void Rev(double joe) {
    fl.spinFor(reverse,joe,degrees,false);
    fr.spinFor(reverse,joe,degrees,false);
    bl.spinFor(reverse,joe,degrees,false);
    br.spinFor(reverse,joe,degrees);
}

//Left function
void Left(double joe) {
    fl.spinFor(reverse,joe,degrees,false);
    fr.spinFor(fwd,joe,degrees,false);
    bl.spinFor(fwd,joe,degrees,false);
    br.spinFor(reverse,joe,degrees);
}

//Right function
void Right(double joe) {
    fl.spinFor(fwd,joe,degrees,false);
    fr.spinFor(reverse,joe,degrees,false);
    bl.spinFor(reverse,joe,degrees,false);
    br.spinFor(fwd,joe,degrees);
}

void go1 () {
    
}

void go2 () {
    
}

void go3 () {
    
}

void auton1 () {

    setbrake();

    For(6);
    intake.spin(reverse,100,pct);
    wait(500,msec);
    intake.stop();
    Left(90);
    For(36);
    Right(90);
    intake.spin(forward,100,pct);
    flex.set(1);
    wait(500,msec);
    flex.set(0);

    setcoast();
    c = 1;
}

void auton2 () {

    setbrake();

    For(6);
    intake.spin(reverse,100,pct);
    wait(500,msec);
    intake.stop();
    Right(90);
    For(36);
    Left(90);
    intake.spin(forward,100,pct);
    flex.set(1);
    wait(500,msec);
    flex.set(0);    

    setcoast();
    c = 1;
}

void auton3 () {
    
    setbrake();

    setcoast();
    c = 1;
}