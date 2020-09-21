#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k; scanf("%d %d", &n, &k);

	int a = n;
	int b = n / 2;

	while (true) {

		a = n - b;

		if (a - b == k) break;

		b--;

	}

	printf("%d %d", a, b);

	return 0;

}