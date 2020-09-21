#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//위치가 i에서의 경우의수, 현재숫자가 j,
ll dp[65][10];

int n;

int main() {

	int tc; cin >> tc;

	while (tc--) {

		cin >> n;
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i <= 9; i++)
			dp[1][i] = 1;

		for (int i = 2; i <= n; i++) {

			for (int j = 0; j <= 9; j++) {

				for (int k = 0; k <= j ; k++)
					dp[i][j] += dp[i - 1][k];
					
			}

		}

		ll ans = 0;

		for (int i = 0; i <= 9; i++)
			ans += dp[n][i];

		cout << ans << "\n";

	}

	return 0;

}