#include <iostream>
#include <algorithm>

#define MAX 2001

int arr[MAX];
bool dp[MAX][MAX];

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	int n; std::cin >> n;

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {

			if (j - i == 0) dp[i][j] = true;
			else if (j - i == 1) dp[i][j] = (arr[i] == arr[j]);

		}

	for (int i = n - 1; i >= 0; i--)
		for (int j = i; j < n; j++) {

			if (j - i > 1) {

				if (arr[i] == arr[j]) {

					dp[i][j] = 1,
						dp[i][j] = std::min(dp[i][j], dp[i + 1][j - 1]);

				}

			}
				
		}

	int q; std::cin >> q;

	while (q--) {

		int s, e; std::cin >> s >> e;

		std::cout << dp[s - 1][e - 1] << "\n";

	}

	return 0;

} 