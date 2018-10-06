#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAXN  100000             /* max length of my arrays */

int matoi(char s[]);

int main(int argc, char *argv[])
{
    int res;
    char s[MAXN+1];
    strcpy(s, argv[1]);


    res = matoi(s);
    printf("%d\n", res);
    return 0;
}
