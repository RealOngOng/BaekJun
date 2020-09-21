#include <iostream>

#define MAX 31

int dp[MAX];

int main() {

	int n; std::cin >> n;

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= n; i ++) {

		int sum = 0;

		for (int j = 2; j <= i; j += 2) {

			sum += dp[i - j] * ((j == 2) ? 3 : 2);

		}

		dp[i] += sum;

	}
		
	std::cout << dp[n] << "\n";

	return 0;

}