#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>

#define MAX 501
#define INF 0x3f3f3f3f

int dp[MAX][MAX];
std::pair<int, int> arr[MAX];

int func(int l, int r) {

	if (dp[l][r] != INF) return dp[l][r];

	if (l == r) return 0;

	if (l + 1 == r) return arr[l].first * arr[l].second * arr[r].second;

	for (int i = l; i < r; i++)
		dp[l][r] = std::min(dp[l][r], 
							func(l, i) + func(i + 1, r) + arr[l].first * arr[i].second * arr[r].second);

	return dp[l][r];

}

int main() {

	memset(dp, INF, sizeof(dp));

	int n; std::cin >> n;

	for (int i = 1; i <= n; i++) std::cin >> arr[i].first >> arr[i].second;

	std::cout << func(1, n) << "\n";

	return 0;

}