/*
The Regula Falsi Method (also called the False Position Method) is another root-finding technique for continuous functions, similar to the Bisection Method. Like Bisection, it requires an initial interval [a, b] where the function changes sign, indicating a root. However, instead of halving the interval, Regula Falsi uses a linear interpolation to estimate the root. This results in potentially faster convergence than the Bisection Method in some cases.


*/
#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x - x * x + 2;  // Example function: f(x) = x^3 - x^2 + 2
}

int main() {
    double a, b, c;
    int maxIterations, iteration = 0;

    // Input the values for interval [a, b] and max iterations
    printf("Enter the value of a: ");
    scanf("%lf", &a);
    printf("Enter the value of b: ");
    scanf("%lf", &b);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);

    // Check if the initial interval is valid (function must change sign over the interval)
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval. The function must change sign over the interval.\n");
        return -1;
    }

    // Regula Falsi method loop
    while (iteration <= maxIterations) {
        // Calculate the point where the line connecting f(a) and f(b) intersects the x-axis
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        // Check if the root is found or the result is within the tolerance level
        if (f(c) == 0.0) {
            break;
        }

        // Print current iteration details
        printf("Iteration %d: c = %.6f, f(c) = %.6f\n", iteration, c, f(c));

        // Update the interval [a, b]
        if (f(a) * f(c) < 0) {
            b = c;  // Root is in the left subinterval
        } else {
            a = c;  // Root is in the right subinterval
        }

        iteration++;
    }

    // If maximum iterations reached without convergence
    if (iteration > maxIterations) {
        printf("The method did not converge after %d iterations.\n", maxIterations);
    } else {
        // Print the root
        printf("Approximate root found at c = %.6f after %d iterations.\n", c, iteration);
    }

    return 0;
}
