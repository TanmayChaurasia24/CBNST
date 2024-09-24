#include <stdio.h>

// Function to calculate factorial
int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// Function to perform Newton's Backward Interpolation
void newtonBackwardInterpolation(double x[], double y[], int n, double value)
{
    double differenceTable[n][n];

    // Initializing the difference table with y values
    for (int i = 0; i < n; i++)
    {
        differenceTable[i][0] = y[i];
    }

    // Calculating backward differences
    for (int j = 1; j < n; j++)
    {
        for (int i = n - 1; i >= j; i--)
        {
            differenceTable[i][j] = differenceTable[i][j - 1] - differenceTable[i - 1][j - 1];
        }
    }

    // Displaying the backward difference table
    printf("\nBackward Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%f ", differenceTable[i][j]);
        }
        printf("\n");
    }

    // Calculate u
    double h = x[1] - x[0]; // Assuming uniform spacing
    double u = (value - x[n - 1]) / h;

    // Interpolating the value
    double result = y[n - 1]; // Initialize with the last y value (f(x_n))
    double u_term = 1;        // u(u+1)(u+2)... term starts from 1

    for (int i = 1; i < n; i++)
    {
        u_term *= (u + (i - 1));
        result += (u_term * differenceTable[n - 1][i]) / factorial(i);
    }

    // Print the interpolated value
    printf("\nThe interpolated value at x = %lf is: %lf\n", value, result);
}

int main()
{
    int n;
    double value;

    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];

    // Input the data points
    printf("Enter the values of x and corresponding y:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i);
        scanf("%lf", &y[i]);
    }

    // Input the value of x for which we want to interpolate
    printf("Enter the value of x to interpolate: ");
    scanf("%lf", &value);

    // Perform Newton's backward interpolation
    newtonBackwardInterpolation(x, y, n, value);

    return 0;
}
