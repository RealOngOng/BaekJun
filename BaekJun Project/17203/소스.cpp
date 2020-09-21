#include <bits/stdc++.h> 

using namespace std;

int main() {

	int n, m; scanf("%d %d", &n, &m);
	vector<int> arr(n + 1), sub(n + 1), dp(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]),
		sub[i] = (i == 1) ? 0 : abs(arr[i] - arr[i - 1]),
		dp[i] = dp[i - 1] + sub[i];

	while (m--) {

		int a, b; scanf("%d %d", &a, &b);

		if (b - 1 < a) printf("0\n");
		else printf("%d\n", dp[b] - dp[a]);

	}

	return 0;

}