#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

	bool operator==(Vector2 vec) { return (x == vec.x && y == vec.y); }

};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int r, c, k, cnt;

char field[6][6];
bool visit[6][6];

Vector2 dst;

bool isOut(Vector2 pos) { return (pos.x < 0 || pos.y < 0 || pos.x >= r || pos.y >= c); }

void backtrack(Vector2 pos, int num) {

	if (pos == dst) {

		if (num == k - 1) cnt++;

		return;

	}

	for (int i = 0; i < 4; i++) {

		Vector2 dir = { pos.x + dx[i], pos.y + dy[i] };

		if (visit[dir.x][dir.y] || isOut(dir) || field[dir.x][dir.y] == 'T') continue;

		visit[dir.x][dir.y] = true;
		backtrack(dir, num + 1);
		visit[dir.x][dir.y] = false;

	}

}

int main() {

	scanf("%d %d %d", &r, &c, &k);

	dst = { 0, c - 1 };

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf(" %c", &field[i][j]);
	
	visit[r - 1][0] = true;
	backtrack({r - 1, 0}, 0);

	printf("%d\n", cnt);

	return 0;

}