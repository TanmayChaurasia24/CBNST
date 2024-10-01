#include <stdio.h>
#include <math.h>  // For the fabs() function

// Function to define g(x) = 3 / x
float g(float x) {
    return 3 / x;
}

int main() {
    float x0, x1, error;
    int maxIterations, iteration = 0;

    // User inputs
    printf("Enter the initial guess: ");
    scanf("%f", &x0);  // Input initial guess from the user
    printf("Enter the tolerance (e.g., 0.0001): ");
    scanf("%f", &error);  // Input error tolerance
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);  // Input maximum iterations

    // Iteration loop
    do {
        // Apply the iteration formula x1 = g(x0)
        x1 = g(x0);

        // Print the current iteration details
        printf("Iteration %d: x = %f\n", iteration, x1);

        // Check if the difference between current and previous guess is small enough
        if (fabs(x1 - x0) < error) {
            break;  // If the difference is less than the tolerance, stop iterating
        }

        // Update x0 for the next iteration
        x0 = x1;

        // Increment iteration counter
        iteration++;

        // Check if we've hit the maximum number of iterations
        if (iteration >= maxIterations) {
            printf("Solution did not converge within the maximum iterations.\n");
            return 0;
        }

    } while (fabs(x1 - x0) >= error);  // Repeat until the difference is smaller than the tolerance

    // Print the result
    printf("The root is approximately: %f\n", x1);
    printf("Found in %d iterations.\n", iteration);

    return 0;
}
