#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int main() {

	int n, m, k; scanf("%d %d %d", &n, &m, &k);

	for(int i=0; i < n; i++)
		for (int j = 0; j < m; j++) {

			int a; scanf("%d", &a);

			dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + a;

		}

	while (k--) {

		int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int sum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		int w = x2 - x1 + 1, h = y2 - y1 + 1;

		printf("%d\n", sum / (w * h));

	}

	return 0;

}