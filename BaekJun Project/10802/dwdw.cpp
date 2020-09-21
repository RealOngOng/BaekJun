#include <iostream>
#include <string>
#include <algorithm>

#define MAX 100001
#define MOD 20150523

//dp[i][j] i길이의 수 중 나머지 j를 가지는 개수
//3, 6, 9가 들어간 숫자는 제외
//dp[i][j] = dp[i - 1][j] + dp[i - 1][(j + 1) % 3] * 3 + dp[i - 1][(j + 2) % 3] * 3
int dp[MAX][3];
//no3[i] i길이의 수 중 3, 6, 9가 포함되지 않는 수의 개수
//no3[i] = no3[i - 1] * 7
int no3[MAX];

int clap(const std::string& num) {

	int n = num.size();

	int sum_front = 0;
	int m3 = -1; //숫자에 3, 6, 9가 포함되지 않은 3의 배수의 개수

	for (int i = 0; i < n; i++) {

		int front = num[i] - '0';

		for (int j = 0; j < front; j++) {

			if (j != 0 && j % 3 == 0) continue;

			int order = (sum_front + j) % 3;
			m3 += dp[n - (i + 1)][(3 - order) % 3];
			m3 %= MOD;

		}

		if (front != 0 && front % 3 == 0) break;
		sum_front = (sum_front + front) % 3;

	}

	int no369 = 0; //3, 6, 9가 포함되지 않은 숫자의 개수

	for (int i = 0; i < n; i++) {

		int front = num[i] - '0';

		for (int j = 0; j < front; j++) {

			if (j != 0 && j % 3 == 0) continue;

			no369 += no3[n - (i + 1)];
			no369 %= MOD;

		}

		if (front != 0 && front % 3 == 0) break;

	}

	int toInt = 0;
	int pow = 1;

	for (int i = n - 1; i >= 0; i--) {

		toInt += (num[i] - '0') * pow;
		toInt %= MOD;
		pow = (pow * 10) % MOD;

	}

	toInt -= no369, toInt %= MOD;

	if (toInt < 0) toInt += MOD;

	return (m3 + toInt) % MOD;

}

bool isClap(const std::string& num) {

	int sum = 0;
	int n = num.size();

	for (int i = 0; i < n; i++) {

		int front = num[i] - '0';
		sum += front;

		if (front != 0 && front % 3 == 0) return true;

	}

	return (sum % 3 == 0);

}

int main() {

	std::string a, b; std::cin >> a >> b;

	dp[0][0] = dp[1][0] = 1;
	dp[1][1] = dp[1][2] = 3;

	no3[0] = 1, no3[1] = 7;

	for (int i = 2; i < MAX; i++) {

		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] * 3 + dp[i - 1][2] * 3) % MOD;
		dp[i][1] = (dp[i - 1][1] + dp[i - 1][0] * 3 + dp[i - 1][2] * 3) % MOD;
		dp[i][2] = (dp[i - 1][2] + dp[i - 1][0] * 3 + dp[i - 1][1] * 3) % MOD;

		no3[i] = (no3[i - 1] * 7) % MOD;

	}

	for (int i = 1; i < 100; i++) {

		std::cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << no3[i] << "\n";

	}

	int result = (clap(b) - clap(a) + isClap(b)) % MOD;

	if (result < 0) result += MOD;

	std::cout << result << "\n";

	return 0;

}