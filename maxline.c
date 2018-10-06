#include <stdio.h>
#define MAXLINE   1000   /* maximum input line size */

int readline(char line[], int lim);
void copy(char to[],  char from[]);

int main(void) {
    int len;
    int max;
    char line[MAXLINE+1];    /* add 1 for '\0' */
    char longest[MAXLINE+1];

    max = 0;
    while ((len = readline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    if (max > 0)
        printf("%s\n", longest);
    return 0;
}

/* readline: read a line into s, return length */
int readline(char[] s, int N) {
    int c, i;

    i = 0;
    while (i < N && ((c = getchar()) != EOF) && c != '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0'; /* terminate string */
    return i;
}

/*copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
