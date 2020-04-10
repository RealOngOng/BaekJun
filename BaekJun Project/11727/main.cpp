#include <iostream>

#define MAX 1001

int dp[MAX];

int main() {

	int n; std::cin >> n;

	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n + 1; i++)
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;

	std::cout << dp[n] % 10007 << "\n";

	return 0;

}