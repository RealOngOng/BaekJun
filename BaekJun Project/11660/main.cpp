#include <bits/stdc++.h>

using namespace std;

int arr[1026][1026], dp[1026][1026];

int main() {

	int n, m; scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {

			scanf("%d", &arr[i][j]);
			dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + arr[i][j];

		}
 
	while (m--) {

		int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		printf("%d\n", dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]);

	}

	return 0;

}