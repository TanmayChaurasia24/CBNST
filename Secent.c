#include <stdio.h>
#include <math.h>

// Define the function for which we want to find the root
double f(double x) {
    return x * x * x - x * x + 2; // Example: f(x) = x^3 - x^2 + 2
}

// Secant Method to find the root of a function
void secantMethod(double x0, double x1, double tolerance, int maxIterations) {
    double x2, f0, f1, f2;
    int iteration = 0;

    // Print the header for the output
    printf("Iteration\t  x0\t\t  x1\t\t  x2\t\t  f(x2)\n");
    printf("------------------------------------------------------------\n");

    do {
        f0 = f(x0);  // Calculate f(x0)
        f1 = f(x1);  // Calculate f(x1)

        // Check if the denominator becomes zero (to avoid division by zero)
        if (fabs(f1 - f0) < tolerance) {
            printf("Denominator is too small. Division by zero error may occur.\n");
            return;
        }

        // Apply the Secant Method formula to find the next approximation x2
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);

        f2 = f(x2);  // Calculate f(x2)

        // Print the current iteration, values of x0, x1, x2, and f(x2)
        printf("%d\t\t  %.6lf\t  %.6lf\t  %.6lf\t  %.6lf\n", iteration, x0, x1, x2, f2);

        // Check if the result is close enough to the root (within the given tolerance)
        if (fabs(f2) < tolerance) {
            printf("Root found at x = %.6lf after %d iterations\n", x2, iteration + 1);
            return;
        }

        // Update x0 and x1 for the next iteration
        x0 = x1;
        x1 = x2;

        // Increment the iteration count
        iteration++;

    } while (iteration < maxIterations);  // Continue until the maximum number of iterations

    // If the loop exits without finding the root, print a message
    printf("Root not found within the maximum number of iterations.\n");
}

int main() {
    // Initial guesses for x0 and x1
    double x0 = -20.0;
    double x1 = -15.0;

    // Define the tolerance (acceptable error) and the maximum number of iterations
    double tolerance = 0.000001;  // Desired precision
    int maxIterations = 100;      // Limit the number of iterations

    // Call the secant method function
    secantMethod(x0, x1, tolerance, maxIterations);

    return 0;
}
