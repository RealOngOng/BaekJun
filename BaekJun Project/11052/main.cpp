#include <iostream>
#include <algorithm>

#define MAX 1001

int cost[MAX];
int dp[MAX];

int main() {

	int n; std::cin >> n;
	for (int i = 1; i <= n; i++) std::cin >> cost[i];

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= i; j++)
			dp[i] = std::max(dp[i], dp[i - j] + cost[j]);

	}

	std::cout << dp[n] << "\n";

	return 0;

}