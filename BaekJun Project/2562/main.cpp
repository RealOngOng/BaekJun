#include <iostream>

#define MAX 9

int main() {

	int temp, max = 0, j=0;

	for (int i = 0; i < MAX; i++) {

		scanf("%d", &temp);

		if (max < temp) {

			max = temp;
			j = i;

		}

	}

	printf("%d\n%d", max, j+1);

	return 0;

}