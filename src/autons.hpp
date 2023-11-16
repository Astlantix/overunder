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
void flies() {
    if(c==0) {
        cata.spin(fwd,3600,rpm);
    }
    else if(c==1) {
        cata.stop(coast);
    }
}

//stop is hold
void sethold() {
    R.setStopping(hold);
    L.setStopping(hold);
}

//stop is coast
void setcoast() {
    R.setStopping(coast);
    L.setStopping(coast);
}

//stop is brake
void setbrake() {
    R.setStopping(brake);
    L.setStopping(coast);
}

//stop
void stoop() {
    R.stop(coast);
    L.stop(coast);
}

//Forward function
void For(double joe) {
    L.spinFor(fwd,joe*24,degrees,false);
    R.spinFor(fwd,joe*24,degrees);
}

//Backward function
void Rev(double joe) {
    L.spinFor(reverse,joe*24,degrees,false);
    R.spinFor(reverse,joe*24,degrees);
}

//Left function
void Left(double joe) {
    L.spinFor(reverse,joe*2,degrees,false);
    R.spinFor(fwd,joe*2,degrees);
}

//Right function
void Right(double joe) {
    L.spinFor(fwd,joe*2,degrees,false);
    R.spinFor(reverse,joe*2,degrees);
}

void setv(double joe) {
    L.setVelocity(joe,pct);
    R.setVelocity(joe,pct);
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