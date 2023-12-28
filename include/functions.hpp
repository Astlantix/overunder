#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

/*   __   ______     __    ________    __   ____      
 /'_ `\/\  ___\  /'__`\ /\_____  \ /'__`\/\  _`\    
/\ \L\ \ \ \__/ /\ \/\ \\/___//'/'/\ \/\ \ \ \L\ \  
\ \___, \ \___``\ \ \ \ \   /' /' \ \ \ \ \ \  _ <' 
 \/__,/\ \/\ \L\ \ \ \_\ \/' /'    \ \ \_\ \ \ \L\ \
      \ \_\ \____/\ \____/\_/       \ \____/\ \____/
       \/_/\/___/  \/___/\//         \/___/  \/___/ 
*/

// Declare your variables

extern int b;
extern bool catamode;
extern bool modes;
extern bool airborne;
extern int auton;
extern int numofautons;

// Declare your functions

void msp(motor m, bool x = 0, double speed = 100);
void msc(motor m);
void wingactiona();
void wingactionb();

void flies(bool c = 0);
void liftoff();
void down();
void up();
void intaking();
void setbrake();
void stoop();
void For(double distance, double adjust = 20);
void Rev(double distance, double adjust = 20);
void Left(double angle, double adjust = 0.1);
void Right(double angle, double adjust = 0.1);
void setv(double vel);
void setcoast();
void sethold();
void printing(std::string string);
void printer(double x);
void dtcode(double x, double y);
void autonslctr();
void modechange();
void catamoving();
void tempcheck();


#endif // FUNCTIONS_HPP