#include <string.h>
#include <stdio.h>

#define MAXN  1000

void reverse(char s[]);
void readall(char s[]);
void exch(char s[], int i, int j);

int main(void) {
    char s[MAXN+1];

    readall(s);
    printf("%s\n", s);

    reverse(s);
    printf("%s\n", s);
    return 0;
}
/* readall: read everything on stdout. */
void readall(char s[])
{
    int i, c;

    i = 0;
    while ((c = getchar()) != EOF)
        s[i++] = c;
    s[i] = '\0';
}
/* reverse: reverse string s in-place. */
void reverse(char s[]) {
    int i, j, N, ch;

    N = strlen(s);
    for (i = 0; i < N/2; i++)
        exch(s, i, N-i-1);

}
/* exch: swaps chars at indexes i and j. */
void exch(char s[], int i, int j)
{
    char temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}
