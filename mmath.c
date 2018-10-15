#include<string.h>
#include<limits.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#define MAXN    1000

double msqrt(double x);
void mitoa(int n, char s[]);
int matoi(char s[]);
double matof(char s[]);
int mbtoi(char s[], int b);
void mitob(int n, char s[], int b);


int main(int argc, char *argv[])
{
    int n, b;
    char s[MAXN];
    strcpy(s, argv[1]);
    printf("%d\n", matoi(s));
    return 0;
}

/* msqrt: sqrt using newton's method */
double msqrt(double x)
{
    if (x < 0.0) return 0.0/0;
    double t, e;

    e = 1E-15;
    t = x;
    while (fabs(t - x/t) > e*t)
        t = (t + x/t) / 2.0;
    return t;
}

/* matoi: string to int. */
int matoi(char s[])
{
    int i, v, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? -1: +1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (v = 0; isdigit(s[i]); i++)
        v  = v * 10 + (s[i] - '0');
    return sign*v;
}

/* matof: string to float/double. */
double matof(char s[])
{
    int i, sign;
    double v, p;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? -1: +1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (v = 0.0; isdigit(s[i]); i++)
        v  = 10.0 * v + (s[i] - '0');

    if (s[i] == '.') i++;
    for (p = 1.0; isdigit(s[i]); i++) {
        v  = 10.0 * v + (s[i] - '0');
        p *= 10.0;
    }
    return sign * v / p;
}

/* mitoa: integer to string. */
void mitoa(int n, char s[])
{
    int i, j, ch, sign, r;

    sign = (n < 0)? -1: +1;
    r = 0;
    if (sign < 0) {
        if (n == INT_MIN)
            r = 1, n +=1;
        n = -n;
    }
    i = 0;
    while (n > 0) {
        s[i++] = n % 10 + '0';
        n /= 10;
    }
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    for (j = 0; j < i/2; j++) {
        ch = s[i-j-1];
        s[i-j-1] = s[j];
        s[j] = ch;
    }
    s[i-1] += r;
}

/* mitob: from int to radix base. */
void mitob(int n, char s[], int b)
{
    int i, j, ch, d;

    i = 2;
    while (n > 0) {
        d  = n % b;
        n /= b;
        s[i++] = (d < 10)? d + '0': 'A' + d%10;
    }
    s[i] = '\0';
    for (j = 2; j < i/2; j++) {
        ch = s[i-j-1];
        s[i-j-1] = s[j];
        s[j] = ch;
    }
}

/* mbtoi: from radix base to int. */
int mbtoi(char s[], int b)
{
    double res;
    int i, d, N;

    N = strlen(s);
    res = 0;
    for (i = 0; s[i] != '\0'; i++) {
        d = (s[i] <= '9')? s[i] - '0': s[i] - 'A' + 10;
        res += d * pow(b, N-i-1);
    }
    return (int) res;
}
