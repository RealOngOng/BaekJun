#include <iostream>
#include <utility>
#include <algorithm>

#define MAX_N 101
#define MAX_K 100001

typedef std::pair<int, int> Vector2;

Vector2 stuff[MAX_N];

int dp[MAX_N][MAX_K];

int main() {

	int n, k;
	std::cin >> n >> k;

	for (int i = 1; i <= n; i++) {

		int a, b; std::cin >> a >> b;
		stuff[i] = { a, b };
		
	}

	std::fill(dp[0], dp[0] + MAX_K, 0);

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= k; j++) {

			dp[i][j] = dp[i - 1][j];

			if (j - stuff[i].first >= 0)
				dp[i][j] = std::max(dp[i - 1][j], stuff[i].second + dp[i - 1][j - stuff[i].first]);

		}

	}

	std::cout << dp[n][k] << "\n";

	return 0;

}