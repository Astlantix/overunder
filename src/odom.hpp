#include "vex.h"

const double π = atan(1) * 4;

const double circ = (3.25 * π)/36000; // circumference of the wheel

double xpos = 0; // x coordinate
double ypos = 0; // y coordinate

double dti; // distance to inches

//turning
void dturn (double joe) {
    fl.spinFor(joe,degrees,false);
    fr.spinFor(-joe,degrees,false);
    ml.spinFor(joe,degrees,false);
    mr.spinFor(-joe,degrees,false);
    bl.spinFor(joe,degrees,false);
    br.spinFor(-joe,degrees);
}

//moving forward and backward
void fwdrev (double joey) {
    double joe = joey * dti;
    fl.spinFor(fwd,joe,degrees,false);
    fr.spinFor(fwd,joe,degrees,false);
    ml.spinFor(fwd,joe,degrees,false);
    mr.spinFor(fwd,joe,degrees,false);
    bl.spinFor(fwd,joe,degrees,false);
    br.spinFor(fwd,joe,degrees);
}

//odometry
void odometry() {
    double lprev = lef.position(degrees); //left previous position
    double rprev = rig.position(degrees); //right previous position
    double sprev = side.position(degrees); //side previous position
    double angprev = 0; //previous angle
    //double iprev = inert.rotation(degrees);

    double ldist = 1.75; //left distance to tracking center
    double rdist = 1.75; //right distance to tracking center
    double sdist = 1.75; //side distance to tracking center

    while (1) {
        
        double Δleft = lef.position(degrees) - lprev; //change in left position
        double Δright = rig.position(degrees) - rprev; //change in right position
        double Δside = side.position(degrees) - sprev; //change in side position
        //double Δi = inert.rotation(degrees) - iprev; //change in angle

        Δleft *= circ; //change in left position in inches
        Δright *= circ; //change in right position in inches
        Δside *= circ; //change in side position in inches
        //Δi *= π / 18000; //change in angle in radians

        double angchange = (Δleft - Δright) / (Δleft + Δright); //change in angle
        //double angchange = Δi; //change in angle

        double locΔX;
        double locΔY;
        
        //if the robot is moving straight
        if(angchange==0) {
            locΔX = Δside;
            locΔY = Δright;
        }

        //if the robot is turning
        else {
            double radf = Δleft / angchange - ldist;
            double rads = Δright / angchange - sdist;

            locΔX = 2 * rads * sin(angchange / 2);
            locΔY = 2 * radf * sin(angchange / 2);
        }

        //#1 calculating new position

        double distance = sqrt(locΔX * locΔX + locΔY * locΔY); //distance traveled
        xpos += distance * cos(atan(locΔY / locΔX) - angprev - angchange / 2); //new x position
        ypos += distance * sin(atan(locΔY / locΔX) - angprev - angchange / 2); //new y position

        //#2 calculating new position

        /*
        xpos += locΔX * sin(angprev + angchange / 2) + locΔY * cose(angprev + angchange / 2);
        ypos += locΔX * cos(angprev + angchange / 2) - locΔY * sin(angprev + angchange / 2);
        */

        lprev = lef.position(degrees); //updating left previous position
        rprev = rig.position(degrees); //updating right previous position
        sprev = side.position(degrees); //updating side previous position
        angprev += angchange; //updating previous angle
        //iprev = inert.rotation(degrees); //updating previous angle

        wait(10, msec);
    }
    
}

//Pure Pursuit
void travel(double x, double y) {
    //distance from current point to target point
    double dist = sqrt((x - xpos) * (x - xpos) + (y - ypos) * (y - ypos));
    //angle from current point to target point in degrees
    double relangdeg = atan((y - ypos) / (x - xpos)) * 180 / π;
    //turning to correct angle to be facing target point
    dturn(relangdeg);
    //moving to target point
    fwdrev(dist);
}