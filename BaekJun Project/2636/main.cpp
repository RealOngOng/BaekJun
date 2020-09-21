#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int field[102][102];
bool visit[102][102];

int n, m;

bool isEmpty() {

	bool empty = true;

	for (int y = 1; y <= m; y++)
		for (int x = 1; x <= n; x++)
			if (field[x][y]) { empty = false; break;}

	return empty;

}

void Update() {

	for (int y = 1; y <= m; y++)
		for (int x = 1; x <= n; x++)
			if (field[x][y] == 2) field[x][y] = 0;

}

void Print() {

	for (int y = 1; y <= m; y++) {

		for (int x = 1; x <= n; x++)
			printf("%d ", field[x][y]);

		printf("\n");

	}

}

bool isOut(Vector2 pos) { return(pos.x < 0 || pos.y < 0 || pos.x > n || pos.y > m); }

int main() {

	scanf("%d %d", &m, &n);

	for (int y = 1; y <= m; y++)
		for (int x = 1; x <= n; x++)
			scanf("%d", &field[x][y]);

	int day = 0, count = 0;

	while (true) {

		if (isEmpty()) break;

		count = 0;

		queue<Vector2> q;

		q.push({0, 0});

		while (!q.empty()) {

			Vector2 top = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {

				Vector2 dir = { top.x + dx[i], top.y + dy[i] };

				if (field[dir.x][dir.y] == 1) field[dir.x][dir.y] = 2, count++;
				if (isOut(dir) || visit[dir.x][dir.y] || field[dir.x][dir.y] != 0) continue;

				visit[dir.x][dir.y] = true;
				q.push(dir);

			}

		}

		Update();

		day++;
		memset(visit, false, sizeof(visit));

	}

	printf("%d\n%d\n", day, count);

	return 0;

}