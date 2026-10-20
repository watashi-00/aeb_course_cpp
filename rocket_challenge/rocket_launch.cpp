
#include <cmath>
#include <cstdio>
#include <vector>
#include <limits>

constexpr double PI = 3.14159265358979323846;
constexpr double G = 9.80665; // Earth's gravitational acceleration (m/s²)

constexpr double toRadians(double degrees) {
    return degrees * (PI / 180.0);
}

struct Vector2 {
    double x = 0.0;
    double y = 0.0;
};

struct Rocket {
    double mass = 100.0;        // Rocket mass in kilograms
    double launchSpeed = 100.0; // Initial speed in meters per second
    double angle = 90.0;        // Launch angle in degrees

    Vector2 position{};
    Vector2 velocity{};

    double elapsedTime = 0.0;
};

struct Frame {
    double time;
    Vector2 position;
    Vector2 velocity;
};

// Reads a numeric value and validates its allowed range.
double readDouble(const char* prompt, double min, double max) {
    double value;

    while (true) {
        std::printf("%s", prompt);

        if (std::scanf("%lf", &value) == 1 &&
            std::isfinite(value) &&
            value >= min && value <= max) {
            return value;
        }

        std::printf("Invalid input. Enter a value between "
                    "%.2f and %.2f.\n", min, max);

        // Clear invalid input from the standard input buffer.
        int ch;
        while ((ch = std::getchar()) != '\n' && ch != EOF) {}
    }
}

// Calculates the initial velocity components from the launch angle.
void initialize(Rocket& rocket) {
    const double theta = toRadians(rocket.angle);

    rocket.velocity.x =
        rocket.launchSpeed * std::cos(theta);

    rocket.velocity.y =
        rocket.launchSpeed * std::sin(theta);
}

// Advances the simulation by one time step.
// This model assumes constant gravity and no air resistance.
void simulateStep(Rocket& rocket, double dt) {
    rocket.position.x += rocket.velocity.x * dt;

    rocket.position.y += rocket.velocity.y * dt
                       - 0.5 * G * dt * dt;

    rocket.velocity.y -= G * dt;

    rocket.elapsedTime += dt;
}

int main() {
    Rocket rocket;

    std::printf("=== Rocket Trajectory Simulator ===\n\n");

    // Collect simulation parameters from the user.
    rocket.mass = readDouble(
        "Rocket mass (kg): ", 0.001, 1e9
    );

    rocket.launchSpeed = readDouble(
        "Initial velocity (m/s): ", 0.0, 1e6
    );

    rocket.angle = readDouble(
        "Launch angle (degrees, 0-90): ", 0.0, 90.0
    );

    initialize(rocket);

    constexpr double dt = 0.01;
    constexpr double maxFlightTime = 1000.0;

    std::vector<Frame> history;

    // Store the initial state and each subsequent simulation frame.
    while (rocket.position.y >= 0.0 ||
           rocket.elapsedTime == 0.0) {

        history.push_back({
            rocket.elapsedTime,
            rocket.position,
            rocket.velocity
        });

        simulateStep(rocket, dt);

        if (rocket.elapsedTime >= maxFlightTime) {
            std::printf("Warning: Maximum simulation time reached.\n");
            break;
        }
    }

    std::printf("\n=== Simulation Results ===\n");
    std::printf("Flight time:         %.2f s\n",
                rocket.elapsedTime);
    std::printf("Horizontal distance: %.2f m\n",
                rocket.position.x);
    std::printf("Final height:        %.2f m\n",
                rocket.position.y);
    std::printf("Frames recorded:     %zu\n",
                history.size());

    return 0;
}
