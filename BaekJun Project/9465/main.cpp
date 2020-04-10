#include <iostream>
#include <algorithm>

#define MAX 100001

int main() {

	int t; std::cin >> t;

	while (t--) {

		int n; std::cin >> n;

		int field[2][MAX], dp[MAX][3] = {0};

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				std::cin >> field[i][j];

		for (int i = 0; i < n; i++) {

			dp[i + 1][0] = std::max(dp[i + 1][0], std::max(dp[i][0], std::max(dp[i][1], dp[i][2])));
			dp[i + 1][1] = std::max(dp[i + 1][1], std::max(dp[i][0], dp[i][2]) + field[0][i]);
			dp[i + 1][2] = std::max(dp[i + 1][2], std::max(dp[i][0], dp[i][1]) + field[1][i]);

		}

		std::cout << std::max(dp[n][0], std::max(dp[n][1], dp[n][2])) << "\n";


	}

	return 0;

}