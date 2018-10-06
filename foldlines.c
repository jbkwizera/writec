#include <stdio.h>

#define N     10

int readline(void);

int main(void) {
    int c;

    while ((c = readline()) != EOF)
        ;
    return 0;
}
int readline() {
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        putchar(c);
        ++i;
        if (i == N) {
            i = 0;
            putchar('\n');
            while ((c = getchar()) == ' ' || c == '\t')
                ;
            if (c != ' ' && c != '\t') {
                putchar(c);
                ++i;
            }
        }
    }
    if (c != EOF) putchar('\n');
    return c;
}
