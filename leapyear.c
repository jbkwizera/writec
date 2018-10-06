#include <stdio.h>
#include <stdlib.h>

int isleapyear(int y);

int main(int argc, char *argv[]) {
    int y;

    y = atoi(argv[1]);
    if (isleapyear(y)) printf("%d is leap year\n", y);
    else               printf("%d is not leap year\n", y);
	return 0;
}
int isleapyear(int y) {
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		return 1;
	return 0;
}
