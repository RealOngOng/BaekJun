#include <bits/stdc++.h>

using namespace std;

//n, r
//(n ,r) = (n - 1, r - 1) + (n - 1, r)
int dp[31][31];

int main() {

	int tc; cin >> tc;

	for (int i = 1; i <= 30; i++)
		for (int j = 0; j <= 30; j++) {

			if (i == j || j == 0) {

				dp[i][j] = 1;
				continue;

			}
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

		}


	while (tc--) {

		int n, m; cin >> n >> m;

		cout << dp[m][n] << "\n";

	}

	return 0;

}