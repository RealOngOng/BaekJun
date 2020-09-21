#include <bits/stdc++.h>

using namespace std;

typedef struct Vector3 {

	int x, y, z;

};

typedef pair<Vector3, int> pi;

int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dy[6] = { -1, 1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

int field[101][101][101];
bool visit[101][101][101];

int n, m, h;

bool isOut(Vector3 vec) { return(vec.x < 0 || vec.y < 0 || vec.z < 0 || vec.x >= n || vec.y >= m || vec.z >= h); }

int main() {

	scanf("%d %d %d", &n, &m, &h);

	queue<pi> q;

	for (int z = 0; z < h; z++)
		for (int y = 0; y < m; y++)
			for (int x = 0; x < n; x++) {

				scanf("%d", &field[x][y][z]);

				if (field[x][y][z] == 1)
					q.push({ {x, y, z}, 0 });

			}

	int cnt = -1e9;

	while (!q.empty()) {

		int size = q.size();

		for (int i = 0; i < size; i++) {

			pi top = q.front(); q.pop();

			cnt = max(cnt, top.second);

			for (int j = 0; j < 6; j++) {

				Vector3 dir = { top.first.x + dx[j], top.first.y + dy[j], top.first.z + dz[j] };

				if (isOut(dir) || visit[dir.x][dir.y][dir.z] || 
					field[dir.x][dir.y][dir.z] == -1 || field[dir.x][dir.y][dir.z] == 1) continue;

				visit[dir.x][dir.y][dir.z] = true;
				field[dir.x][dir.y][dir.z] = 1;
				q.push({ dir, top.second + 1 });

			}

		}

	}

	bool isOK = true;

	for (int z = 0; z < h; z++) 
		for (int y = 0; y < m; y++)
			for (int x = 0; x < n; x++)
				if (field[x][y][z] == 0) {

					isOK = false;
					break;

				}

	if (!isOK) printf("-1\n");
	else printf("%d\n", cnt);

	return 0;

}