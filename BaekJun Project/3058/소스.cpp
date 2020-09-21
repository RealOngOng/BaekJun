#include <bits/stdc++.h>

using namespace std;

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		int sum = 0, m = 1e9;

		for (int i = 0; i < 7; i++) {

			int a; scanf("%d", &a);

			if (a % 2 == 0) sum += a, m = min(m, a);

		}

		printf("%d %d\n", sum, m);

	}

	return 0;

}