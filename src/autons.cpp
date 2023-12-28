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
  timer t;
  setv(50);
  t.clear();
  For(29.5);
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
  Left(165);
  msp(intake);
  For(17);
  wait(500,msec);
  msc(intake);
  Rev(5);
  Right(180);
  msp(intake,1,90);
  wait(200,msec);
  For(16);
  wait(500,msec);
  Rev(5);
  Right(125);
  msp(intake);
  For(23);
  wait(500,msec);
  msc(intake);
  Rev(5);
  Right(160);
  msp(intake,1,90);
  For(16);
  wait(500,msec);
  cout << t.time(sec) << endl;
  Rev(5);
  msc(intake);
  Right(180);
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
  wait(30,msec);
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
  Rev(8);
  Right(120);
  setv(40);
  setcoast();
  For(7.5);
  Left(25);
  For(20.2);
  wait(200,msec);
  msc(intake);
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

// Right Side AWP 2 triball
void auton4 () {
  /**/
  setv(20);
  For(28);
  wings.open();
  Right(80);
  msp(intake,1,90);
  setv(20);
  wait(200,msec);
  For(5);
  wait(700,msec);
  setv(40);
  msc(intake);
  wait(20,msec);
  Rev(5);
  wings.close();
  Right(135);
  msp(intake,0,90);
  For(13.5);
  wait(500,msec);
  msc(intake);
  wait(20,msec);
  Rev(5);
  Left(175);
  msp(intake,1,90);
  For(22);
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

// skills
void auton5() {
  /*flies();
  wait(30,sec);
  flies(1);*/
  //
  msp(cata,1);
  wait(35,sec);
  Rev(30);
  msc(cata);
  Left(45);
  wingactiona();
  Rev(70); 
  /*For(100);
  wingactiona();
  For(100);
  wait(200,msec);
  Rev(50);
  Right(90);*/
  /*travel(36,-90);
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
  travel(36,0);*/
}

// drivetrain test
void auton6 () {
  Right(90);
}





