#include <bits/stdc++.h>

using namespace std;

int main() {

	int k, n; scanf("%d %d", &k, &n);

	int half = (k + 1) / 2;

	while (n--) {

		int a, b; scanf("%d %d", &a, &b);

		if (a == b) printf("1\n");
		else if (a > b) {

			int w = k - a;

			printf("%d\n", ((a - b) - w <= 2));

		}
		else {

			int w = k - b;

			printf("%d\n", ((b - a) - w <= 1));

		}

	}

}