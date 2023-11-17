#include "vex.h"

using namespace vex;

/*
Set all gains to zero.

Increase kP until the response to a step input (like a sudden change in target distance) is steady oscillation. Steady oscillation means the robot moves back and forth around the target distance without settling down.

Set kP to about half of the value causing steady oscillation.

Increase kD until any overshoot is acceptable. Overshoot is when the robot moves past the target distance before coming back. Increasing kD will reduce the overshoot, but making kD too large can lead to a sluggish response.

Increase kI until the robot reaches the target distance in a reasonable time during steady state. Steady state is when the robot is not being subjected to any disturbances or changes in the target distance. Be careful with increasing kI, as too large a value can cause instability.

*/
// PID constants
double kP = 0.0;
double kI = 0.0;
double kD = 0.0;



// PID variables
double integral = 0;
double derivative = 0;
double error = 0;
double lastError = 0;
double integralLimit = 20;

// Orientation PID constants
double kP_orient = 0.0;
double kI_orient = 0.0;
double kD_orient = 0.0;

// Orientation PID variables
double integral_orient = 0;
double derivative_orient = 0;
double error_orient = 0;
double lastError_orient = 0;

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
    derivative = error - lastError;
    lastError = error;

    // Calculate orientation derivative
    derivative_orient = error_orient - lastError_orient;
    lastError_orient = error_orient;

    // Calculate distance PID output
    double output = kP * error + kI * integral + kD * derivative;

    // Calculate orientation PID output
    double output_orient = kP_orient * error_orient + kI_orient * integral_orient + kD_orient * derivative_orient;

    // Control motors
    double leftMotorSpeed = output - output_orient;
    double rightMotorSpeed = output + output_orient;

    // Set motor speeds...
    L.spin(fwd, leftMotorSpeed, pct);
    R.spin(fwd, rightMotorSpeed, pct);
}

void travel(double distance, double angle) {
    // Get current distance sensor value
    double currentDistance = D.position(turns) * 4;

    // Get current orientation sensor value
    double currentOrientation = inert.yaw();

    // Move forward
    while (fabs(distance - currentDistance) > 0.1) {
        drivetrainPID(distance, currentOrientation, currentDistance, currentOrientation);
        currentDistance = D.position(turns) *4;
    }

    // Turn
    while (fabs(angle - currentOrientation) > 0.1) {
        drivetrainPID(0, angle, currentDistance, currentOrientation);
        currentOrientation = inert.yaw();
    }

    // Move forward again
    while (fabs(distance - currentDistance) > 0.1) {
        drivetrainPID(distance, currentOrientation, currentDistance, currentOrientation);
        currentDistance = D.position(turns) *4;
    }
}