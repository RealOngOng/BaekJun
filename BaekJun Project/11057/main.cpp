#include <iostream>

#define MOD 10007
#define MAX 1001

long dp[10][MAX];

int main() {

	int n; std::cin >> n;

	for (int i = 0; i < 10; i++) dp[i][1] = 1;

	for (int i = 2; i <= n; i++) {

		for (int j = 0; j < 10; j++)
			for (int w = j; w < 10; w++)
				dp[j][i] += dp[w][i - 1] % MOD;

	}

	long sum = 0;

	for (int i = 0; i < 10; i++)
		sum += dp[i][n] % MOD;

	std::cout << sum % MOD << "\n";;

}