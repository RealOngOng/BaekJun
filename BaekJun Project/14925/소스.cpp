#include <bits/stdc++.h>

using namespace std;

int n, m;
int cnt;
int field[1002][1002];
int dp[1002][1002];

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> field[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {

			if (field[i][j] != 0) continue;

			dp[i][j] = 1;

			int a = dp[i - 1][j],
				b = dp[i][j - 1],
				c = dp[i - 1][j - 1];

			if (a == b && b == c)
				dp[i][j] = a + 1;
			else
				dp[i][j] = min({a, b, c}) + 1;

		}

	//cout << "\n";

	int ans = 0;
	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= m; j++) {

			ans = max(ans, dp[i][j]);
			//cout << dp[i][j] << " ";

		}

		//cout << "\n";

	}

	cout << ans;

	return 0;

}