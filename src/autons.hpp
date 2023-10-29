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
    fl.spinFor(fwd,joe*24,degrees,false);
    fr.spinFor(fwd,joe*24,degrees,false);
    ml.spinFor(fwd,joe*24,degrees,false);
    mr.spinFor(fwd,joe*24,degrees,false);
    bl.spinFor(fwd,joe*24,degrees,false);
    br.spinFor(fwd,joe*24,degrees);
}

//Backward function
void Rev(double joe) {
    fl.spinFor(reverse,joe*24,degrees,false);
    fr.spinFor(reverse,joe*24,degrees,false);
    ml.spinFor(reverse,joe*24,degrees,false);
    mr.spinFor(reverse,joe*24,degrees,false);
    bl.spinFor(reverse,joe*24,degrees,false);
    br.spinFor(reverse,joe*24,degrees);
}

//Left function
void Left(double joe) {
    fl.spinFor(reverse,joe*2,degrees,false);
    fr.spinFor(fwd,joe*2,degrees,false);
    ml.spinFor(reverse,joe*2,degrees,false);
    mr.spinFor(fwd,joe*2,degrees,false);
    bl.spinFor(reverse,joe*2,degrees,false);
    br.spinFor(reverse,joe*2,degrees);
}

//Right function
void Right(double joe) {
    fl.spinFor(fwd,joe*2,degrees,false);
    fr.spinFor(reverse,joe*2,degrees,false);
    ml.spinFor(fwd,joe*2,degrees,false);
    mr.spinFor(reverse,joe*2,degrees,false);
    bl.spinFor(fwd,joe*2,degrees,false);
    br.spinFor(reverse,joe*2,degrees);
}

void setv(double joe) {
    fl.setVelocity(joe,pct);
    fr.setVelocity(joe,pct);
    ml.setVelocity(joe,pct);
    mr.setVelocity(joe,pct);
    bl.setVelocity(joe,pct);
    br.setVelocity(joe,pct);
}


//left side AWP
void auton1 () {

    setbrake();
    setv(50);
    fly.close();
    wait(20,msec);
    Rev(15);
    wait(20,msec);
    Right(60);
    wait(20,msec);
    fly.open();
    wait(20,msec);
    Rev(22);
    setcoast();
    c = 1;
}

//right Side AWP
void auton2 () {

    setbrake();
    setv(80);
    For(44);
    Right(90);
    intake.spin(reverse,100,pct);
    For(20);
    wait(200,msec);
    intake.stop(coast);
    Rev(24);
    Right(120);
    intake.spin(fwd,100,pct);
    For(22);
    wait(200,msec);
    intake.stop(coast);
    Rev(22);
    Right(230);
    For(24);
    Right(20);
    For(22);
    intake.spin(reverse,100,pct);
    wait(200,msec);
    intake.stop(coast);
    Rev(22);
    Left(90);
    intake.spin(fwd,100,pct);
    For(7.5);
    wait(200,msec);
    Rev(7.5);
    Right(90);
    For(22);
    intake.spin(reverse,100,pct);
    wait(200,msec);
    intake.stop(coast);
    Rev(44);
    Left(90);
    intake.spin(fwd,100,pct);
    For(7.5);
    wait(200,msec);
    Rev(7.5);
    intake.stop(coast);
    Right(90);
    For(22);
    intake.spin(reverse,100,pct);
    wait(200,msec);
    intake.stop(coast);
    Rev(10);

    setcoast();
    c = 1;
}


//right Side Getting as many tri-balls as possible
void auton3 () {
    
    setbrake();

    Right(90);
    wait(200,msec);
    Rev(24);

    setcoast();
    c = 1;
}