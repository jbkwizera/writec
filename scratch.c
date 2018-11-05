#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


#define MAXL  1001              /* max length of my arrays */
#define max(x, y) (x > y? x: y) /* max macro */
void printd(long);

int main(int argc, char const *argv[])
{
    int x;
    x = INT_MIN;
    printd(x);
    printf("\n");

    char s[] = "could";
    char t[] = "would";
    printf("%d\n", max(s, t));
}

void printd(long n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}
