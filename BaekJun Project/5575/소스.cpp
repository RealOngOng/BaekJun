#include <bits/stdc++.h>

using namespace std;

int main() {

	int i = 3;

	while (i--) {

		int a, b, c, d, e, f; scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

		int t1 = a * 3600 + b * 60 + c,
			t2 = d * 3600 + e * 60 + f;

		t2 -= t1;

		int h = t2 / 3600,
			m = (t2 % 3600) / 60,
			s = t2 % 60;

		printf("%d %d %d\n", h ,m, s);

	}

	return 0;

}