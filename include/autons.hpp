#ifndef AUTONS_HPP

#define AUTONS_HPP

/*   __   ______     __    ________    __   ____      
 /'_ `\/\  ___\  /'__`\ /\_____  \ /'__`\/\  _`\    
/\ \L\ \ \ \__/ /\ \/\ \\/___//'/'/\ \/\ \ \ \L\ \  
\ \___, \ \___``\ \ \ \ \   /' /' \ \ \ \ \ \  _ <' 
 \/__,/\ \/\ \L\ \ \ \_\ \/' /'    \ \ \_\ \ \ \L\ \
      \ \_\ \____/\ \____/\_/       \ \____/\ \____/
       \/_/\/___/  \/___/\//         \/___/  \/___/ 
*/



//declare your functions

extern int b;
extern bool catamode;
extern bool modes;
void msp(motor m, bool x = 0, double speed = 100);
void msc(motor m);
void wingactiona();
void wingactionb();
extern bool airborne;
void flies(bool c = 0);
void liftoff();
void down();
void up();
void intaking();
void setbrake();
void stoop();
void For(double distance, double adjust = 20);
void Rev(double distance, double adjust = 20);
void Left(double angle, double adjust = 0.25);
void Right(double angle, double adjust = 0.25);
void setv(double vel);
void setcoast();
void sethold();
void printing(std::string string);
void dtcode(double x, double y);
extern int auton;
extern int numofautons;
void autonslctr();
void modechange();
void catamoving();
void tempcheck();

void auton1();

void auton2();

void auton3();

void auton4();

void auton5();

void auton6();



#endif // AUTONS_HPP