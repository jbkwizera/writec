#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void munif(int a[], int N, int lo, int hi)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < N; i++)
        a[i] = (rand() % (hi - lo + 1)) + lo;
}
