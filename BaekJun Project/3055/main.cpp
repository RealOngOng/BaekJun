#include <bits/stdc++.h>

#define BEABER 'S'
#define HOUSE 'D'
#define NONE '.'
#define WALL 'X'
#define WATER '*'

using namespace std;

typedef struct Vector2 {

	int x, y;

	bool operator==(Vector2 vec) { return (x == vec.x && y == vec.y); }

};

typedef pair<Vector2, int> pi;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

char field[51][51];
bool visit[51][51];

int a, b;

bool isOut(Vector2 vec) { return (vec.x < 1 || vec.y < 1 || vec.x > a || vec.y > b); }

int main() {

	scanf("%d %d", &a, &b);

	int cnt = 1e9;

	Vector2 start, end;

	queue<pi> q1;
	queue<Vector2> q2;

	for (int x = 1; x <= a; x++) {

		string str; cin >> str;

		for (int y = 1; y <= b; y++) {

			field[x][y] = str[y - 1];

			if (field[x][y] == BEABER) start = { x, y };
			if (field[x][y] == HOUSE) end = { x, y };
			if (field[x][y] == WATER) q2.push({ x, y });

		}

	}

	q1.push({ start, 0 });
	visit[start.x][start.y] = true;

	while (!q1.empty()) {

		int size;

		size = q2.size();

		for (int i = 0; i < size; i++) {

			Vector2 fire = q2.front(); q2.pop();

			for (int j = 0; j < 4; j++) {

				Vector2 dir = { fire.x + dx[j], fire.y + dy[j] };

				if (isOut(dir) || field[dir.x][dir.y] != NONE) continue;

				field[dir.x][dir.y] = WATER;
				q2.push(dir);

			}

		}

		size = q1.size();

		for (int i = 0; i < size; i++) {

			pi top = q1.front(); q1.pop();

			if (top.first == end)
				cnt = min(cnt, top.second);

			for (int i = 0; i < 4; i++) {

				Vector2 dir = { top.first.x + dx[i], top.first.y + dy[i] };

				if (isOut(dir) || visit[dir.x][dir.y] || field[dir.x][dir.y] == WATER || field[dir.x][dir.y] == WALL) continue;

				visit[dir.x][dir.y] = true;
				q1.push({ dir, top.second + 1 });

			}

		}

	}

	if (cnt == 1e9) printf("KAKTUS\n");
	else printf("%d\n", cnt);

	return 0;

}