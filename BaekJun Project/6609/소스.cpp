#include <bits/stdc++.h>

using namespace std;

int main() {

	int m, p, l, e, r, s, n;

	while (scanf("%d %d %d %d %d %d %d", &m, &p, &l, &e, &r, &s, &n) != EOF) {

		for (int i = 0; i < n; i++) {

			int tm = 0, tp = 0, tl = 0;

			tm = p / s, tp = l / r, tl = m * e;

			m = tm, p = tp, l = tl;

		}

		printf("%d\n", m);

	}

	return 0;

}