#include "vex.h"
#include "odom.hpp"



bool c = 0;

//intake stuff
void take(int joe) {
    if(joe==0) {
        intake.stop(coast);
    }
    else if(joe==1) {
        intake.spin(fwd,100,pct);
    }
    else if(joe==2) {
        intake.spin(reverse,100,pct);
    }
}

//flywheel stuff
void fly() {
    if(c==0) {
        cata.spin(fwd,3600,rpm);
    }
    else if(c==1) {
        cata.stop(coast);
    }
}

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
    Right(49);
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
    For(51);
    wait(200,msec);
    Right(90);
    take(2);
    For(12);
    wait(200,msec);
    wings.open();
    wait(200,msec);
    Rev(24);
    intake.stop(coast);
    wait(200,msec);
    Right(195);
    wait(200,msec);
    take(1);
    wait(200,msec);
    For(18);
    wait(200,msec);
    Rev(22);
    take(0);
    wait(200,msec);
    Right(180);
    wait(200,msec);
    For(18);
    take(2);
    wait(200,msec);
    Rev(24);
    take(0);
    Right(120);
    take(1);
    For(23);
    wait(200,msec);
    take(0);
    Left(165+90);
    take(2);
    For(5);
    Rev(10);
    take(0);
    For(24);
    setcoast();
    c = 1;
} 


//skills
void auton3() {
    ml.spin(fwd,100,pct);
    wait(1,sec);
    ml.stop(coast);
    wait(1,sec);
    mr.spin(fwd,100,pct);
    wait(1,sec);
    mr.stop(coast);
    wait(1,sec);
    fr.spin(fwd,100,pct);
    wait(1,sec);
    fr.stop(coast);
    wait(1,sec);
    fl.spin(fwd,100,pct);
    wait(1,sec);
    fl.stop(coast);
    wait(1,sec);
    bl.spin(fwd,100,pct);
    wait(1,sec);
    bl.stop(coast);
    wait(1,sec);
    br.spin(fwd,100,pct);
    wait(1,sec);
    br.stop(coast);
    wait(1,sec);

}