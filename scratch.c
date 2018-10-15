#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAXN  1001             /* max length of my arrays */

int main(int argc, char *argv[])
{
    char i, ch;
    char s[MAXN];
    double matof(char s[]);
    int readline(char s[], int lim);
    double sum;

    sum = 0.0;
    while ((readline(s, MAXN) > 0)) {
        sum += matof(s);
        printf("%12.5f %13.5f\n", matof(s), sum);
    }
    return 0;
}

double matof(char s[]) {
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
