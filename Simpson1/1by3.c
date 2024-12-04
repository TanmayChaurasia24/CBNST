#include <stdio.h>
#include <math.h>

double f(double x) {
    return sin(x);
}

double simpsonsRule(double (*func)(double), double a, double b, int n) {
    if (n % 2 != 0){
        n++;  
    }

    double h = (b - a) / n; 
    double sum = func(a) + func(b); 

    for (int i = 1; i < n; i++){
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * func(x);
        } else {
            sum += 4 * func(x);  
        }
    }

    sum *= h / 3; 
    return sum;
}

int main(){
    double a,b;
    int n;

    printf("Enter the lower limit");
    scanf("%lf",&a);

    printf("Enter the upper limit");
    scanf("%lf",&b);

    printf("Enter the number of intervals");
    scanf("%d",&n);

    double result = simpsonsRule(f,a,b,n);  

    printf("The integral result is: %lf\n", result);
    return 0;
}
