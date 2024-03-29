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
extern int auton;
extern int numofautons;
extern bool flying;
extern bool flapping;

// Declare your functions

void msp(motor m, bool x = 0, double speed = 100);
void msc(motor m);
void wingactiona();
void wingactionb();
void wingaction();
void flap();
void down();
void up();
void intaking();
void setbrake();
void stoop();
void For(double distance, double adjust = 18);
void Rev(double distance, double adjust = 18);
void Left(double angle, double adjust = 0.1);
void Right(double angle, double adjust = 0.1);
void setv(double vel);
void setcoast();
void sethold();
void printing(std::string text);
void printer(double x);
int dtcode();
int dcode();
void batmobile();
void autonslctr();
void punching();
void notpunching();

#endif // FUNCTIONS_HPP