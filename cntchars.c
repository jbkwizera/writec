#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAXN  100             /* max length of my arrays */

int main(int argc, char *argv[])
{
    int c, i, cntwhite, cntother, cntdigit[15];

    cntwhite = cntother = 0;
    for (i = 0; i < 10; i++)
        cntdigit[i] =0;

    while ((c = getchar()) != EOF) {
        if      (c >= '0' && c <= '9')
            cntdigit[c - '0']++;
        else if (c == ' ' || c == '\t' || c == '\n')
            cntwhite++;
        else
            cntother++;
    }
    printf("digits counts\n");
    for (i = 0; i < 10; i++)
        printf("%4d", i);
    printf("\n");
    for (i = 0; i < 10; i++)
        printf("%4d", cntdigit[i]);
    printf("\n");

    printf("whitespaces: %4d\n", cntwhite);
    printf("other chars: %4d\n", cntother);
}
