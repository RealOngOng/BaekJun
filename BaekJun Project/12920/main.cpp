//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//#define MAX 10001
//
//typedef struct Stuff {
//
//	int weight, value;
//
//};
//
//std::vector<Stuff> stuff;
//
//int dp[MAX];
//
//int main() {
//
//	int n, m; std::cin >> n >> m;
//
//	for (int i = 0; i < n; i++) {
//
//		int v, c, k; std::cin >> v >> c >> k;
//
//		for (int j = k; j > 0; j >>= 1) {
//
//			int num = j - (j >> 1);
//			stuff.push_back({ v * num, c * num });
//
//		}
//
//	}
//
//	for (int i = 0; i < stuff.size(); i++) {
//
//		int w = stuff[i].weight, v = stuff[i].value;
//
//		for (int j = m; j >= w; j--)
//			dp[j] = std::max(dp[j], dp[j - w] + v);
//
//	}
//
//	std::cout << dp[m] << "\n";
//
//	return 0;
//
//}