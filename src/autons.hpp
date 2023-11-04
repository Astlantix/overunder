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
    wait(200,msec);
    Rev(15);
    wait(20,msec);
    Right(75);
    wait(200,msec);
    wait(200,msec);
    setv(100);
    Rev(22);
    setcoast();
    c = 1;
}

//right Side AWP
void auton2 () {

    setbrake();
    setv(75);
    wings.close();
    For(48);
    wait(200,msec);
    Right(90);
    intake.spin(reverse,100,pct);
    For(10);
    wait(200,msec);
    wings.open();
    intake.stop(coast);
    wait(200,msec);
    Rev(24);
    wait(200,msec);
    Right(195);
    wait(200,msec);
    intake.spin(fwd,100,pct);
    wait(200,msec);
    For(18);
    wait(200,msec);
    intake.stop(coast);
    Rev(22);
    wait(200,msec);
    Right(180);
    wait(200,msec);
    For(20);
    intake.spin(reverse,100,pct);
    wait(200,msec);
    intake.stop(coast);
    Rev(24);
    Right(150);
    intake.spin(fwd,100,pct);
    For(23);
    wait(200,msec);
    intake.stop(coast);
    Rev(25);
    Left(165);
    intake.spin(reverse,100,pct);
    For(24);
    Rev(24);
    intake.stop(coast);
    setcoast();
    c = 1;
} 


//skills
void auton3() {
    Right(90);

}