//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, w;
//int arr[2][10010];
////Ã¹¹øÂ° ÁÙÀ» i¹øÂ°±îÁö º¸¾Ò°í, µÎ¹øÂ° ÁÙÀ» j¹øÂ°±îÁö º¸¾Ò´Ù
//int dp[10010][10010];
//
//int solve(int x, int y)
//{
//	if (x >= n && y >= n) return 0;
//
//	int &ret = dp[x][y];
//	if (ret != 0x3f3f3f3f) return ret;
//
//	//ÇÑÄ­ ¸Ô±â
//	if (x < n)
//		ret = min(ret, solve(x + 1, y) + 1);
//	if (y < n)
//		ret = min(ret, solve(x, y + 1) + 1);
//
//	//À­Ä­ °¡·Î µÎÄ­ ¸Ô±â
//	if (x < n && arr[0][x] + arr[0][x + 1] <= w)
//		ret = min(ret, solve(x + 2, y) + 1);
//
//	//¾Æ·¡Ä­ °¡·Î µÎÄ­ ¸Ô±â
//	if (y < n && arr[1][y] + arr[1][y + 1] <= w)
//		ret = min(ret, solve(x, y + 2) + 1);
//
//	//¼¼·Î µÎÄ­ ¸Ô±â
//	if (x == y && arr[0][x] + arr[1][y] <= w)
//		ret = min(ret, solve(x + 1, y + 1) + 1);
//
//	return ret;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//
//	int tc; cin >> tc;
//	while (tc--)
//	{
//		cin >> n >> w;
//		for (int i = 1; i <= n; i++) cin >> arr[0][i];
//		arr[0][0] = arr[0][n];
//		for (int i = 1; i <= n; i++) cin >> arr[1][i];
//		arr[1][0] = arr[1][n];
//
//		int ans = 0x3f3f3f3f;
//
//		memset(dp, 0x3f3f3f3f, sizeof(dp));
//		ans = min(ans, solve(0, 0));
//
//		n++;
//		memset(dp, 0x3f3f3f3f, sizeof(dp));
//		ans = min(ans, solve(1, 1));
//
//		cout << ans << "\n";
//	}
//
//	return 0;
//}