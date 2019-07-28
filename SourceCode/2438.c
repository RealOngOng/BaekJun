#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	for (int line = 0; line < n; line++) {

		for (int i = 0; i <= line; i++)
			printf("*");

		printf("\n");

	}

	return 0;

}