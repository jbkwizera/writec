#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void tohex(char c, char s[]);
int main(int argc, char const *argv[])
{
    /*
    int ch, ls, val, i, nonascii,
        counts[256], cnt, tot;
    char s[3];

    for (i = 0; i < 256; i++)
        counts[i] = 0;

    tot = 0;
    while ((ch = getchar()) != EOF) {
        val = ch - '0' + 48;
        if (val < 256) {
            tot++;
            counts[val]++;
        }
        else nonascii++;
        ls = ch;
    }
    tohex(ls, s);
    printf("total: %d\n", tot);
    printf("last: %s\n", s);

    cnt = 0;
    for (i = 0; i < 128; i++)
        cnt += counts[i];

    printf("non-space control: %d\n", cnt);
    cnt = counts[32];
    for (i = 9; i < 14; i++)
        cnt += counts[i];
    printf("whitespace: %d\n", cnt);
    if (counts[9]  > 0) printf("  09 %d\n", counts[9]);
    if (counts[10] > 0) printf("  0A %d\n", counts[10]);
    if (counts[11] > 0) printf("  0B %d\n", counts[11]);
    if (counts[12] > 0) printf("  0C %d\n", counts[12]);
    if (counts[13] > 0) printf("  0D %d\n", counts[13]);
    if (counts[32] > 0) printf("  20 %d\n", counts[32]);

    cnt = 0;
    for (i = 33; i < 127; i++)
        cnt += counts[i];

    printf("non-space printable: %d\n", cnt);
    printf("non-ascii: %d\n", nonascii);

    return 0;
}
*/
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
