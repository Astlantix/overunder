#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor fl = motor(PORT7, ratio18_1, true);
motor fr = motor(PORT4, ratio18_1, false);
motor bl = motor(PORT10, ratio18_1, true);
motor br = motor(PORT2, ratio18_1, false);
motor ml = motor(PORT9, ratio18_1, true);
motor mr = motor(PORT5, ratio18_1, false);
controller gamers = controller(primary);
motor intake = motor(PORT1, ratio18_1, false);
digital_out flex = digital_out(Brain.ThreeWirePort.A);
digital_out muscle = digital_out(Brain.ThreeWirePort.B);
rotation lef = rotation(PORT13, false);
rotation rig = rotation(PORT12, false);
inertial inert = inertial(PORT14);
rotation side = rotation(PORT11, false);

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