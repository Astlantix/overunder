#include "vex.h"

double π = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263560827785771342757789609173637178721468440901224953430146549585371050792279689258923542019956112129021960864034418159813629774771309960518707211349999998372978049951059731732816096318595024459455346908302642522308253344685035261931188171010003137838752886587533208381420617177669147303598253490428755468731159562863882353787593751957781857780532171226806613001927876611195909216420198;

//replace 4 with your wheel diameter for odom pods (units don't matter as long as you use them all across the code)
double wheelDiameter = 4;
double wheelCircumference = wheelDiameter * π;
double ticksPerRev = 360;
double ticksPerInch = ticksPerRev / wheelCircumference;

//forward and backward movement in inches (or whatever units you use)
void fwdrev(double joe) {
  fl.spinFor(fwd, joe*ticksPerInch, deg,false);
  fr.spinFor(fwd,joe*ticksPerInch, deg, false);
  bl.spinFor(fwd,joe*ticksPerInch, deg, false);
  br.spinFor(fwd,joe*ticksPerInch, deg);
}


//turning, input degrees, and turn value input times a constant based on your wheel to make it actually turn the right amount
void turn(double joe) {
  fl.spinFor(fwd, joe*1.5, deg,false);
  fr.spinFor(fwd,-joe*1.5, deg, false);
  bl.spinFor(fwd,joe*1.5, deg, false);
  br.spinFor(fwd,-joe*1.5, deg);
}

//the reason we are multipying by 1.5 is because the robot turns 1.5 times as much as it moves forward

double x;
double y;

//odometry
void odometry() {
  xpos.setPosition(x,deg);
  ypos.setPosition(y,deg);

  while(1) {
    x = xpos.position(deg)*ticksPerInch;
    y = ypos.position(deg)*ticksPerInch;
    wait(20, msec);
  }
}

void travel(double xcor, double ycor) {
  double xdiff = xcor - x;
  double ydiff = ycor - y;
  double distance = sqrt(xdiff*xdiff + ydiff*ydiff);
  double angleDiff = atan2(ydiff,xdiff) * 180 / π;
  turn(angleDiff);
  fwdrev(distance);
}


/*#include "vex.h"

void odometry() {}

double x = GPST.xPosition(inches);
double y = GPST.yPosition(inches);
void travel(double xcor, double ycor) {
    double dist = sqrt(pow(xcor - x, 2) + pow(ycor - y, 2));
    double angle = atan2(ycor - y, xcor - x);
    while (dist > 0.5) {
        double x = GPST.xPosition(inches);
        double y = GPST.yPosition(inches);
        double dist = sqrt(pow(xcor - x, 2) + pow(ycor - y, 2));
        double angle = atan2(ycor - y, xcor - x);
        double theta = GPST.heading(degrees);
        double error = angle - theta;
        double turn = error * 0.5;
        double speed = dist * 0.5;
        if (speed > 100) {
            speed = 100;
        }
        if (speed < -100) {
            speed = -100;
        }
        if (turn > 100) {
            turn = 100;
        }
        if (turn < -100) {
            turn = -100;
        }
        if (error > 180) {
            error = error - 360;
        }
        if (error < -180) {
            error = error + 360;
        }
        if (error > 0) {
            if (error < 90) {
                fl.spin(forward, speed + turn, percent);
                bl.spin(forward, speed + turn, percent);
                fr.spin(forward, speed - turn, percent);
                br.spin(forward, speed - turn, percent);
            } else {
                fl.spin(forward, speed - turn, percent);
                bl.spin(forward, speed - turn, percent);
                fr.spin(forward, speed + turn, percent);
                br.spin(forward, speed + turn, percent);
            }
        } else {
            if (error > -90) {
                fl.spin(forward, speed - turn, percent);
                bl.spin(forward, speed - turn, percent);
                fr.spin(forward, speed + turn, percent);
                br.spin(forward, speed + turn, percent);
            } else {
                fl.spin(forward, speed + turn, percent);
                bl.spin(forward, speed + turn, percent);
                fr.spin(forward, speed - turn, percent);
                br.spin(forward, speed - turn, percent);
            }
        }
    }
}*/