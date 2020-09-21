#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[8], lt[8];

set<string> visit;

void solve(int pos, int prev) {

	if (pos == m) {

		string str;

		for (int i = 0; i < m; i++) str += arr[i] + '0';

		if (visit.find(str) != visit.end()) return;

		for (int i = 0; i < m; i++) printf("%d ", arr[i]);

		printf("\n");

		visit.insert(str);

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