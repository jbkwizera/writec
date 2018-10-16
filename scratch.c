#include <stdlib.h>
#include <stdio.h>

#define MAXL  1001             /* max length of my arrays */

int nexttoken(char s[]);

int main(int argc, char const *argv[])
{
    char c, s[MAXL];

    while ((c = nexttoken(s)) != EOF) {
        printf("%9s: %d\n", s, c);
    }
    return 0;
}



#include <ctype.h>

int nexttoken(char s[])
{
    int i, c;

    while ((c = getchar()) != EOF && isspace(c))
        ;
    if (c == EOF) return c;

    i = 0;
    s[i++] = c;
    while ((c = getchar()) != EOF && !isspace(c))
        s[i++] = c;
    s[i] = '\0';

    if (c == EOF) return c;
    return i;
}
