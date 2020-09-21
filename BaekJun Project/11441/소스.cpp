#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; scanf("%d", &n);
	vector<int> arr(n + 1), dp(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]), dp[i] = dp[i - 1] + arr[i];

	int m; scanf("%d", &m);
	while (m--) {

		int a, b; scanf("%d %d", &a, &b);

		printf("%d\n", dp[b] - dp[a - 1]);

	}

	return 0;

}