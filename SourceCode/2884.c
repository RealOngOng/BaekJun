#include <stdio.h>

int main() {

	int h, m;
	scanf("%d %d", &h, &m);

	m -= 45;

	if (m < 0) {

		h--;
		m = 60 + m;

	}

	if (h < 0) h = 24 + h;

	printf("%d %d", h, m);

	return 0;

}