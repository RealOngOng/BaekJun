#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	for (int line = 0; line < n; line++) {

		for (int i = 0; i < n; i++) {

			if (n - line > i + 1)
				printf(" ");
			else
				printf("*");

		}

		printf("\n");

	}

	return 0;
	
}