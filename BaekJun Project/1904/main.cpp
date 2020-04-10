#include <iostream>

#define MAX 10000001

int dp[MAX];

int main() {

	int n; std::cin >> n;

	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n + 1; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;

	std::cout << dp[n] % 15746 << "\n";

	return 0;
	
}