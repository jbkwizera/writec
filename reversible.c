
#include <stdio.h>
#include <stdlib.h>

long revlong(long n);
int allodd(long n);

int main(int argc, char const *argv[])
{
    long n, sum, cnt, LIMIT;

    cnt = sum = 0;
    LIMIT = atoi(argv[1]);
    for (n = 1; n < LIMIT; n++) {
        if (n % 10 == 0) continue;
        sum = n + revlong(n);
        if (allodd(sum))
            cnt++;
    }
    printf("%ld\n", cnt);
    return 0;
}

long revlong(long n)
{
    long res;

    res = 0;
    while (n > 0) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int allodd(long n)
{
    while (n > 0) {
        if (((n % 10) % 2) == 0)
            return 0;
        n /= 10;
    }
    return 1;
}
