#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {
	int x, y;
};

int sum[301][301];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < str.length(); j++) {
			int a = str[j] - '0';
			sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a;
		}
	}

	function<int(int, int, int, int)> GetSum = [&](int x1, int y1, int x2, int y2) -> int {
		return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
	};

	function<bool(Vector2, Vector2)> solve = [&](Vector2 start, Vector2 end) -> bool {

		int midx = (start.x + end.x) / 2;
		int midy = (start.y + end.y) / 2;

		for (int x = start.x; x <= midx; x++) {

			int dx = end.x - (x - start.x);

			if (GetSum(x, start.y, x, end.y)
				!= GetSum(dx, start.y, dx, end.y))
				return false;

		}

		for (int y = start.y; y <= midy; y++) {

			int dy = end.y - (y - start.y);

			if (GetSum(start.x, y, end.x, y)
				!= GetSum(start.x, dy, end.x, dy))
				return false;

		}

		return true;

	};

	int ans = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {

			int len = min(n - i, m - j);

			for (int w = len; w >= ans - 1; w--) {
				Vector2 start = { i, j }, end = { i + w, j + w };
				if (solve(start, end)) {
					ans = max(ans, w + 1);
					break;
				}
			}

		}

	if (ans == 1) cout << "-1\n";
	else cout << ans << "\n";

	return 0;

}