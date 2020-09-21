#include <bits/stdc++.h>

using namespace std;

int main() {

	int a, b; scanf("%d %d", &a, &b);

	int x = (a + b) / 2, y = (a - b) / 2;

	if (x < 0 || y < 0 || (a + b) % 2 == 1 || (a - b) % 2 == 1) {

		printf("-1\n");
		return 0;

	}

	if (x < y) swap(x, y);

	printf("%d %d\n", x, y);

	return 0;

}