#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor fl = motor(PORT1, ratio18_1, false);
motor fr = motor(PORT2, ratio18_1, false);
motor bl = motor(PORT3, ratio18_1, false);
motor br = motor(PORT4, ratio18_1, false);
motor ml = motor(PORT7, ratio18_1, false);
motor mr = motor(PORT8, ratio18_1, false);
controller gamers = controller(primary);
motor intakeMotorA = motor(PORT6, ratio18_1, false);
motor intakeMotorB = motor(PORT5, ratio18_1, false);
motor_group intake = motor_group(intakeMotorA, intakeMotorB);
digital_out flex = digital_out(Brain.ThreeWirePort.E);
encoder xpos = encoder(Brain.ThreeWirePort.A);
encoder ypos = encoder(Brain.ThreeWirePort.C);
inertial inert = inertial(PORT10);

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