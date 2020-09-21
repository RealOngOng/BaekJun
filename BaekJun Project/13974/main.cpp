//#include <bits/stdc++.h>
//
//#define MAX 5001
//#define INF 0x3f3f3f3f
//
//int dp[MAX][MAX], K[MAX][MAX];
//int arr[MAX];
//int sum[MAX];
//
//int solve(int n) {
//
//	for (int m = 2; m <= n; m++) {
//
//		for (int i = 0; m + i <= n; i++) {
//
//			int j = i + m;
//			for (int k = K[i][j - 1]; k <= K[i + 1][j]; k++) {
//
//				int now = dp[i][k] + dp[k][j] + sum[j] - sum[i];
//				if (dp[i][j] > now)
//					dp[i][j] = now, K[i][j] = k;
//
//			}
//
//		}
//
//	}
//
//	return dp[0][n];
//
//}
//
//int main() {
//
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(NULL); std::cout.tie(NULL);
//
//	int t; std::cin >> t;
//
//	while (t--) {
//
//		int n; std::cin >> n;
//
//		memset(dp, INF, sizeof(dp));
//
//		for (int i = 1; i <= n; i++)
//			std::cin >> arr[i], sum[i] = sum[i - 1] + arr[i], K[i - 1][i] = i, dp[i - 1][i] = 0;
//
//		std::cout << solve(n) << "\n";
//
//	}
//
//	return 0;
//
//}