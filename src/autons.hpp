#include "vex.h"
#include "functions.hpp"
#include "pid.hpp"



//stop is brake
void setbrake() {
    R.setStopping(brake);
    L.setStopping(brake);
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
    L.spinFor(rev,joe*24,degrees,false);
    R.spinFor(rev,joe*24,degrees);
}

//Left function
void Left(double joe) {
    L.spinFor(rev,joe*2,degrees,false);
    R.spinFor(fwd,joe*2,degrees);
}

//Right function
void Right(double joe) {
    L.spinFor(fwd,joe*2,degrees,false);
    R.spinFor(rev,joe*2,degrees);
}

void setv(double joe) {
    L.setVelocity(joe,pct);
    R.setVelocity(joe,pct);
}


//left side AWP
void auton1 () {

    travel(72,90);
    


}

//right Side AWP
void auton2 () {


    
} 


//skills
void auton3() {
    flies();
    wait(30,sec);
    flies(1);
    //
    For(100);
    wingactiona();
    For(100);
    wait(200,msec);
    Rev(50);
    travel(0,90);
    travel(36,-90);
    travel(12,-90);
    For(10);
    wait(200,msec);
    Rev(10);
    wait(200,msec);
    travel(0,-90);
    travel(12,90);
    travel(60,90);
    travel(12,90);
    For(10);
    wait(200,msec);
    Rev(10);
    wait(200,msec);
    travel(0,90);
    travel(36,0);
    
}
