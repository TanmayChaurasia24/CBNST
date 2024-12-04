#include <math.h>
#include <stdio.h>

double f(double x) { return sin(x); }

double trapezoidalRule(double (*func)(double), double a, double b, int n) {
      double h = (b - a) / n;
      double sum = 0.5 * (func(a) + func(b));

      for (int i = 1; i < n; i++) {
            double x = a + i * h;
            sum += func(x);
      }

      sum *= h;
      return sum;
}

int main() {
      double a, b;
      int n;
      printf("Enter the lower limit");
      scanf("%lf", &a);
      printf("Enter the upper limit");
      scanf("%lf", &b);
      printf("Enter the number of intervals");
      scanf("%d", &n);
      double result = trapezoidalRule(f, a, b, n);
      printf("The integral result is: %.10lf\n", result);

      return 0;
}
