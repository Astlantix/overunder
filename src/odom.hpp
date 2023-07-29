#include "vex.h"

const double circ = (3.25 * atan(1) * 4)/36000; // circumference of the wheel

double xPosition = 0;
double yPosition = 0;

void odometry() {

    double leftPrevious = lef.position(degrees);
    double rightPrevious = rig.position(degrees);
    double sidePrevious = side.position(degrees);
    double anglePrevious = 0;
    //double inertialPrevious = inertial.rotation(degrees);

    double leftDistance = 1.75;
    double rightDistance = 1.75;
    double sideDistance = 1.75;

    while (1) {
        
        double deltaLeft = lef.position(degrees) - leftPrevious;
        double deltaRight = rig.position(degrees) - rightPrevious;
        double deltaSide = side.position(degrees) - sidePrevious;
        //double deltaInertial = inertial.rotation(degrees) - inertialPrevious;

        deltaLeft *= circ;
        deltaRight *= circ;
        deltaSide *= circ;
        //deltaInertial *= atan(1) * 4 / 18000;

        double angleChange = (deltaLeft - deltaRight) / (deltaLeft + deltaRight);
        //double angleChange = deltaInertial;

        double localDeltaX;
        double localDeltaY;
        
        if(angleChange==0) {
            localDeltaX = deltaSide;
            localDeltaY = deltaRight;
        }

        else {
            double radiusFront = deltaLeft / angleChange - leftDistance;
            double radiusSide = deltaRight / angleChange - sideDistance;

            localDeltaX = 2 * radiusSide * sin(angleChange / 2);
            localDeltaY = 2 * radiusFront * sin(angleChange / 2);
        }

        //#1
        double distance = sqrt(localDeltaX * localDeltaX + localDeltaY * localDeltaY);
        xPosition += distance * cos(atan(localDeltaY / localDeltaX) - anglePrevious - angleChange / 2);
        yPosition += distance * sin(atan(localDeltaY / localDeltaX) - anglePrevious - angleChange / 2);

        //#2
        /*
        xPosition += localDeltaX * sin(anglePrevious + angleChange / 2) + localDeltaY * cose(anglePrevious + angleChange / 2);
        yPosition += localDeltaX * cos(anglePrevious + angleChange / 2) - localDeltaY * sin(anglePrevious + angleChange / 2);
        */

        leftPrevious = lef.position(degrees);
        rightPrevious = rig.position(degrees);
        sidePrevious = side.position(degrees);
        //inertialPrevious = inertial.rotation(degrees);
        anglePrevious += angleChange;

        wait(10, msec);

    }
    

}