#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#define MAXN    1000

double newton(double x);
void mitoa(int N, char s[]);
int matoi(char s[]);
int htoi(char s[]);


int main(int argc, char *argv[])
{
    int x;
    char s[20];

    x = matoi(argv[1]);
    printf("%d\n", x);
    mitoa(x, s);
    printf("%s\n", s);
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

void mitoa(int N, char s[]) {
    int i, j, ch, sign;

    sign = (N < 0)? -1: +1;
    if (sign < 0)
        N = -N;
    i = 0;
    while (N > 0) {
        s[i++] = N % 10 + '0';
        N /= 10;
    }
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    for (j = 0; j < i/2; j++) {
        ch = s[i-j-1];
        s[i-j-1] = s[j];
        s[j] = ch;
    }
}
