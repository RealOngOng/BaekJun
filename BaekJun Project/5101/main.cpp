#include <bits/stdc++.h>

using namespace std;

int main() {

	while (true) {

		int a, b, c; scanf("%d %d %d", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0) break;

		int idx = 1;

		while (true) {

			if (a == c) break;
			if (a > c) {

				idx = -1;
				break;

			}

			a += b;
			idx++;

		}

		if (idx == -1) printf("X\n");
		else printf("%d\n", idx);

	}

	return 0;

}