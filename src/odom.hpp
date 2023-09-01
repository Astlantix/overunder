#include "vex.h"

const double π = atan(1) * 4;

const double circ = (3.25 * π)/36000; // circumference of the wheel

double xpos = 0;
double ypos = 0;

double dti;

//turning
void dturn (double joe) {
    double turning = inert.rotation(degrees) + joe;
    while (inert.rotation(degrees) < turning) {
        fl.spin(fwd);
        fr.spin(reverse);
        bl.spin(fwd);
        br.spin(reverse);
    }
    while (inert.rotation(degrees) > turning) {
        fl.spin(reverse);
        fr.spin(fwd);
        bl.spin(reverse);
        br.spin(fwd);
    }
}

//moving
void fwdrev (double joey) {
    double joe = joey * dti;
    fl.spinFor(fwd,joe,degrees,false);
    fr.spinFor(fwd,joe,degrees,false);
    ml.spinFor(fwd,joe,degrees,false);
    mr.spinFor(fwd,joe,degrees,false);
    bl.spinFor(fwd,joe,degrees,false);
    br.spinFor(fwd,joe,degrees);
}

void odometry() {

    double lprev = lef.position(degrees);
    double rprev = rig.position(degrees);
    //double sprev = side.position(degrees);
    double angprev = 0;
    double iprev = inert.rotation(degrees);

    double ldist = 1.75;
    double rdist = 1.75;
    //double sdist = 1.75;

    while (1) {
        
        double Δleft = lef.position(degrees) - lprev;
        double Δright = rig.position(degrees) - rprev;
        //double Δside = side.position(degrees) - sprev;
        double Δi = inert.rotation(degrees) - iprev;

        Δleft *= circ;
        Δright *= circ;
        //Δside *= circ;
        Δi *= π / 18000;

        //double angchange = (Δleft - Δright) / (Δleft + Δright);
        double angchange = Δi;

        double locΔX;
        double locΔY;
        
        if(angchange==0) {
            locΔX = Δi;
            locΔY = Δright;
        }

        else {
            double radf = Δleft / angchange - ldist;
            double rads = Δright / angchange - sdist;

            locΔX = 2 * rads * sin(angchange / 2);
            locΔY = 2 * radf * sin(angchange / 2);
        }

        //#1
        double distance = sqrt(locΔX * locΔX + locΔY * locΔY);
        xpos += distance * cos(atan(locΔY / locΔX) - iprev - Δi / 2);
        ypos += distance * sin(atan(locΔY / locΔX) - iprev - Δi / 2);

        //#2
        /*
        xpos += locΔX * sin(angprev + angchange / 2) + locΔY * cose(angprev + angchange / 2);
        ypos += locΔX * cos(angprev + angchange / 2) - locΔY * sin(angprev + angchange / 2);
        */

        lprev = lef.position(degrees);
        rprev = rig.position(degrees);
        //sprev = side.position(degrees);
        iprev = inert.rotation(degrees);
        angprev += angchange;

        wait(10, msec);

    }
    
}

//Pure Pursuit
void travel(double x, double y) {
    //distance from current point to target point
    double dist = sqrt((x - xpos) * (x - xpos) + (y - ypos) * (y - ypos));
    //angle from current point to target point
    double ang = atan2(y - ypos, x - xpos);
    //angle from current point to target point relative to robot
    double relang = ang - inert.rotation(degrees);
    //angle from current point to target point relative to robot in degrees
    double relangdeg = relang * 180 / π;
    //turning to correct angle to be facing target point
    dturn(relangdeg);
    //moving to target point
    fwdrev(dist);
}