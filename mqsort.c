#include <stdio.h>
#include "mrandom.h"

void msort(int[], int, int);

int main(int argc, char const *argv[])
{

    int N = 10;
    int a[N] = {0};

    munif(a, N, -100, 100);
    for (int i = 0; i < N; i++)
        printf("%4d ", a[i]);
    printf("\n\n");
    msort(a, 0, N-1);

    for (int i = 0; i < N; i++)
        printf("%4d ", a[i]);
    printf("\n");

    return 0;
}

void msort(int a[], int lo, int hi)
{
    int i, last, mid;
    void exch(int a[], int i, int j);

    if (lo >= hi)   /* do nothing if array contains */
        return;     /* fewer than two elements */

    mid = lo + (hi - lo)/2;
    exch(a, lo, mid);               /* move pivot to the front */
    last = lo;
    for (i = lo+1; i <= hi; i++)    /* partition */
        if (a[i] < a[lo])
            exch(a, ++last, i);

    exch(a, lo, last);              /* restore pivot */
    msort(a, lo, last-1);
    msort(a, last+1, hi);
}

void exch(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
