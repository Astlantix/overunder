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


//drivetrain test
void auton1 () {

    fl.spin(fwd);
    wait(2,sec);
    fl.stop(coast);
    br.spin(fwd);
    wait(2,sec);
    br.stop(coast);
    mr.spin(fwd);
    wait(2,sec);
    mr.stop(coast);
    fr.spin(fwd);
    wait(2,sec);
    fr.stop(coast);
    ml.spin(fwd);
    wait(2,sec);
    ml.stop(coast);
    bl.spin(fwd);
    wait(2,sec);
    bl.stop(coast);
    


}

//Right Side AWP
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

//Left Side AWP
void auton4() {
    
}

//Right Side No AWP
void auton5() {
    
}

//Left Side No AWP 
void auton6() {

}