#include <bits/stdc++.h>

#define RED 'R'
#define GREEN 'G'
#define BLUE 'B'

using namespace std;

typedef pair<int, int> pi;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int n;

char field[101][101];
bool visit[101][101];

bool isOut(pi pos) { return (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= n); }

void dfs(char target, pi pos) {

	visit[pos.first][pos.second] = true;

	for (int i = 0; i < 4; i++) {

		pi dir = { pos.first + dx[i], pos.second + dy[i] };

		if (isOut(dir) || visit[dir.first][dir.second] || field[dir.first][dir.second] != target) continue;

		dfs(target, dir);

	}

}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		string str; cin >> str;

		for (int j = 0; j < n; j++) field[i][j] = str[j];

	}

	int normal = 0, color = 0;

	char target[3] = { 'R', 'G', 'B' };

	for (int w = 0; w < 3; w++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {

				if (visit[i][j] || field[i][j] != target[w]) continue;

				dfs(target[w], { i, j }), normal++;

			}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (field[i][j] == 'R') field[i][j] = 'G';

	memset(visit, false, sizeof(visit));

	for (int w = 1; w < 3; w++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {

				if (visit[i][j] || field[i][j] != target[w]) continue;

				dfs(target[w], { i, j }), color++;

			}

	printf("%d %d\n", normal, color);

	return 0;

}