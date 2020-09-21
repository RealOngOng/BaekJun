#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int field[100][100];

bool visit[100][100];

int n;

bool isOut(pi pos) { return (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= n); }

void dfs(pi pos, int height) {

	visit[pos.first][pos.second] = true;

	for (int i = 0; i < 4; i++) {

		pi dir = { pos.first + dx[i], pos.second + dy[i] };

		if (isOut(dir) || visit[dir.first][dir.second] || field[dir.first][dir.second] <= height) continue;

		dfs(dir, height);

	}

}

int GetGood(int height) {

	int k = 0, m = 0;

	while (k <= height) {

		int result = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {

				if (visit[i][j] || field[i][j] <= k) continue;

				dfs({ i, j }, k), result++;

			}

		m = max(m, result);
		memset(visit, false, sizeof(visit));

		k++;

	}

	return m;

}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &field[i][j]);

	std::cout << GetGood(100) << "\n";

	return 0;

}