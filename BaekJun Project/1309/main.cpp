//#include <iostream>
//
//#define MAX 100001
//#define MOD 9901
//
//int dp[MAX];
//
//int main() {
//
//	int n; std::cin >> n;
//
//	int result = 0;
//
//	dp[0] = 1, dp[1] = 3;
//
//	for (int i = 2; i <= n; i++) dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % MOD;
//
//	std::cout << dp[n] << "\n";
//
//	return 0;
//
//}