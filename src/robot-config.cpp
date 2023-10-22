#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor fl = motor(PORT17, ratio18_1, false);
motor fr = motor(PORT12, ratio18_1, true);
motor bl = motor(PORT4, ratio18_1, false);
motor br = motor(PORT1, ratio18_1, true);
motor ml = motor(PORT10, ratio18_1, false);
motor mr = motor(PORT7, ratio18_1, true);
controller gamers = controller(primary);
motor intake = motor(PORT16, ratio18_1, false);
motor pull = motor(PORT11, ratio36_1, false);
digital_out muscle = digital_out(Brain.ThreeWirePort.G);
rotation lef = rotation(PORT18, true);
rotation rig = rotation(PORT2, false);
rotation side = rotation(PORT3, false);
pneumatics wings = pneumatics(Brain.ThreeWirePort.A);
pneumatics fly = pneumatics(Brain.ThreeWirePort.C);
motor cata = motor(PORT5, ratio36_1, false);
limit ballin = limit(Brain.ThreeWirePort.E);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}