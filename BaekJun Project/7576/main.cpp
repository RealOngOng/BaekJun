#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

typedef pair<Vector2, int> pi;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int field[1001][1001];
bool visit[1001][1001];

int n, m;

bool isOut(Vector2 vec) { return(vec.x < 0 || vec.y < 0 || vec.x >= n || vec.y >= m); }

int main() {

	scanf("%d %d", &n, &m);

	queue<pi> q;

	for (int y = 0; y < m; y++)
		for (int x = 0; x < n; x++) {

			scanf("%d", &field[x][y]); 
			
			if (field[x][y] == 1) 
				q.push({ {x, y}, 0 });

		}

	int cnt = -1e9;

	while (!q.empty()) {

		int size = q.size();

		for (int i = 0; i < size; i++) {

			pi top = q.front(); q.pop();

			cnt = max(cnt, top.second);

			for (int j = 0; j < 4; j++) {

				Vector2 dir = { top.first.x + dx[j], top.first.y + dy[j] };

				if (isOut(dir) || visit[dir.x][dir.y] || field[dir.x][dir.y] == -1) continue;

				visit[dir.x][dir.y] = true;
				field[dir.x][dir.y] = 1;
				q.push({ dir, top.second + 1 });

			}

		}

	}

	bool isOK = true;

	for (int y = 0; y < m; y++)
		for (int x = 0; x < n; x++)
			if (field[x][y] == 0) {

				isOK = false;
				break;

			}

	if (!isOK) printf("-1\n");
	else printf("%d\n", cnt);

	return 0;

}