#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void tohex(char c, char s[]);
int main(int argc, char const *argv[])
{
    int ws, nsp, nsc, ncc, del, bs,
        tb, vt, nl, ff, cr, cnt;
    char ch, ls, s[3];

    ch = ws = nsp = nsc = ncc = del =
    bs = tb = vt  = nl  = ff  = cnt = cr = 0;

    while ((ch = getchar()) != EOF) {
        if (iscntrl(ch) && !isspace(ch)) nsc++;
        if (isspace(ch)) {
            ws++;
            if (ch == '\t') tb++;
            if (ch == '\n') nl++;
            if (ch == '\v') vt++;
            if (ch == '\f') ff++;
            if (ch == '\r') cr++;
            if (ch ==  ' ') bs++;
        }
        if (isprint(ch) && !isspace(ch)) nsp++;
        if ((ch-'0') > 127 && (ch-'0') < 256) ncc++;
        ls = ch;
        cnt++;
    }
    printf("total: %d\n", cnt);
    tohex(ls, s);
    printf("last: %s\n", s);
    printf("non-space control: %d\n", nsc);
    printf("whitespace: %d\n", ws);
    if (ws > 0) {
        if (tb > 0) printf("  09 %d\n", tb);
        if (nl > 0) printf("  0A %d\n", nl);
        if (vt > 0) printf("  0B %d\n", vt);
        if (ff > 0) printf("  0C %d\n", ff);
        if (cr > 0) printf("  0D %d\n", cr);
        if (bs > 0) printf("  20 %d\n", bs);
    }
    printf("non-space printable: %d\n", nsp);
    printf("non-ascii: %d\n", ncc);
    return 0;
}
void tohex(char c, char s[])
{
    int v0, v1, v;

    v = c - '0' + 48;
    v0 = v % 16;
    v1 = v / 16 % 16;
    s[1] = (v0 < 10)? v0 + '0': 'A' + v0 % 10;
    s[0] = (v1 < 10)? v1 + '0': 'A' + v0 % 10;
    s[2] = '\0';
}
