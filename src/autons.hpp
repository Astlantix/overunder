#include "vex.h"
#include "functions.hpp"
#include "pid.hpp"

/*   __   ______     __    ________    __   ____      
 /'_ `\/\  ___\  /'__`\ /\_____  \ /'__`\/\  _`\    
/\ \L\ \ \ \__/ /\ \/\ \\/___//'/'/\ \/\ \ \ \L\ \  
\ \___, \ \___``\ \ \ \ \   /' /' \ \ \ \ \ \  _ <' 
 \/__,/\ \/\ \L\ \ \ \_\ \/' /'    \ \ \_\ \ \ \L\ \
      \ \_\ \____/\ \____/\_/       \ \____/\ \____/
       \/_/\/___/  \/___/\//         \/___/  \/___/ 
                                                    
*/

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
void For(double joe, double adjust = 24) {
    L.spinFor(fwd,joe*adjust,degrees,false);
    R.spinFor(fwd,joe*adjust,degrees);
}

//Backward function
void Rev(double joe, double adjust = 24) {
    L.spinFor(rev,joe*adjust,degrees,false);
    R.spinFor(rev,joe*adjust,degrees);
}

//Left function
void Left(double joe, double adjust = 2) {
    L.spinFor(rev,joe*adjust,degrees,false);
    R.spinFor(fwd,joe*adjust,degrees);
}

//Right function
void Right(double joe, double adjust = 2) {
    L.spinFor(fwd,joe*adjust,degrees,false);
    R.spinFor(rev,joe*adjust,degrees);
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
    /*
    
    */
    For(100);
    wings.open();
    Right(90);
    msp(intake,1);
    For(10);
    wait(200,msec);
    msc(intake);
    wait(20,msec);
    Rev(10);
    wings.close();
    Right(180);
    msp(intake);
    For(25);
    wait(20,msec);
    msc(intake);
    wait(20,msec);
    Rev(10);
    Right(180);
    msp(intake,1);
    For(25);
    wait(200,msec);
    msc(intake);
    wait(20,msec);
    Rev(10);
    Right(135);
    msp(intake);
    For(12);
    wait(20,msec);
    msc(intake);
    wait(20,msec);
    Left(180);
    For(12);
    wait(20,msec);
    Right(45);
    msp(intake,1);
    For(10);
    wait(200,msec);
    msc(intake);
    wait(20,msec);
    Rev(10);
    Right(180);
    For(100);
    Left(90);
    Rev(50);

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