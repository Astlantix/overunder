#include "vex.h"
#include "autons.hpp"
#include "functions.hpp"
#include "pid.hpp"
using namespace vex;
using namespace std;

/*   __   ______     __    ________    __   ____      
 /'_ `\/\  ___\  /'__`\ /\_____  \ /'__`\/\  _`\    
/\ \L\ \ \ \__/ /\ \/\ \\/___//'/'/\ \/\ \ \ \L\ \  
\ \___, \ \___``\ \ \ \ \   /' /' \ \ \ \ \ \  _ <' 
 \/__,/\ \/\ \L\ \ \ \_\ \/' /'    \ \ \_\ \ \ \L\ \
      \ \_\ \____/\ \____/\_/       \ \____/\ \____/
       \/_/\/___/  \/___/\//         \/___/  \/___/ 
*/

// Right Side AWP 4 triballs
void auton1() {
  /*setv(50);
  For(29);
  fly.open();
  wait(10,msec);
  Right(90);
  msp(intake,1,90);
  wait(500,msec);
  msc(intake);
  For(5.5);
  wait(500,msec);
  Rev(5.5);
  setv(45);
  fly.close();
  Right(135);
  msp(intake);
  For(12.75);
  wait(750,msec);
  msc(intake);
  Rev(5);
  Right(180);
  msp(intake,1,90);
  wait(200,msec);
  For(16);
  wait(500,msec);
  Rev(5);
  Left(155);
  msp(intake);
  For(14);
  wait(500,msec);
  msc(intake);
  Rev(5);
  Right(180);
  msp(intake,1,90);
  For(16);
  wait(500,msec);
  Rev(5);
  msc(intake);*/
  setv(40);
  For(27);
  Right(90);
  msp(intake,1,90);
  wait(100,msec);
  For(5);
  wait(250,msec);
  Rev(5);
  Right(145);
  msp(intake);
  For(11.25);
  wait(200,msec);
  Right(165);
  msp(intake,1);
  wait(600,msec);
  Left(30);
  msp(intake);
  For(2.75);
  setv(25);
  R.spinFor(fwd,360,deg);
  wingactiona();
  wait(250,msec);
  setv(100);
  msc(intake);
  Rev(17);
  For(5);
  wingactionb();
  Right(180);
  msp(intake,1,90);
  For(5);
  wait(100,msec);
  Rev(5);
  wait(100,msec);
  For(5);
}

// Left Side AWP
void auton2() {
  /*Right(37);
  wait(10,msec);
  Rev(13.5);
  wait(10,msec);
  setv(40);
  For(15.625);
  wait(10,msec);
  Left(40); 
  wings.open();
  Left(45);
  wings.close();
  msp(intake,1);
  For(20);
  msc(intake);*/
  fly.open();
  wait(300,msec);
  Left(45);
  wait(40,msec);
  fly.close();
  Right(20); 
  msp(intake,1,90);
  setv(100);
  For(12);
  wait(750,msec);
  Rev(0.45);
  Left(90);
  msc(intake);
  setv(40);
  Rev(35);
  fly.open();
  Left(25);
}

// Left Side Elims
void auton3() {
  Rev(7.5);
  wait(10,msec);
  For(7.5);
  wait(10,msec);
  Left(30);
  msp(intake,1);
  For(20);
  wait(20,msec);
  Rev(17);
}

// Left Side Sabotage
void auton4 () {
  For(20);
  Left(90);
  msp(intake,1);
  wait(500,msec);
  For(5);
  fly.open();
  msc(intake);
  Rev(35);
  Right(90);
  fly.close();
}

// skills
void auton5() {
  punching();
  //Right(25);
  //For(20);
}

// drivetrain test
void auton6 () {
  msp(fr);
  wait(1,sec);
  msc(fr);
  msp(bl);
  wait(1,sec);
  msc(bl);
  msp(ml);
  wait(1,sec);
  msc(ml);
  msp(fl);
  wait(1,sec);
  msc(fl);
  msp(mr);
  wait(1,sec);
  msc(mr);
  msp(br);
  wait(1,sec);
  msc(br);
}