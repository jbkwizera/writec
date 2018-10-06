#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#define MAXN    1000

double newton(double x);
int matoi(char s[]);
int htoi(char s[]);

int main(int argc, char *argv[])
{
    double x;

    x = matoi(argv[1]);
    printf("%.0f\n", x);
    printf("approx: %.15f\n", newton(x));
    printf("actual: %.15f\n", sqrt(x));
    return 0;
}

/* newton: sqrt using newton's method */
double newton(double x)
{
    if (x < 0.0) return 0.0/0;
    double t, e;

    e = 1E-15;
    t = x;
    while (fabs(t - x/t) > e*t)
        t = (t + x/t) / 2.0;
    return t;
}

/* htoi: hexadecimal to int */
int htoi(char s[])
{
    double res, v;
    int i, c, N;

    N   = strlen(s);
    res = 0;
    v   = 0;
    if (N > 2 && s[0] == '0' && s[1] == 'x')
        i = 2;
    while (s[i] != '\0') {
        v = pow(16, N-i-1);
        c = toupper(s[i]);
        if (isdigit(c)) v *= c - '0';
        else            v *= c - 'A' + 10;
        res += v;
        ++i;
    }
    return (int) res;
}

/* matoi: string to int */
int matoi(char s[])
{
    int i, n, sign;

    for (i = 0; s[i] == ' '; i++)
        ;
    sign = (s[i] == '-')? -1: +1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = n * 10 + (s[i] - '0');
    return sign*n;
}
