#include <iostream>
#include <algorithm>

#define MOD 1000000000
#define MAX 101

long dp[10][MAX];

int main() {

	int n; std::cin >> n;

	for (int i = 0; i <= 9; i++) dp[i][1] = 1;

	for (int i = 2; i <= n; i++) {

		for (int j = 0; j <= 9; j++) {

			if (j == 0) dp[j][i] = dp[j + 1][i - 1] % MOD;
			else if (j == 9) dp[j][i] = dp[j - 1][i - 1] % MOD;
			else dp[j][i] = (dp[j + 1][i - 1] + dp[j - 1][i - 1]) % MOD;

		}

	}

	long sum = 0;
	for (int i = 1; i <= 9; i++)
		sum += dp[i][n] % MOD;

	std::cout << sum % MOD << "\n";

	return 0;

}