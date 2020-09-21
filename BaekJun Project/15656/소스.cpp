#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[8], lt[8];

void solve(int pos) {

	if (pos == m) {

		for (int i = 0; i < m; i++) printf("%d ", arr[i]);

		printf("\n");

		return;

	}

	for (int i = 0; i < n; i++) {

		arr[pos] = lt[i];
		solve(pos + 1);

	}
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) scanf("%d", lt + i);

	sort(lt, lt + n);

	solve(0);

	return 0;

}