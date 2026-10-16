#include <stdio.h>
#include <cmath>

// consider:
//  - Vx: horizontal velocity
//  - Vy: vertical velocity
//  - Tg: global elapsed time
//  - Tta: launch angle
//
// not considered for now:
//  - air resistance
//
// extras:
//  - frame times (persist simulation state at specific timestamps
//    to reconstruct the launch state at a given frame)
//  - time steps (define the interval between simulation frames)
//  - trajectory history (store the state of the rocket at each frame)

#define PI 3.1415 

double convertRadians(double &value);

int main() {

    double teta = 90.0;

    double cosVx  = cos(convertRadians(teta));
    double cosVy  = sin(convertRadians(teta));

    return 0;
}

double convertRadians(double &value) {
    value *(PI / 180.0);
}