
#include <stdio.h>
#include <stdlib.h>  /* for atof() */


#define MAXOP   100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

void result(void);
/* reverse polish calculator */
int main(int argc, char const *argv[])
{
    char type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: / by zero.\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    result();
    return 0;
}

/*****************************************************************************/
#define MAXVAL  100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* stack of operands */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack is full. %g\n", f);
}

/* pop: pop and return top value from stack. */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack is empty.\n");
        return 0.0;
    }
}

/*****************************************************************************/
#include <ctype.h>

int getch(void);
void ungetch(int);

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

/*****************************************************************************/
#define BUFSIZE 100

char buf[BUFSIZE];     /* buffer for ungetch */
int bufp = 0;          /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void)
{ return (bufp > 0)? buf[--bufp]: getchar();    }

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters.\n");
    else
        buf[bufp++] = c;
}

/*****************************************************************************/

void result (void)
{
    int i;

    for (i = 0; i < sp; i++)
        printf("%f\n", val[i]);

}
