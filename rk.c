#include <stdio.h>

double f(double x, double y) {
    return (x * x – y); 
}

void rungeKutta4(double x0, double y0, double xn, double h) {
    double x = x0, y = y0;
    int step = 1;
  
    printf("Step\t   x\t         y\t        k1\t        k2\t        k3\t        k4\n");
  
    printf("-------------------------------------------------------------------------------\n");
  
    while (x < xn) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x + h, y + k3);
        double y1 = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0, x1 = x + h;
      
        printf("%d\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\n", 
               step, x, y, k1, k2, k3, k4);
        x = x1;
        y = y1;
        step++;
    }

    printf("Final value at x = %.6lf is y = %.6lf\n", x, y);
}
int main() {
    double x0, y0, xn, h;

    printf("Enter the initial value of x (x0): ");
    scanf("%lf", &x0);

    printf("Enter the initial value of y (y0): ");
    scanf("%lf", &y0);

    printf("Enter the final value of x (xn): ");
    scanf("%lf", &xn);

    printf("Enter the step size (h): ");
    scanf("%lf", &h);

    if(h==0 || xn<x0){
	    printf(“stepsize or xn is incorrect\n”);
      return 0;
    }
      
    rungeKutta4(x0, y0, xn, h);
    return 0;
}
