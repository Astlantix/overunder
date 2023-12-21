using namespace vex;

extern brain Brain;
/*   __   ______     __    ________    __   ____      
 /'_ `\/\  ___\  /'__`\ /\_____  \ /'__`\/\  _`\    
/\ \L\ \ \ \__/ /\ \/\ \\/___//'/'/\ \/\ \ \ \L\ \  
\ \___, \ \___``\ \ \ \ \   /' /' \ \ \ \ \ \  _ <' 
 \/__,/\ \/\ \L\ \ \ \_\ \/' /'    \ \ \_\ \ \ \L\ \
      \ \_\ \____/\ \____/\_/       \ \____/\ \____/
       \/_/\/___/  \/___/\//         \/___/  \/___/ 
                                                    
*/

// define your global instances of motors and other devices here
// VEXcode devices
extern controller gamers;
extern motor fl;
extern motor fr;
extern motor bl;
extern motor br;
extern motor ml;
extern motor mr;
extern motor_group L;
extern motor_group R;
extern pneumatics climb;
extern rotation D;
extern inertial inert;
extern pneumatics wings;
extern pneumatics fly;
extern motor cata;
extern motor intake;
extern motor flywheel;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
