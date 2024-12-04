#include <math.h>
#include <stdio.h>

double f(double x) { return 1 / (1 + (x * x)); }

double simpsonsRule(double (*func)(double), double a, double b, int n) {
      if (n % 3 != 0) {
            printf("enter correct interval");
      }

      double h = (b - a) / n;
      double sum = func(a) + func(b);

      for (int i = 1; i < n; i++) {
            double x = a + i * h;
            if (i % 3 == 0) {
                  sum += 2 * func(x);
            } else {
                  sum += 3 * func(x);
            }
      }

      return (3.0 * h / 8.0) * sum;
}

int main() {
      double a, b;
      int n;

      printf("Enter the lower limit  ");
      scanf("%lf", &a);
      printf("Enter the upper limit");
      scanf("%lf", &b);
      printf("Enter the number of intervals");
      scanf("%d", &n);

      double result = simpsonsRule(f, a, b, n);

      printf("The integral result is: %lf\n", result);
      return 0;
}

