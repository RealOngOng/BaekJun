#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

	bool operator==(const Vector2& vec) { return(x == vec.x && y == vec.y); }

};

typedef struct bdata {

	Vector2 pos;
	int num, key;

};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

char field[51][51];
bool visit[51][51][1 << 6];

int main() {

	int n, m; scanf("%d %d", &n, &m);

	queue<bdata> q;

	for(int i=0; i < n; i++)
		for (int j = 0; j < m; j++) {

			scanf(" %c", &field[i][j]);
			if (field[i][j] == '0')
				q.push({ {i, j}, 0, 0});

		}

	int ans = -1;

	while (!q.empty()) {

		bdata top = q.front(); q.pop();

		if (field[top.pos.x][top.pos.y] == '1') {

			ans = top.num;
			break;

		}

		for (int i = 0; i < 4; i++) {

			Vector2 dir = { top.pos.x + dx[i], top.pos.y + dy[i] };

			if (dir.x < 0 || dir.y < 0 || dir.x >= n || dir.y >= m) continue;

			char front = field[dir.x][dir.y];

			if (visit[dir.x][dir.y][top.key] || front == '#') continue;

			if ('A' <= front && front <= 'F')
				if (!(top.key & (1 << (front - 'A')))) continue;

			visit[dir.x][dir.y][top.key] = true;

			if ('a' <= front && front <= 'f')
				q.push({dir, top.num + 1, top.key | (1 << (front - 'a'))});
			else
				q.push({ dir, top.num + 1, top.key });

		}

	}

	printf("%d\n", ans);

	return 0;

}