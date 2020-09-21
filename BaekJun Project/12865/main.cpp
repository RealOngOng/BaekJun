//#include <iostream>
//#include <utility>
//#include <algorithm>
//
//#define MAX_N 101
//#define MAX_K 100001
//
//typedef std::pair<int, int> Vector2;
//
//Vector2 stuff[MAX_N];
//
//int dp[MAX_K];
//
//int main() {
//
//	int n, k;
//	std::cin >> n >> k;
//
//	for (int i = 1; i <= n; i++) {
//
//		int a, b; std::cin >> a >> b;
//		stuff[i] = { a, b };
//		
//	}
//
//	for (int i = 1; i <= n; i++) {
//
//		int w = stuff[i].first, v = stuff[i].second;
//
//		for (int j = k; j >= w; j--)
//			dp[j] = std::max(dp[j], dp[j - w] + v);
//
//	}
//
//	std::cout << dp[k] << "\n";
//
//	return 0;
//
//}