#include <stdio.h>

int main() {

	int year, result = 0;
	scanf("%d", &year);
	
	if (year % 4 == 0) result = 1;

	if (year % 100 == 0) {
		result = 0;
		if (year % 400 == 0)
			result = 1;
	}

	printf("%d", result);

	return 0;

}