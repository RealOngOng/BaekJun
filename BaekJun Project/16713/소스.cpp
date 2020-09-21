#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {

		int a; cin >> a;
		dp[i] = dp[i - 1] ^ a;

	}

	int ans = 0;

	while (m--) {

		int a, b; cin >> a >> b;

		ans = ans ^ (dp[b] ^ dp[a - 1]);

	}

	cout << ans;

	return 0;

}