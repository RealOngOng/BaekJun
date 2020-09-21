#include <iostream>
#include <algorithm>

#define MAX 1003

int arr[MAX][MAX], dp[MAX][MAX];

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	int n, m; std::cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			std::cin >> arr[i][j], dp[i][j] = arr[i][j];

	int dx[3] = { 1, 0, 1 };
	int dy[3] = { 0, 1, 1 };

	int max = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {

			for (int k = 0; k < 3; k++) {

				dp[i + dx[k]][j + dy[k]] = std::max(dp[i + dx[k]][j + dy[k]], dp[i][j] + arr[i + dx[k]][j + dy[k]]);
				max = std::max(max, dp[i + dx[k]][j + dy[k]]);

			}

		}

	std::cout << max << "\n";

	return 0;

}