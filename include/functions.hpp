#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

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
void Left(double angle, double adjust = 1.5);
void Right(double angle, double adjust = 1.5);
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

#endif //FUNCTIONS_HPP