#include <bits/stdc++.h>

using namespace std;

int dp[101][101][2];

int main() {

	dp[1][0][1] = 1;
	dp[1][0][0] = 1;

	for (int k = 0; k < 100; k++) {

		for (int n = 1; n <= 100; n++) {

			if (k == 0)
				dp[n][k][1] += dp[n - 1][k][0];
			else
				dp[n][k][1] += dp[n - 1][k][0] + dp[n - 1][k - 1][1];

			dp[n][k][0] += dp[n - 1][k][1] + dp[n - 1][k][0];


		}

	}

	int tc; cin >> tc;

	while (tc--) {

		int n, k; cin >> n >> k;

		cout << dp[n][k][0] + dp[n][k][1] << "\n";

	}

	return 0;

}