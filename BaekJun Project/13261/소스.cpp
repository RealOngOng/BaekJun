//#include <bits/stdc++.h>
//
//using namespace std;
//
////j번째까지 봤을 때, i명의 간수를 사용함
//int dp[801][8001];
//int arr[8001], sum[8001];
//
//int n, m;
//
//int cost(int a, int b) { return (sum[b] - sum[a - 1]) * (b - a + 1); }
//
//int solve(int cnt, int pos) {
//
//	if (pos == n + 1) return 0;
//	if (cnt == 0) return 0x3f3f3f3f;
//
//	int &ret = dp[cnt][pos];
//	if (ret != 0x3f3f3f3f) return ret;
//
//	//dnc
//	for (int i = 1; pos + i <= n + 1; i++)
//		ret = min(ret, solve(cnt - 1, pos + i) + cost(pos, pos + i - 1));
//
//	return ret;
//
//}
//
//int main() {
//
//	memset(dp, 0x3f3f3f3f, sizeof(dp));
//
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//		sum[i] = sum[i - 1] + arr[i];
//	}
//
//	cout << solve(m, 1);
//
//	return 0;
//
//}