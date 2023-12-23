#ifndef PID_HPP
#define PID_HPP
/*   __   ______     __    ________    __   ____      
 /'_ `\/\  ___\  /'__`\ /\_____  \ /'__`\/\  _`\    
/\ \L\ \ \ \__/ /\ \/\ \\/___//'/'/\ \/\ \ \ \L\ \  
\ \___, \ \___``\ \ \ \ \   /' /' \ \ \ \ \ \  _ <' 
 \/__,/\ \/\ \L\ \ \ \_\ \/' /'    \ \ \_\ \ \ \L\ \
      \ \_\ \____/\ \____/\_/       \ \____/\ \____/
       \/_/\/___/  \/___/\//         \/___/  \/___/ 
                                                    
*/
//Declare your variables
extern double integral_orient;
extern double lastError;
extern double lastError_orient;
extern double kP;
extern double kI;
extern double kD;
extern double kP_orient;
extern double kI_orient;
extern double kD_orient;

//Declare your functions
void drivetrainPID(double error, double error_orient);

void travel(double distance, double angle);

#endif //PID_HPP