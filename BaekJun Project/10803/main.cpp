#include <iostream>
#include <algorithm>
#include <limits.h>

#define MAX_N 10001
#define MAX_M 101
#define INF 100000000

int dp[MAX_N][MAX_M];

int func(int n, int m) {

	if (n < m) std::swap(n, m);

	if (n < 1 || m < 1) return INF;

	if (n % m == 0) return n / m;

	if (dp[n][m] != INF) return dp[n][m];

	if (n > m * 3) dp[n][m] = std::min(dp[n][m], func(n - m, m) + 1);
	else {

		for (int q = 1; q <= n * 0.5; q++) dp[n][m] = std::min(dp[n][m], func(q, m) + func(n - q, m));
		for (int q = 1; q <= m * 0.5; q++) dp[n][m] = std::min(dp[n][m], func(n ,q) + func(n, m - q));

	}

	return dp[n][m];

}

int main() {

	int a, b; std::cin >> a >> b;

	for (int i = 0; i < MAX_N; i++) std::fill(dp[i], dp[i] + MAX_M, INF);

	std::cout << func(a, b) << "\n";

	return 0;

}