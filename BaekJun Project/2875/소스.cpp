#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m, k; scanf("%d %d %d", &n, &m, &k);

	int team = min(n / 2, m);

	int sum = 0;

	if (n > team * 2) sum += n - team * 2, n = team * 2;
	if (m > team) sum += m - team, m = team;

	while (true) {

		if (sum >= k) break;
		if (n < 0 || m < 0) {

			team = 0;
			break;

		}

		n -= 2;
		m -= 1;
		team -= 1;

		sum += 3;

	}

	printf("%d", team);

	return 0;

}