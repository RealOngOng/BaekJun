#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[8], lt[8];

void solve(int pos, int prev) {

	if (pos == m) {

		for (int i = 0; i < m; i++) printf("%d ", arr[i]);

		printf("\n");

		return;

	}

	for (int i = 0; i < n; i++) {

		if (prev > lt[i]) continue;

		arr[pos] = lt[i];
		solve(pos + 1, lt[i]);

	}
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) scanf("%d", lt + i);

	sort(lt, lt + n);

	solve(0, 0);

	return 0;

}