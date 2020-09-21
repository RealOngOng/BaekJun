#include <bits/stdc++.h>

using namespace std;

int main() {

	int t = 10;

	int m = 0;
	int p = 0;

	while (t--) {

		int a, b; scanf("%d %d", &a, &b);

		m = max(m, p);
		p -= a, p += b;

	}

	printf("%d", m);

	return 0;

}