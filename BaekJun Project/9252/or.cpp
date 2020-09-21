//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//
//#define MAX 1001
//
//int dp[MAX][MAX];
//
//int main() {
//
//	std::string str1, str2; std::cin >> str1 >> str2;
//
//	int t1 = str1.size(), t2 = str2.size();
//
//	std::string result;
//
//	int max = 0;
//
//	for (int i = 1; i <= t1; i++) {
//
//		for (int j = 1; j <= t2; j++) {
//
//			if (str1[i - 1] == str2[j - 1])
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			else
//				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
//
//		}
//
//	}
//
//	for (int i = 1; i <= t1; i++) {
//
//		for (int j = 1; j <= t2; j++) {
//
//			std::cout << dp[i][j] << " ";
//
//		}
//
//		std::cout << "\n";
//
//	}
//
//	int x = t1, y = t2;
//
//	while (x != 0 && y != 0) {
//
//		if (dp[x][y] == dp[x - 1][y]) x--;
//		else if (dp[x][y] == dp[x][y - 1]) y--;
//		else if (dp[x][y] != dp[x - 1][y] && dp[x][y] != dp[x][y - 1]) {
//
//			result += str1[x - 1];
//
//			x--, y--;
//
//		}
//
//	}
//
//	std::reverse(result.begin(), result.end());
//
//	std::cout << dp[t1][t2] << "\n" << result << "\n";
//
//	return 0;
//
//}