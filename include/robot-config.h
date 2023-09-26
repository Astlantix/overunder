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
extern controller gamers;
extern motor intake;
extern motor pull;
extern digital_out flex;
extern digital_out muscle;
extern rotation lef;
extern rotation rig;
extern rotation side;
extern digital_out wings;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
