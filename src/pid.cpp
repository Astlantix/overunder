#include "vex.h"
#include "pid.hpp"
/*   __   ______     __    ________    __   ____      
 /'_ `\/\  ___\  /'__`\ /\_____  \ /'__`\/\  _`\    
/\ \L\ \ \ \__/ /\ \/\ \\/___//'/'/\ \/\ \ \ \L\ \  
\ \___, \ \___``\ \ \ \ \   /' /' \ \ \ \ \ \  _ <' 
 \/__,/\ \/\ \L\ \ \ \_\ \/' /'    \ \ \_\ \ \ \L\ \
      \ \_\ \____/\ \____/\_/       \ \____/\ \____/
       \/_/\/___/  \/___/\//         \/___/  \/___/ 
*/
using namespace vex;

double π = atan(1) * 4; // defining pi using the symbol because im cool
double ws = 4; // wheel diameter in inches

/*
Set all gains to zero.

Increase kP until the response to a step input (like a sudden change in target distance) is steady oscillation. Steady oscillation means the robot moves back and forth around the target distance without settling down.

Set kP to about half of the value causing steady oscillation.

Increase kD until any overshoot is acceptable. Overshoot is when the robot moves past the target distance before coming back. Increasing kD will reduce the overshoot, but making kD too large can lead to a sluggish response.

Increase kI until the robot reaches the target distance in a reasonable time during steady state. Steady state is when the robot is not being subjected to any disturbances or changes in the target distance. Be careful with increasing kI, as too large a value can cause instability.

*/
// PID constants
double kP = 0.1; // kP is the constant for proportional control
double kI = 0.0; // kI is the constant for integral control
double kD = 0.0; // kD is the constant for derivative control



// PID variables
double integral = 0; // integral is the sum of all errors 
double derivative = 0; // derivative is the difference between the current error and the last error
double error = 0; // error is the difference between the target distance and the current distance
double lastError = 0; // lastError is the error from the last time the function was called
double integralLimit = 20; // integralLimit is the maximum value of the integral

// Orientation PID constants
double kP_orient = 0.0; // kP is the constant for proportional control
double kI_orient = 0.0; // kI is the constant for integral control
double kD_orient = 0.0; // kD is the constant for derivative control

// Orientation PID variables
double integral_orient = 0; // integral is the sum of all errors
double derivative_orient = 0; // derivative is the difference between the current error and the last error
double error_orient = 0; // error is the difference between the target orientation and the current orientation
double lastError_orient = 0; // lastError is the error from the last time the function was called

// drivetrain pid with odometry
void drivetrainPID(double targetDistance, double targetOrientation, double distanceSensorValue, double orientationSensorValue) {
    // Calculate distance error
    error = targetDistance - distanceSensorValue;

    // Calculate orientation error
    error_orient = targetOrientation - orientationSensorValue;

    // Calculate distance integral with windup prevention
    if (fabs(error) < integralLimit) {
        integral += error;
    } else {
        integral = 0;
    }

    // Calculate orientation integral with windup prevention
    if (fabs(error_orient) < integralLimit) {
        integral_orient += error_orient;
    } else {
        integral_orient = 0;
    }

    // Calculate distance derivative
    derivative = error - lastError; // change in distance
    lastError = error; // update previous value

    // Calculate orientation derivative
    derivative_orient = error_orient - lastError_orient; // change in orient
    lastError_orient = error_orient; // update previous value

    // Calculate distance PID output
    double output = kP*error + kI*integral + kD*derivative;

    // Calculate orientation PID output
    double output_orient = kP_orient*error_orient + kI_orient*integral_orient + kD_orient*derivative_orient;

    // Control motors
    double leftMotorSpeed = output + output_orient; // Calculate left speed
    double rightMotorSpeed = output - output_orient; // Calculate right speed

    // Set motor speeds...
    L.spin(fwd,leftMotorSpeed,pct);
    R.spin(fwd,rightMotorSpeed,pct);
}

// odometry using pid
void travel(double distance, double angle) {
    // Get current distance sensor value
    // double currentDistance = (D.position(turns) + E.position(turns) / 2) * π * ws;
    double currentDistance = (E.position(turns) + D.position(turns))/2*π*ws;
    // Get current orientation sensor value
    double currentOrientation = inert.yaw();

    // Move forward
    while (fabs(distance - currentDistance) > 0.1) {
        drivetrainPID(distance, currentOrientation, currentDistance, currentOrientation);
        // currentDistance = (D.position(turns) + E.position(turns) / 2) * π * ws;
        currentDistance = (D.position(turns) + E.position(turns))/2*π*ws;
    }

    // Turn
    while (fabs(angle - currentOrientation) > 0.1) {
        drivetrainPID(0, angle, currentDistance, currentOrientation);
        currentOrientation = inert.yaw();
    }
}