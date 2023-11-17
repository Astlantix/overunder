using namespace vex;

extern brain Brain;


// define your global instances of motors and other devices here
// VEXcode devices
extern motor fl;
extern motor fr;
extern motor bl;
extern motor br;
extern motor ml;
extern motor mr;
extern motor_group L;
extern motor_group R;
extern controller gamers;
extern motor intake;
extern motor pull;
extern digital_out muscle;
extern encoder D;
extern inertial inert;
extern pneumatics wings;
extern pneumatics fly;
extern motor cata;
extern limit ballin;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
