#include <bits/stdc++.h>

using namespace std;

int main() {

	while (true) {

		int a; scanf("%d", &a);

		if (!a) break;

		int s = 1;

		for (int i = 0; i < a; i++) {

			int n, m; scanf("%d %d", &n, &m);

			s *= n; s -= m;

		}

		printf("%d\n", s);

	}

	return 0;

}