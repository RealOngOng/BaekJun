#include <iostream>
#include <algorithm>
#include <string>

#define MAX 1001

int dp[MAX][MAX];

int main() {

	std::string str1, str2; std::cin >> str1 >> str2;

	int t1 = str1.size(), t2 = str2.size();

	for (int i = 1; i <= t1; i++) {

		for (int j = 1; j <= t2; j++) {

			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);

		}

	}

	std::cout << dp[t1][t2];

	return 0;

}