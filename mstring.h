#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAXN  100             /* max length of my arrays */

/*
void sqweeze(char s[], char c);
void sqweezo(char s[], char t[]);
void catstr(char s[], char t[]);
void mcopy(char s[], char t[]);
int anych(char s[], char t[]);
int readline(char s[], int lim);
int lindx(char s[], char t[]);
int rindx(char s[], char t[]);

int main(int argc, char const *argv[])
{
    char c, t[MAXN], s[MAXN];
    int found;

    found = 0;
    strcpy(t, argv[1]);
    while (readline(s, MAXN) > 0) {
        if (lindx(s, t) >= 0) {
            printf("%s\n", s);
            found++;
        }
    }
    return found;
}
*/
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

/* mcopy: copy s to t. */
void mcopy(char s[], char t[])
{
    int i;

    i = 0;
    while ((t[i] = s[i]) != '\0')
        i++;
}

/* lindx: return first occurance of t in s from left. */
int lindx(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/* rindx: return first occurance of t in s from right. */
int rindx(char s[], char t[])
{
    int i, j, k, m, n;

    m = strlen(s);
    n = strlen(t);
    for (i = m-n; i > -1; i--) {
        for (j = i, k = 0; k < n && s[j] == t[k]; j++, k++)
            ;
        if (k == n) return i;
    }
    return -1;
}

/* readline: read line on stdin with max length lim.
 *           return length of the line.
 */
int readline(char s[], int lim)
{
    int i, ch;

    i = 0;
    while (--lim && (ch = getchar()) != EOF && ch != '\n')
        s[i++] = ch;
    s[i] = '\0';
    return i;
}
