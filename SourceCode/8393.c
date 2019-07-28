#include <stdio.h>

int main() {

	int n, result = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		result += i + 1;

	printf("%d", result);

	return 0;

}