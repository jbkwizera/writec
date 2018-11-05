#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or operand */
int getop(char s[])
{
    int i, c;
    
    /* ?: why not isspace()??? */
    while (isspace(s[0] = c = getch()))
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;                  /* not a number */
    i = 0;
    if (isdigit(c))                /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')                  /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c == EOF) return c;
    ungetch(c);                    /* put c back to input stream */
    return NUMBER;
}
