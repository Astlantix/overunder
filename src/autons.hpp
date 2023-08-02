#include "vex.h"
#include "odom.hpp"



bool a = 0;

//stop is hold
void sethold() {
  ml.stop(hold);
  mr.stop(hold);
  fr.stop(hold);
  fl.stop(hold);
  bl.stop(hold);
  br.stop(hold);
}

//stop is coast
void setcoast() {
  ml.stop(coast);
  mr.stop(coast);
  fr.stop(coast);
  fl.stop(coast);
  bl.stop(coast);
  br.stop(coast);
}

//stop is brake
void setbrake() {
  ml.stop(brake);
  mr.stop(brake);
  fr.stop(brake);
  fl.stop(brake);
  bl.stop(brake);
  br.stop(brake);
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

    setcoast();
    a = 1;
}

void auton2 () {

    setbrake();

    setcoast();
    a = 1;
}

void auton3 () {
    
    setbrake();

    setcoast();
    a = 1;
}