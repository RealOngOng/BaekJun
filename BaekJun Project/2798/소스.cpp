#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;

int arr[101];

void backtrack(int pos, int count, int sum) {

	if (sum > m) return;

	if (count == 3) {

		if (sum <= m) cnt = max(cnt, sum);

		return;

	}

	for (int i = pos + 1; i < n; i++) {

		if (sum + arr[i] > m) continue;

		backtrack(i, count + 1, sum + arr[i]);

	}

}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	backtrack(0, 0, 0);

	printf("%d", cnt);

	return 0;

}