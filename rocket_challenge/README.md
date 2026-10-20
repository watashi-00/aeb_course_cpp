# Rocket Trajectory Simulator

Interactive C++ program developed for an AEB (Brazilian Space Agency) challenge. It simulates rocket trajectories using the equations of oblique projectile motion.

## How to Run

Clone the repository:

```bash
git clone https://github.com/watashi-00/aeb_course_cpp.git
cd aeb_course_cpp
```

Compile the program:

```bash
g++ -std=c++20 -O2 rocket_challenge/rocket_launch.cpp -o rocket
```

Run it:

```bash
./rocket
```

## Input

The program requests the following parameters:

- Rocket mass (kg)
- Initial velocity (m/s)
- Launch angle (degrees, from 0 to 90)

## Physics

The simulation assumes constant gravitational acceleration (9.80665 m/s²) and ignores air resistance and engine thrust.

The initial velocity is split into horizontal and vertical components:

- Horizontal velocity: `Vx = V0 * cos(angle)`
- Vertical velocity: `Vy = V0 * sin(angle)`

The program calculates the rocket's position and velocity over time and records each simulation frame.

## Limitations

- Rocket mass does not affect the calculations.
- Engine thrust and fuel consumption are not simulated.
- Air resistance is ignored.
- Gravity remains constant throughout the simulation.

The model represents projectile motion, not a complete powered rocket launch.

## Requirements

- GCC or Clang with C++20 support
- Linux, macOS, or Windows with a compatible C++ toolchain

## License

No license.