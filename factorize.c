#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>

void evaluate(long N);

int main(int argc, char *argv[])
{
    long N;

    N = LONG_MAX;
    evaluate(N);
    return 0;
}

/* evaluate: print out factors of N */
void evaluate(long N)
{
    long v;

    v = 2;
    while (v <= N/v) {
        while (N % v == 0) {
            printf("%ld ", v);
            N /= v;
        }
        ++v;
    }
    if (N > 1) printf("%ld ", N);
    printf("\n");
}
