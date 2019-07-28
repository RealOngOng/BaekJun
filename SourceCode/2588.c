#include <stdio.h>

int main() {

	int num1, num2;
	scanf("%d\n%d", &num1, &num2);

	int result = num1 * num2;

	while (num2) {

		printf("%d\n", num2 % 10 * num1);
		num2 /= 10;

	}

	printf("%d", result);

	return 0;

}