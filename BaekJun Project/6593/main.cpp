#include <bits/stdc++.h>

#define SANGBUM 'S'
#define WALL '#'
#define NONE '.'
#define EXIT 'E'

using namespace std;

typedef struct Vector3 {

	int x, y, z;

	bool operator==(Vector3 vec) { return (x == vec.x && y == vec.y && z == vec.z); }

};

typedef pair<Vector3, int> pii;

char field[31][31][31];
bool visit[31][31][31];

int l, r, c;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

bool isOut(Vector3 vec) { return (vec.x < 1 || vec.y < 1 || vec.z < 1 || vec.x > c || vec.y > r || vec.z > l); }

int main() {

	while (true) {

		scanf("%d %d %d", &l, &r, &c);

		if (l == 0 && r == 0 && c == 0) break;

		Vector3 start, end;

		for (int z = 1; z <= l; z++)
			for (int y = 1; y <= r; y++) {

				string str; cin >> str;

				for (int x = 1; x <= c; x++) {

					field[x][y][z] = str[x - 1];

					if (str[x - 1] == SANGBUM) start = { x, y, z };
					if (str[x - 1] == EXIT) end = { x, y, z };

				}

			}

		queue<pii> q;

		visit[start.x][start.y][start.z] = true;
		q.push({start, 0});

		int cnt = 1e9 + 1;

		while (!q.empty()) {

			pii top = q.front(); q.pop();

			if (top.first == end)
				cnt = min(cnt, top.second);

			for (int i = 0; i < 6; i++) {

				Vector3 dir = { top.first.x + dx[i], top.first.y + dy[i], top.first.z + dz[i] };

				if (isOut(dir) || visit[dir.x][dir.y][dir.z] || field[dir.x][dir.y][dir.z] == WALL) continue;

				visit[dir.x][dir.y][dir.z] = true;
				q.push({dir, top.second + 1});

			}

		}

		if (visit[end.x][end.y][end.z]) printf("Escaped in %d minute(s).\n", cnt);
		else printf("Trapped!\n");

		memset(visit, false, sizeof(visit));

	}

	return 0;

}