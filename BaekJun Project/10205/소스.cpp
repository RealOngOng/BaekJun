#include <bits/stdc++.h>

using namespace std;

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		int h, w, n; scanf("%d %d %d", &h, &w, &n);

		int t = n % h;

		if (t == 0) t = h;

		printf("%d%02d\n", t, (int)ceil((double)n / h));

	}

	return 0;

}