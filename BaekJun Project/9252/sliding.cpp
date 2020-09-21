//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//#define MAX 1001
//
//int dp[2][MAX];
//std::string lcs[2][MAX];
//
//int main() {
//
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(NULL), std::cout.tie(NULL);
//
//	std::string str1, str2;
//
//	std::cin >> str1 >> str2;
//
//	int t1 = str1.length(), t2 = str2.length();
//
//	for (int i = 1; i <= t1; i++) {
//
//		for (int j = 1; j <= t2; j++) {
//
//			if (str1[i - 1] == str2[j - 1])
//				lcs[i % 2][j] = lcs[(i - 1) % 2][j - 1] + str1[i - 1];
//			else {
//
//				if (lcs[(i - 1) % 2][j].length() > lcs[i % 2][j - 1].length())
//					lcs[i % 2][j] = lcs[(i - 1) % 2][j];
//				else
//					lcs[i % 2][j] = lcs[i % 2][j - 1];
//
//			}
//
//		}
//
//	}
//
//	std::cout << lcs[t1 % 2][t2].length() << "\n" << lcs[t1 % 2][t2] << "\n";
//
//	return 0;
//
//}