#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;
	
	bool operator==(Vector2 vec) { return (x == vec.x && y == vec.y); }

};
typedef struct Route {

	Vector2 pos;
	int num;
	bool crashed;

};

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int n, m;

bool field[1001][1001], visit[2][1001][1001];

bool isOut(Vector2 pos) { return (pos.x < 0 || pos.y < 0 || pos.x >= n || pos.y >= m); }

int main() {

	scanf("%d %d", &n, &m);

	Vector2 end = { n - 1, m - 1 };

	for (int i = 0; i < n; i++) {

		string str; cin >> str;

		for (int j = 0; j < m; j++)
			field[i][j] = str[j] - '0';

	}

	queue<Route> q;

	q.push({ {0, 0}, 1, false });
	visit[0][0][0] = true;

	int cnt = 1e9;

	while (!q.empty()) {

		Route top = q.front(); q.pop();

		if (top.pos == end)
			cnt = min(cnt, top.num);

		for (int i = 0; i < 4; i++) {

			Vector2 dir = { top.pos.x + dx[i], top.pos.y + dy[i] };

			if (isOut(dir) || visit[top.crashed][dir.x][dir.y]) continue;

			if (field[dir.x][dir.y]) {

				if (top.crashed) continue;

				visit[1][dir.x][dir.y] = true;
				q.push({ dir, top.num + 1, true });

			}
			else {

				visit[top.crashed][dir.x][dir.y] = true;
				q.push({ dir, top.num + 1, top.crashed });

			}

		}

	}

	if (cnt == 1e9) printf("-1\n");
	else printf("%d\n", cnt);

	return 0;

}