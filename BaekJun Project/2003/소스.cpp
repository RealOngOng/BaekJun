#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m; scanf("%d %d", &n, &m);

	int ans = 0;

	vector<int> arr(n + 1), dp(n + 1);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]), dp[i] = dp[i - 1] + arr[i];

	int lo = 1, hi = 1;

	while (lo <= n) {

		int v = dp[hi] - dp[lo - 1];

		if (v == m) ans++;

		if (hi == n) lo++;
		else {

			if (v >= m) lo++;
			else hi++;

		}

	}

	printf("%d\n", ans);

	return 0;

}