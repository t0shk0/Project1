#include <stdio.h>

int main() {
	unsigned int a = 102;
	unsigned int b = 57;

	printf("%d\n", a & !b);

	return 0;
}