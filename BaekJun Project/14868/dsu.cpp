#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {
	int x, y;
};

int p[100100];
int field[2020][2020];
bool visit[2020][2020];

int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int find(int a) {

	if (p[a] == 0) return a;
	else 
		return p[a] = find(p[a]);

}

void merge(int a, int b) {

	a = find(a);
	b = find(b);

	if (a == b) return;
	p[b] = a;

}

bool isOut(int x, int y) { return (x < 1 || y < 1 || x > n || y > n); }

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	queue<Vector2> q;
	vector<Vector2> vec;
	for (int i = 0; i < m; i++) {

		int x, y; cin >> x >> y;
		field[x][y] = i + 1;
		q.push({x, y});
		vec.push_back({x, y});

	}

	//merge한 횟수 m - 1번하면 모두 한걸로 볼 수 있음
	int cnt = 0;
	int ans = 0;

	for (Vector2 p : vec) {

		for (int i = 0; i < 4; i++) {
			Vector2 front = { p.x + dx[i], p.y + dy[i] };
			if (isOut(front.x, front.y)) continue;

			if (field[front.x][front.y] != 0) {

				if (find(field[p.x][p.y]) != find(field[front.x][front.y])) {
					cnt++;
					merge(field[p.x][p.y], field[front.x][front.y]);
				}
			}
		}

	}

	while (!q.empty()) {

		if (cnt >= m - 1) break;
		int v = q.size();
		
		vector<Vector2> pos;

		while (v--) {

			Vector2 top = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				Vector2 front = { top.x + dx[i], top.y + dy[i] };
				if (isOut(front.x, front.y) || visit[front.x][front.y]) continue;
				if(field[front.x][front.y] == 0)
					field[front.x][front.y] = field[top.x][top.y];

				visit[front.x][front.y] = true;
				q.push(front);
				pos.push_back(front);
			}

		}

		for (Vector2 p : pos) {

			for (int i = 0; i < 4; i++) {
				Vector2 front = { p.x + dx[i], p.y + dy[i] };
				if (isOut(front.x, front.y)) continue;

				if (field[front.x][front.y] != 0) {

					if (find(field[p.x][p.y]) != find(field[front.x][front.y])) {
						cnt++;
						merge(field[p.x][p.y], field[front.x][front.y]);
					}
				}
			}

		}

		ans++;

	}

	cout << ans;

	return 0;

}