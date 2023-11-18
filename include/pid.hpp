#ifndef PID_HPP
#define PID_HPP

// Declare your variables
extern double integral_orient;
extern double lastError;
extern double lastError_orient;
extern double kP;
extern double kI;
extern double kD;
extern double kP_orient;
extern double kI_orient;
extern double kD_orient;

// Declare your functions
double calculate_pid(double error, double error_orient);

#endif // PID_HPP