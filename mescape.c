#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAXN  100000             /* max length of my arrays */

void mescp(char s[], char t[]);
void rescp(char s[]);

int main(int argc, char *argv[])
{
    int c, i;
    char s[MAXN+1], t[MAXN+1];

    i = 0;
    while (i < MAXN && (c = getchar()) != EOF)
        s[i++] = c;
    s[i] = '\0';

    mescp(s, t);
    printf("%s\n", s);
    printf("%s\n", t);

    rescp(t);
    printf("%s\n", t);
    return 0;
}

/* mescp: replaces esc chars with visible chars */
void mescp(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while ((t[i] = s[j]) != '\0') {
        if (s[j] == '\n' || s[j] == '\t' || s[j] == ' ') {
            t[i++] = '\\';
            if      (s[j] == '\n') t[i] = 'n';
            else if (s[j] == '\t') t[i] = 't';
            else if (s[j] ==  ' ') t[i] = 'b';
        }
        i++;
        j++;
    }
}

/* rescp: replaces visible chars with real esc chars. */
void rescp(char s[])
{
    int i, j;

    i = j = 0;
    while (s[j] != '\0') {
        if (s[j] == '\\') {
            if      (s[j+1] == 'b') s[i++] =  ' ';
            else if (s[j+1] == 't') s[i++] = '\t';
            else if (s[j+1] == 'n') s[i++] = '\n';
            j++;
        }
        else if (s[j-1] != '\\')
            s[i++] = s[j];
        j++;
    }
    s[i] = '\0';
}
