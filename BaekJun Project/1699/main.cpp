#include <iostream>
#include <math.h>
#include <algorithm>

#define MAX 100001

int dp[MAX];

int main() {

	int n; std::cin >> n;

	int sqr = std::sqrt(n);

	std::fill(dp, dp + MAX, MAX);

	dp[0] = 0;
	for (int i = 1; i <= sqr; i++) {

		int p = i * i;

		for (int j = p; j < MAX; j++) {

			dp[j] = std::min(dp[j], dp[j - p] + 1);

		}

	}

	std::cout << dp[n] << "\n";

	return 0;
	
}