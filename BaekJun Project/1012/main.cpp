#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool field[51][51], visit[51][51];

int n, m, k;

bool isOut(pi pos) {return (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= m);}

void dfs(pi pos) {

	visit[pos.first][pos.second] = true;

	for (int i = 0; i < 4; i++) {

		pi dir = { pos.first + dx[i], pos.second + dy[i] };

		if (isOut(dir) || visit[dir.first][dir.second] || !field[dir.first][dir.second]) continue;
		dfs(dir);

	}

}

int main() {

	int t; scanf("%d", &t);
	while (t--) {

		scanf("%d %d %d", &n, &m, &k);

		int result = 0;

		vector<pi> pos;

		while (k--) {

			int a, b; scanf("%d %d", &a, &b);

			field[a][b] = true;

			pos.push_back({a, b});

		}

		for (pi p : pos) {

			if (visit[p.first][p.second]) continue;

			dfs(p), result++;

		}

		printf("%d\n", result);

		memset(field, false, sizeof(field));
		memset(visit, false, sizeof(visit));

	}

	return 0;

}