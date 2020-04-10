#include <iostream>
#include <algorithm>

#define MAX 101

int m[MAX], dp[10001];

int main() {

	int n, k; std::cin >> n >> k;

	std::fill(dp, dp + 10001, 10001);

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {

		std::cin >> m[i];

		for (int j = m[i]; j <= k; j++) {

			dp[j] = std::min(dp[j], dp[j - m[i]] + 1);

		}

	}

	if(dp[k] == 10001) std::cout << "-1\n";
	else std::cout << dp[k] << "\n";

	return 0;

}