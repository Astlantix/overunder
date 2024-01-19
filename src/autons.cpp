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
  setv(50);
  For(30);
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
  For(17);
  wait(500,msec);
  msc(intake);
  Rev(5);
  Left(180);
  msp(intake,1,90);
  wait(200,msec);
  For(16);
  wait(500,msec);
  Rev(5);
  Left(160);
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
  msc(intake);
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
  Rev(2.75);
  Left(82.5);
  msc(intake);
  setv(40);
  setcoast();
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
  Right(25);
  For(20);
  up();
}

// drivetrain test
void auton6 () {
  msp(fl);
  wait(500,msec);
  msc(fl);
  msp(fr);
  wait(500,msec);
  msc(fr);
  msp(ml);
  wait(500,msec);
  msc(ml);
  msp(mr);
  wait(500,msec);
  msc(mr);
  msp(bl);
  wait(500,msec);
  msc(bl);
  msp(br);
  wait(500,msec);
  msc(br);
}