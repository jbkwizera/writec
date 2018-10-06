#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define MAXN 1000

void readints(int a[]);
void sort(int a[], int N);
void exch(int a[], int i, int j);
int issorted(int a[], int N);

int main(int argc, char const *argv[])
{
    int i, N;
    N = atoi(argv[1]);
    int a[N];

    readints(a);
    sort(a,  N);
    printf("is sorted: %d\n", issorted(a, N));
}

/* readints: read integers on stdout. */
void readints(int a[])
{
    int i, k, c;
    char n[10];

    i = k = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (i != 0) {
                n[i] = '\0';
                a[k++] = atoi(n);
                i = 0;
            }
        }
        else n[i++] = c;
    }
}

/* issorted: check if a is sorted. */
int issorted(int a[], int N)
{
    int i;

    for (i = 1; i < N; i++)
        if (a[i-1] > a[i])
            return 0;
    return 1;
}

/* sort: sort a with shell sort. */
void sort(int a[], int N)
{
    int h, i, j;

    i = j = 0;
    h = 1;
    while (h < N/3) h = 3*h + 1;
    while (h >= 1) {
        // h-sort the array...
        for (i = h; i < N; i++) {
            for (j = i; j >= h && a[j] < a[j-h]; j -= h)
                exch(a, j, j-h);
        }
        h = h/3;
    }
}

/* exch: swap elements at indexes i and j. */
void exch(int a[], int i, int j)
{
    int temp;

    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
