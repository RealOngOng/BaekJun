#include <bits/stdc++.h>

using namespace std;

int main() {

	int idx = 0;

	while (true) {

		idx++;

		int n0; scanf("%d", &n0);

		if (n0 == 0) break;

		int n1 = 0, n2 = 0, n3 = 0, n4 = 0;

		n1 = 3 * n0;

		if (n1 % 2 == 0) n2 = n1 / 2;
		else n2 = (n1 + 1) / 2;

		n3 = 3 * n2;
		n4 = n3 / 9;

		if (n1 % 2 == 0) n0 = 2 * n4;
		else n0 = 2 * n4 + 1;

		printf("%d. %s %d\n", idx, (n1 % 2 == 0) ? "even" : "odd", n4);

	}

	return 0;

}