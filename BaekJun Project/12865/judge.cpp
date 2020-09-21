//#include <iostream>
//#include <utility>
//#include <algorithm>
//#include <fstream>
//#include <ctime>
//#include <stdlib.h>
//#include <string>
//
//#define MAX_N 101
//#define MAX_K 100001
//
//typedef std::pair<int, int> Vector2;
//
//Vector2 stuff[MAX_N];
//
//int dp[MAX_N][MAX_K];
//
//int main() {
//
//	std::ofstream inFile, outFile;
//	
//	inFile.open("input.in"), outFile.open("output.out");
//
//	srand(time(NULL));
//
//	int n = (rand() % 100) + 1, k = (rand() % 100000) + 1;
//
//	std::string str_n = std::to_string(n),
//				str_k = std::to_string(k);
//
//	inFile.write(str_n.c_str(), str_n.length());
//	inFile.write(" ", 1);
//	inFile.write(str_k.c_str(), str_k.length());
//	inFile.write("\n", 1);
//
//	//std::cin >> n >> k;
//
//	for (int i = 1; i <= n; i++) {
//
//		int a = (rand() % 100000) + 1 , b = (rand() % 1000); //std::cin >> a >> b;
//
//		std::string str_a = std::to_string(a),
//			str_b = std::to_string(b);
//
//		inFile.write(str_a.c_str(), str_a.length());
//		inFile.write(" ", 1);
//		inFile.write(str_b.c_str(), str_b.length());
//		inFile.write("\n", 1);
//
//		stuff[i] = { a, b };
//
//	}
//
//	std::fill(dp[0], dp[0] + MAX_K, 0);
//
//	for (int i = 1; i <= n; i++) {
//
//		for (int j = 1; j <= k; j++) {
//
//			dp[i][j] = dp[i - 1][j];
//
//			if (j - stuff[i].first >= 0)
//				dp[i][j] = std::max(dp[i - 1][j], stuff[i].second + dp[i - 1][j - stuff[i].first]);
//
//		}
//
//	}
//
//	std::cout << dp[n][k] << "\n";
//
//	std::string str_dp = std::to_string(dp[n][k]);
//
//	outFile.write(str_dp.c_str(), str_dp.length());
//
//	inFile.close(), outFile.close();
//
//	return 0;
//
//}