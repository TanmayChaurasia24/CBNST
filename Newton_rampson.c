#include <stdio.h>
#include <math.h>

// Function f(x)
double f(double x) {
    return x * x - 4; // Example: f(x) = x^2 - 4
}

// Derivative of the function f(x)
double f_prime(double x) {
    return 2 * x; // Derivative: f'(x) = 2x
}

int main() {
    double x0, x1;
    int iter = 0;

    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    // Newton-Raphson iteration loop
    do {
        double f_x0 = f(x0);
        double f_prime_x0 = f_prime(x0);

        x1 = x0 - (f_x0 / f_prime_x0);
        
        // Print the current iteration and approximation of the root
        iter++;
        printf("Iteration %d: x = %lf\n", iter, x1);
        
        // Update the guess for the next iteration
        x0 = x1;

    } while (fabs(f(x1)) > 0.001); // Check for convergence

    return 0;
}
