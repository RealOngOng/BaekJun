#include <bits/stdc++.h>

using namespace std;

int main() {

	int t; scanf("%d", &t);

	int m = 0;

	while (t--) {

		int a, b, c; scanf("%d %d %d", &a, &b, &c);

		int v = 0;

		if (a == b && b == c) v = 10000 + a * 1000;
		else if (a == b || a == c) v = 1000 + a * 100;
		else if (b == c) v = 1000 + b * 100;
		else v = 100 * max(a, max(b, c));

		m = max(m, v);

	}

	printf("%d", m);

	return 0;

}