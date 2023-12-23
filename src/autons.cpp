#include "vex.h"
#include "autons.hpp"
#include "functions.hpp"
#include "pid.hpp"
//using namespace vex;
/*   __   ______     __    ________    __   ____      
 /'_ `\/\  ___\  /'__`\ /\_____  \ /'__`\/\  _`\    
/\ \L\ \ \ \__/ /\ \/\ \\/___//'/'/\ \/\ \ \ \L\ \  
\ \___, \ \___``\ \ \ \ \   /' /' \ \ \ \ \ \  _ <' 
 \/__,/\ \/\ \L\ \ \ \_\ \/' /'    \ \ \_\ \ \ \L\ \
      \ \_\ \____/\ \____/\_/       \ \____/\ \____/
       \/_/\/___/  \/___/\//         \/___/  \/___/ 
                                                    
*/


//drivetrain test
void auton1 () {
    Right(90);
}

//Right Side AWP safe
void auton2 () {
    /**/
    setv(40);
    For(24);
    wings.open();
    Right(90);
    msp(intake,1,90);
    setv(20);
    For(5);
    wait(700,msec);
    setv(40);
    msc(intake);
    wait(20,msec);
    Rev(5);
    wings.close();
    Right(190);
    msp(intake,0,90);
    For(13.5);
    wait(20,msec);
    msc(intake);
    wait(20,msec);
    Left(190);
    For(22);
    msp(intake,1,90);
    setv(20);
    For(5);
    setv(40);
    wait(700,msec);
    msc(intake); 
    wait(20,msec);
    Rev(5);
    msp(intake,1,90);
    wait(500,msec);
    For(5);
    /*Right(135);
    msp(intake,0,90);
    For(12);
    wait(33,msec);
    msc(intake);
    wait(20,msec);
    Left(180);
    For(33);
    wait(20,msec);
    Right(45);
    msp(intake,1,90);
    For(5);
    wait(200,msec);
    msc(intake);
    wait(20,msec);
    Rev(10);
    Right(180);
    For(24);
    Left(90);
    Rev(30);*/
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