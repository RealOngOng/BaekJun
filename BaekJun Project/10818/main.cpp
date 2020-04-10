#include <iostream>
#include <limits.h>

int main() {

	int n, input, min = INT_MAX, max = -INT_MAX;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%d", &input);

		if (input > max) max = input;
		if (input < min) min = input;

	}

	printf("%d %d", min, max);

	return 0;

}