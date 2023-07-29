#include "vex.h"

const double π = atan(1) * 4;

const double circ = (3.25 * π)/36000; // circumference of the wheel

double xpos = 0;
double ypos = 0;

void odometry() {

    double lprev = lef.position(degrees);
    double rprev = rig.position(degrees);
    double sprev = side.position(degrees);
    double angprev = 0;
    //double inertialPrevious = inertial.rotation(degrees);

    double ldist = 1.75;
    double rdist = 1.75;
    double sdist = 1.75;

    while (1) {
        
        double ΔLeft = lef.position(degrees) - lprev;
        double ΔRight = rig.position(degrees) - rprev;
        double ΔSide = side.position(degrees) - sprev;
        //double ΔInertial = inertial.rotation(degrees) - inertialPrevious;

        ΔLeft *= circ;
        ΔRight *= circ;
        ΔSide *= circ;
        //ΔInertial *= π / 18000;

        double angchange = (ΔLeft - ΔRight) / (ΔLeft + ΔRight);
        //double angchange = ΔInertial;

        double locΔX;
        double locΔY;
        
        if(angchange==0) {
            locΔX = ΔSide;
            locΔY = ΔRight;
        }

        else {
            double radiusFront = ΔLeft / angchange - ldist;
            double radiusSide = ΔRight / angchange - sdist;

            locΔX = 2 * radiusSide * sin(angchange / 2);
            locΔY = 2 * radiusFront * sin(angchange / 2);
        }

        //#1
        double distance = sqrt(locΔX * locΔX + locΔY * locΔY);
        xpos += distance * cos(atan(locΔY / locΔX) - angprev - angchange / 2);
        ypos += distance * sin(atan(locΔY / locΔX) - angprev - angchange / 2);

        //#2
        /*
        xpos += locΔX * sin(angprev + angchange / 2) + locΔY * cose(angprev + angchange / 2);
        ypos += locΔX * cos(angprev + angchange / 2) - locΔY * sin(angprev + angchange / 2);
        */

        lprev = lef.position(degrees);
        rprev = rig.position(degrees);
        sprev = side.position(degrees);
        //inertialPrevious = inertial.rotation(degrees);
        angprev += angchange;

        wait(10, msec);

    }
    
}
