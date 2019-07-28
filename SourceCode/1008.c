#include <stdio.h>

int main() {

	int num1, num2;

	scanf("%d %d", &num1, &num2);
	printf("%.15f", (double) num1 / num2);

	return 0;

}