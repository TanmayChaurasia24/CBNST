// P(x) = f(x0) + u/1! *Δf(x0) + u(u−1)/2! * Δ2 f(x 0) + u(u−1)(u−2)/3! *Δ3f(x0).....

#include <stdio.h>

           int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

void newtonForwardInterpolation(double x[], double y[], int n, double value)
{
    double differenceTable[n][n];

    for (int i = 0; i < n; i++)
    {
        differenceTable[i][0] = y[i];
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            differenceTable[i][j] = differenceTable[i + 1][j - 1] - differenceTable[i][j - 1];
        }
    }

    printf("Forward Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%f ", differenceTable[i][j]);
        }
        printf("\n");
    }

    double h = x[1] - x[0];
    double u = (value - x[0]) / h;

    double result = y[0]; // Initialize with the first y value (f(x_0))
    double u_term = 1;    // u(u-1)(u-2)... term starts from 1

    for (int i = 1; i < n; i++)
    {
        u_term *= (u - (i - 1));
        result += (u_term * differenceTable[0][i]) / factorial(i);
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

    // Perform Newton's forward interpolation
    newtonForwardInterpolation(x, y, n, value);

    return 0;
}
