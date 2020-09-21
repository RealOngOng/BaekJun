#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

vector<Vector2> pos;

int dp[1001][1001];

int n, w;

int distance(int from, int to) { return abs(pos[from].x - pos[to].x) + abs(pos[from].y - pos[to].y); }

int solve(int num, int c1, int c2) {

	if (dp[c1][c2] != -1) return dp[c1][c2];

	if (num == w) return 0;

	int case1 = solve(num + 1, num, c2) + distance(c1, num),
		case2 = solve(num + 1, c1, num) + distance(c1, num);

}

int main() {

	memset(dp, -1, sizeof(dp));

	scanf("%d %d", &n, &w);

	pos.push_back({ 1, 1 });
	pos.push_back({ n, n });

	for (int i = 1; i <= n; i++) {

		int x, y; scanf("%d %d", &x, &y);
		pos.push_back({x, y});

	}

	solve(2, 0, 1);

	return 0;

}