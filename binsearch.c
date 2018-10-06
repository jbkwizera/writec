#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int a[]
    return 0;
}

/* binsearch: finds x in a[0] <= a[1] <= ... <= v[N-1] */
int search(int x, int a[], int N)
{
    int lo, hi, mid;

    lo = 0;
    hi = N-1;
    while (lo <= hi) {
        mid = lo + (hi - lo)/2;
        if      (x > a[mid]) lo = mid + 1;
        else if (x < a[mid]) hi = mid - 1;
        else    return mid;                 /* match found */
    }
    return -1; /* no match */
}
