#include <iostream>

#define MAX_N 21
#define MAX_M 10001

int coin[MAX_N];
int dp[MAX_M];

int main() {

	int t; std::cin >> t;

	while (t--) {

		int n; std::cin >> n;
		for (int i = 1; i <= n; i++) std::cin >> coin[i];

		std::fill(dp, dp + MAX_M, 0);

		int m; std::cin >> m;

		dp[0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = coin[i]; j <= m; j++)
				dp[j] += dp[j - coin[i]];

		std::cout << dp[m] << "\n";

	}

	return 0;

}