#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAXN  100             /* max length of my arrays */

void sqweeze(char s[], char c);
void sqweezo(char s[], char t[]);
void catstr(char s[], char t[]);
void mcopy(char s[], char t[]);
int anych(char s[], char t[]);
int matoi(char s[]);

int main(int argc, char const *argv[])
{
    char c, s[MAXN];

    strcpy(s, argv[1]);
    c = getchar();
    sqweeze(s, c);
    printf("%s\n", s);
}

/* sqweeze: remove all c chars in s. */
void sqweeze(char s[], char c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = s[i];
}

/* sqweeze: remove all chars in t from s. */
void sqweezo(char s[], char t[])
{
    int i;

    i = 0;
    while (t[i] != '\0')
        sqweeze(s, t[i++]);
}

/* catstr: add t to s, assuming s is large enough. */
void catstr(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')
        ++i;

    while (t[j] != '\0')
        s[i++] = t[j++];
}

/* anych: check if any char in t is in s. */
int anych(char s[], char t[])
{
    int i, j;

    for (i = 0; t[i] != '\0'; i++)
        for (j = 0; s[j] != '\0'; j++)
            if (s[j] == t[i])
                return j;
    return -1;
}

/* mcopy: copy s to t */
void mcopy(char s[], char t[])
{
    int i;

    i = 0;
    while ((t[i] = s[i]) != '\0')
        i++;
}

/* matoi: changes a string to an int */
int matoi(char s[])
{
    int i, n, sign;

    for (i = 0; s[i] == ' '; i++)
        ;
    sign = (s[i] == '-')? -1: +1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (n = 0; isdigit(s[i]); i++)
        n = n * 10 + (s[i] - '0');
    return sign * n;
}
