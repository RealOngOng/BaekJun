#include <bits/stdc++.h>

#define SANGGUN '@'
#define NONE '.'
#define WALL '#'
#define FIRE '*'

using namespace std;

typedef struct Vector2 {

	int x, y;

	bool operator==(Vector2 vec) { return (x == vec.x && y == vec.y); }

};

typedef pair<Vector2, int> pi;


int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

char field[1001][1001];
bool visit[1001][1001];

int a, b;

bool isOut(Vector2 vec) { return (vec.x < 1 || vec.y < 1 || vec.x > a || vec.y > b); }

int main() {

	int t; scanf("%d", &t);

	while (t--) {

		scanf("%d %d", &a, &b);

		int cnt = 1e9;

		Vector2 start;

		queue<pi> q1;
		queue<Vector2> q2;

		for (int y = 1; y <= b; y++) {

			string str; cin >> str;

			for (int x = 1; x <= a; x++) {

				field[x][y] = str[x - 1];

				if (field[x][y] == SANGGUN) start = { x, y };
				if (field[x][y] == FIRE) q2.push({ x, y });

			}

		}

		q1.push({start, 0});
		visit[start.x][start.y] = true;

		while (!q1.empty()) {

			int size;

			size = q2.size();

			for (int i = 0; i < size; i++) {

				Vector2 fire = q2.front(); q2.pop();

				for (int j = 0; j < 4; j++) {

					Vector2 dir = { fire.x + dx[j], fire.y + dy[j] };

					if (isOut(dir) || field[dir.x][dir.y] != NONE) continue;

					field[dir.x][dir.y] = FIRE;
					q2.push(dir);

				}

			}

			size = q1.size();

			for (int i = 0; i < size; i++) {

				pi top = q1.front(); q1.pop();

				for (int i = 0; i < 4; i++) {

					Vector2 dir = { top.first.x + dx[i], top.first.y + dy[i] };

					if (isOut(dir)) { cnt = min(cnt, top.second + 1); continue; }

					if (visit[dir.x][dir.y] || field[dir.x][dir.y] == FIRE || field[dir.x][dir.y] == WALL) continue;

					visit[dir.x][dir.y] = true;
					q1.push({ dir, top.second + 1 });

				}

			}

		}

		if (cnt == 1e9) printf("IMPOSSIBLE\n");
		else printf("%d\n", cnt);

		memset(visit, false, sizeof(visit));

	}

	return 0;

}