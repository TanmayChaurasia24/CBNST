// The Bisection Method is a numerical method used to find the roots of a continuous function. It is based on the Intermediate Value Theorem, which states that if a function changes sign over an interval [a, b], then there is at least one root in that interval.

// The basic idea is to repeatedly divide the interval in half and select the subinterval where the function changes sign until the root is found with the desired accuracy.

#include <stdio.h>
#include <math.h>

// Function definition for which we need to find the root
double f(double x)
{
    return x * x * x - x * x + 2; // Example function: f(x) = x^3 - x^2 + 2
}

int main()
{
    //a, b: The endpoints of the initial interval [a, b] where the root lies.
    // c: The midpoint of the current interval, which will be refined iteratively.
    // tol: The tolerance level, which defines the accuracy of the root.
    // maxIterations: The maximum number of iterations allowed to prevent the method from running indefinitely.
    double a, b, c, tol;
    int maxIterations, iteration = 1;

    // Input values for interval [a, b] and tolerance
    printf("Enter the value of a: ");
    scanf("%lf", &a);
    printf("Enter the value of b: ");
    scanf("%lf", &b);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);

    // Ensure that the initial interval [a, b] brackets a root (i.e., f(a) * f(b) < 0)
    if (f(a) * f(b) >= 0)
    {
        printf("Invalid interval. The function must change sign over the interval.\n");
        return -1;
    }

    // Bisection method loop
    while (iteration <= maxIterations)
    {
        // Calculate the midpoint of the interval
        c = (a + b) / 2;

        // Check if the root is at the midpoint or the result is within the tolerance level
        if (f(c) == 0.0)
        {
            break;
        }

        // Print current iteration details
        printf("Iteration %d: c = %.6f, f(c) = %.6f\n", iteration, c, f(c));

        // Determine the new interval by checking the sign of f(c)
        if (f(a) * f(c) < 0)
        {
            b = c; // Root is in the left subinterval
        }
        else
        {
            a = c; // Root is in the right subinterval
        }

        iteration++;
    }

    // If maximum iterations reached without convergence
    if (iteration > maxIterations)
    {
        printf("The method did not converge after %d iterations.\n", maxIterations);
    }

    return 0;
}
