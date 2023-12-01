#include "vex.h"
#include "functions.hpp"
#include "pid.hpp"


bool a = 0;



//haha i dont need these bc pid and inertial oh god scary
/*
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
*/

//left side AWP
void auton1 () {

    travel(72,90);
    

    a = 1;
}

//right Side AWP
void auton2 () {


    a = 1;
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
