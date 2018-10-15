#include<stdio.h>
#include<stdlib.h>

double f(double x);
double real(double a, double b);

double f(double x) {
    return x*x;
}
double real(double a, double b) {
    return (b*b*b - a*a*a)/3;
}
double approx(double a, double b, double N) {
    double dx, xi, sum;

    dx = (b - a) / N;
    sum = 0;
    for (i = 0; i < N; i++) {
        xi = a + i*dx;
        sum = sum + f(xi);
    }
    return sum*dx;
}
int main(int argc, char *argv[]) {
    int i;
    double N, a, b, dx, xi, sum;

    a  = atof(argv[1]);
    b  = atof(argv[2]);
    N  = atof(argv[3]);

    double ap4 = approx(a, b, N);


    printf("%f, %f\n", sum*dx, real(a, b) - sum*dx);
}
