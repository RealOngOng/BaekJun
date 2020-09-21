//#include <bits/stdc++.h>
//
//using namespace std;
//
////i, j까지 가는 경우의수
//int dp[21][21];
//
//int main() {
//
//	int n, m, k; cin >> n >> m >> k;
//
//	for (int i = 1; i <= 20; i++)
//		dp[i][1] = 1, dp[1][i] = 1;
//
//	for (int i = 2; i <= 20; i++)
//		for (int j = 2; j <= 20; j++)
//			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//
//	int x = 0, y = 0;
//	int cnt = 1;
//
//	for(int i=1; i <= n; i++)
//		for (int j = 1; j <= m; j++) {
//
//			if (cnt == k)
//				x = i, y = j;
//
//			cnt++;
//
//		}
//
//	if (k == 0)
//		cout << dp[n][m];
//	else 
//		cout << dp[x][y] * dp[n - x + 1][m - y + 1];
//
//	return 0;
//
//}