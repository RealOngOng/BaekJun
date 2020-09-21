#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[10];

void solve(int pos, int prev) {

	if (pos == m) {

		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);

		printf("\n");

		return;

	}

	for (int i = 1; i <= n; i++) {

		if (prev > i) continue;

		arr[pos] = i;
		solve(pos + 1, i);

	}

}

int main() {

	scanf("%d %d", &n, &m);

	solve(0, 0);

	return 0;

}