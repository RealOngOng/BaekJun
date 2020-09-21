#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

int arr[1001][1001], dp[1001][1001];

int GetArea(int sx, int sy, int ex, int ey) {

	return dp[ex][ey] - dp[sx - 1][ey] - dp[ex][sy - 1] + dp[sx - 1][sy - 1];

}

int main() {

	int n; scanf("%d", &n);

	vector<Vector2> pos(n);
	
	for (int i = 0; i < n; i++) {

		int x, y; scanf("%d %d", &x, &y);
		
		pos[i] = { x, y };

	}

	sort(pos.begin(), pos.end(), [](const Vector2& v1, const Vector2& v2) -> bool {

		if (v1.x != v2.x) return v1.x < v2.x;
		return v1.y < v2.y;

	});

	int mx = pos[0].x,
		my = pos[0].y;

	int px = 0, py = 0;

	for (int i = 0; i < n; i++) {

		if (pos[i].x == mx) pos[i].x = px;
		else pos[i].x = ++px, mx = pos[i].x;

	}

	sort(pos.begin(), pos.end(), [](const Vector2& v1, const Vector2& v2) -> bool {

		if (v1.y != v2.y) return v1.y < v2.y;
		return v1.x < v2.x;

	});

	for (int i = 0; i < n; i++) {

		if (pos[i].y == my) pos[i].y = py;
		else pos[i].y = ++py, my = pos[i].y;

	}

	for (Vector2 vec : pos)
		arr[vec.x][vec.y]++;

	sort(pos.begin(), pos.end(), [](const Vector2& v1, const Vector2& v2) -> bool {

		if (v1.x != v2.x) return v1.x < v2.x;
		return v1.y < v2.y;

	});

	for (int i = 0; i <= px; i++)
		for (int j = 0; j <= py; j++)
			dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + arr[i][j];

	int ans = 1e9;

	for (int i = 0; i <= px; i++)
		for (int j = 0; j <= py; j++) {

			int a1 = GetArea(1, 1, i + 1, j + 1),
			 a2 = GetArea(i + 1, 1, px, j + 1),
			 a3 = GetArea(1, j + 1, i + 1, py),
			 a4 = GetArea(i + 1, j + 1, px, py);

			ans = min(ans, max({a1, a2, a3, a4}));

		}

	printf("%d\n", ans);

	return 0;

}