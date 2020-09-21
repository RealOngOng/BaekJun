#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m, cnt;

bool isOut(Vector2 pos) { return (pos.x < 0 || pos.y < 0 || pos.x >= m || pos.y >= n); }

bool visit[101][101];

void dfs(Vector2 pos, int dir, int count) {

	if (count >= n * m - 1) return;

	while (true) {

		Vector2 front = { pos.x + dx[dir], pos.y + dy[dir] };

		if (isOut(front) || visit[front.x][front.y]) break;

		pos = front;
		visit[front.x][front.y] = true;

		count++;

	}

	cnt++;

	dfs(pos, (dir + 1) % 4, count);

}

int main() {

	scanf("%d %d", &n, &m);

	visit[0][0] = true;
	dfs({0, 0}, 0, 0);

	printf("%d\n", cnt - 1);

	return 0;

}