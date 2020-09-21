#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 501
#define INF 0x3f3f3f3f

int dp[MAX][MAX];
int arr[MAX];
int sum[MAX];

int func(int l, int r) {

	if (dp[l][r] != INF) return dp[l][r];

	if (l == r) return dp[l][r] = 0;

	if (l + 1 == r) return dp[l][r] = arr[l] + arr[r];

	for (int i = l; i < r; i++)
		dp[l][r] = std::min(dp[l][r], func(l, i) + func(i + 1, r));

	return dp[l][r] += sum[r] - sum[l - 1];

}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int t; std::cin >> t;

	while (t--) {

		memset(dp, INF, sizeof(dp));

		int n; std::cin >> n;
		for (int i = 1; i <= n; i++) 
			std::cin >> arr[i], sum[i] = sum[i - 1] + arr[i];

		std::cout << func(1, n) << "\n";

	}

	return 0;

}