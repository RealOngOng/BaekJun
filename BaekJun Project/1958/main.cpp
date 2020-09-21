#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define MAX 102

int dp[MAX][MAX][MAX];

int main() {

	std::string str1, str2, str3; std::cin >> str1 >> str2 >> str3;

	int t1 = str1.length(), t2 = str2.length(), t3 = str3.length();

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			std::fill(dp[i][j], dp[i][j] + MAX, 0);

	for (int i = 1; i <= t1; i++) {

		for (int j = 1; j <= t2; j++) {

			for (int k = 1; k <= t3; k++) {

				if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
					dp[i][j][k] = std::max(dp[i - 1][j][k], std::max(dp[i][j - 1][k], dp[i][j][k - 1]));

			}

		}

	}

	std::cout << dp[t1][t2][t3] << "\n";

	return 0;

}