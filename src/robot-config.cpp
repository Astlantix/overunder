#include "vex.h"
/*   __   ______     __    ________    __   ____      
 /'_ `\/\  ___\  /'__`\ /\_____  \ /'__`\/\  _`\    
/\ \L\ \ \ \__/ /\ \/\ \\/___//'/'/\ \/\ \ \ \L\ \  
\ \___, \ \___``\ \ \ \ \   /' /' \ \ \ \ \ \  _ <' 
 \/__,/\ \/\ \L\ \ \ \_\ \/' /'    \ \ \_\ \ \ \L\ \
      \ \_\ \____/\ \____/\_/       \ \____/\ \____/
       \/_/\/___/  \/___/\//         \/___/  \/___/ 
                                                    
*/
using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;
//custom gear ratio hehehe
const gearSetting vex::ratio1_1 = gearSetting::ratio1_1;
// VEXcode device constructors
controller gamers = controller(primary); //amzing controller
motor fl = motor(PORT15, ratio18_1, 1); //front left
motor fr = motor(PORT17, ratio18_1, 0); //front right
motor bl = motor(PORT5, ratio18_1, 1); //back left
motor br = motor(PORT10, ratio18_1, 0); //back right
motor ml = motor(PORT7, ratio18_1, 0); //middle left
motor mr = motor(PORT4, ratio18_1, 1); //middle right
motor_group L = motor_group(ml, bl, fl); //left motors
motor_group R = motor_group(mr, br, fr); //right motors
pneumatics climb = pneumatics(Brain.ThreeWirePort.C); //very cool lifting mechanism
rotation D = rotation(PORT6, 0); //very cool rotation sensor
rotation E = rotation(PORT8,0); //very cool rotation sensor
inertial inert = inertial(PORT3); //disgusting
pneumatics wings = pneumatics(Brain.ThreeWirePort.A); //left wing
pneumatics fly = pneumatics(Brain.ThreeWirePort.H); //right wing
motor cata = motor(PORT2, ratio36_1, 0); //catapult
motor intake = motor(PORT12, ratio18_1, 1); //very cool intake
motor flywheel = motor(PORT13, ratio1_1, 1); //VERY COOL FLYWHEEL ON A STICK I MADE MY IDEA MY WORK I BUILT IT ALL ME 3600 RPM DIRECT CUSTOM CARTRIDGE


// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = 1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
    gamers.rumble(rumblePulse);
};