#include <iostream>

#define MAX 301

int arr[MAX][MAX], dp[MAX][MAX];

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);
	
	int n, m; std::cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			std::cin >> arr[i][j], dp[i][j] = arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] += dp[i][j - 1];

	int k; std::cin >> k;

	while (k--) {

		int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;

		int sum = 0;

		for (int i = x1; i <= x2; i++) sum += dp[i][y2] - dp[i][y1 - 1];

		std::cout << sum << "\n";

	}

	return 0;

}