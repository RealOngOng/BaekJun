#include <bits/stdc++.h>

using namespace std;

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		int a, b; scanf("%d %d", &a, &b);

		int x = a - b, y = 2 * b - a;

		printf("%d %d\n", y, x);

	}

	return 0;

}