// The Gauss-Seidel method is an iterative algorithm used to solve a system of linear equations of the form Ax = b, where A is a square matrix, x is the vector of unknowns, and b is the vector of constants. The method improves the solution step by step and uses the previously calculated values of unknowns to get better accuracy.


#include <stdio.h>
#include <math.h>

#define MAX_ITER 100 // Maximum number of iterations
#define TOLERANCE 0.0001 // Tolerance for convergence

void gaussSeidel(int n, float a[n][n], float b[n], float x[n]) {
    float temp_x[n]; // To store the values of x during iteration
    int iteration = 0; // Count of iterations
    float max_error;

    // Initialize the solution vector x with 0 (initial guess)
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }

    do {
        max_error = 0; // Reset the maximum error

        // For each unknown, calculate its new value
        for (int i = 0; i < n; i++) {
            float sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += a[i][j] * x[j];
                }
            }

            // Store the old value for error calculation
            temp_x[i] = x[i];
            
            // Update the value of x[i]
            x[i] = (b[i] - sum) / a[i][i];
            
            // Calculate the error for convergence check
            float error = fabs(x[i] - temp_x[i]);
            if (error > max_error) {
                max_error = error;
            }
        }

        iteration++;
    } while (max_error > TOLERANCE && iteration < MAX_ITER);

    // Output the results
    if (iteration < MAX_ITER) {
        printf("Converged in %d iterations.\n", iteration);
    } else {
        printf("Reached maximum iterations without full convergence.\n");
    }

    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i, x[i]);
    }
}

int main() {
    int n;

    // Input the number of variables
    printf("Enter the number of variables: ");
    scanf("%d", &n);

    float a[n][n], b[n], x[n];

    // Input the coefficient matrix A and the constant vector b
    printf("Enter the elements of matrix A (coefficients):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the elements of vector b (constants):\n");
    for (int i = 0; i < n; i++) {
        printf("b[%d]: ", i);
        scanf("%f", &b[i]);
    }

    // Call Gauss-Seidel function to solve the system
    gaussSeidel(n, a, b, x);

    return 0;
}











