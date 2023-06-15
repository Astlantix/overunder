#include "vex.h"

//degrees to inches value for auton functions
double dti = 23;

//Forward function
void For(double joe) {
    fl.spinFor(fwd,joe,deg,false);
    fr.spinFor(fwd,joe,deg,false);
    bl.spinFor(fwd,joe,deg,false);
    br.spinFor(fwd,joe,deg);
}

//Backward function
void Rev(double joe) {
    fl.spinFor(rev,joe,deg,false);
    fr.spinFor(rev,joe,deg,false);
    bl.spinFor(rev,joe,deg,false);
    br.spinFor(rev,joe,deg);
}

//Left function
void Left(double joe) {
    fl.spinFor(rev,joe,deg,false);
    fr.spinFor(fwd,joe,deg,false);
    bl.spinFor(fwd,joe,deg,false);
    br.spinFor(rev,joe,deg);
}

//Right function
void Right(double joe) {
    fl.spinFor(fwd,joe,deg,false);
    fr.spinFor(rev,joe,deg,false);
    bl.spinFor(rev,joe,deg,false);
    br.spinFor(fwd,joe,deg);
}