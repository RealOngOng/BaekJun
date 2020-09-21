#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int field[301][301];
bool visit[301][301];

int n, m;

bool isOut(Vector2 pos) { return (pos.x < 0 || pos.y < 0 || pos.x >= n || pos.y >= m); }

void dfs(Vector2 pos) {

	visit[pos.x][pos.y] = true;

	for (int i = 0; i < 4; i++) {

		Vector2 dir = { pos.x + dx[i], pos.y + dy[i] };

		if (isOut(dir) || visit[dir.x][dir.y] || field[dir.x][dir.y] == 0) continue;

		visit[dir.x][dir.y] = true;
		dfs(dir);

	}

}

int GetComponent() {

	int count = 0;

	for(int i=0; i < n; i++)
		for (int j = 0; j < m; j++) {

			if (visit[i][j] || field[i][j] == 0) continue;

			dfs({i, j});
			count++;

		}

	memset(visit, false, sizeof(visit));

	return count;

}

void Dry() {

	queue<Vector2> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (field[i][j] == 0) q.push({i, j});

	while (!q.empty()) {

		Vector2 top = q.front(); q.pop();

		visit[top.x][top.y] = true;

		for (int i = 0; i < 4; i++) {

			Vector2 dir = { top.x + dx[i], top.y + dy[i] };

			if (isOut(dir)) continue;

			visit[dir.x][dir.y] = true;

			if (field[dir.x][dir.y] > 0) field[dir.x][dir.y]--;
			if (visit[dir.x][dir.y] || field[dir.x][dir.y] != 0) continue;

			q.push(dir);

		}

	}

	memset(visit, false, sizeof(visit));

}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &field[i][j]);

	int year = 0;

	while (true) {

		int cmp = GetComponent();

		if (cmp == 0) { year = 0; break; }
		if (cmp > 1) break;

		Dry();

		year++;

	}

	printf("%d\n", year);

	return 0;

}