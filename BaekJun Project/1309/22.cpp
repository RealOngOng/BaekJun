#include <iostream>

#define MAX 100001
#define MOD 9901

//0 ���ʿ� ���ڰ� ���� ���
//1 ���ʿ� ���ڰ� �ִ� ���
//2 �����ʿ� ���ڰ� �ִ� ���
int dp[3][MAX];

int main() {

	int n; std::cin >> n;

	dp[0][0] = dp[1][0] = dp[2][0] = 1;

	for (int i = 1; i < n; i++) {

		dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % MOD;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % MOD;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;

	}

	std::cout << (dp[0][n - 1] + dp[1][n - 1] + dp[2][n - 1]) % MOD << '\n';

	return 0;
	
}