#include <bits/stdc++.h>

#define NONE '0'
#define WALL '1'
#define START 'S'
#define KEY 'K'

using namespace std;

typedef struct Vector2 {

	int x, y;
	bool operator<(const Vector2& v) const{

		if (x != v.x) return x < v.x;
		return y < v.y;

	}

};

typedef struct Line {

	int s, e, cost;

};

typedef struct bdata {

	Vector2 pos;
	int dst;

};

int dsu[251];

int find(int n) {

	if (dsu[n] < 0) return n;
	else
		return dsu[n] = find(dsu[n]);

}

bool merge(int a, int b) {

	a = find(a);
	b = find(b);

	if (a == b) return false;
	dsu[b] = a;
	return true;

}

char field[52][52];
bool visit[52][52];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {

	int n, m; cin >> n >> m;

	for (int i = 0; i < n + 1; i++)
		field[i][0] = field[0][i] = field[i][n + 1] = field[n + 1][i] = WALL;

	vector<Vector2> start;
	map<Vector2, int> mm;

	int cnt = 0;

	for (int i = 1; i <= n; i++) {

		string str; cin >> str;

		for (int j = 1; j <= n; j++) {

			field[i][j] = str[j - 1];

			if (field[i][j] == START || field[i][j] == KEY)
				start.push_back({ i, j }), mm.insert({ {i, j}, cnt++ });
			
		}

	}

	vector<Line> line;

	for (int i = 0; i < start.size(); i++) {

		memset(visit, false, sizeof(visit));

		Vector2 s = start[i];

		queue<bdata> q;

		q.push({ s, 0 });

		visit[s.x][s.y] = true;

		while (!q.empty()) {

			bdata top = q.front(); q.pop();

			Vector2 pos = top.pos;
			int dst = top.dst;

			if (field[pos.x][pos.y] == KEY)
				line.push_back({ i, mm[pos], dst });

			for (int j = 0; j < 4; j++) {

				Vector2 front = { pos.x + dx[j], pos.y + dy[j] };

				if (visit[front.x][front.y]) continue;
				if (field[front.x][front.y] == WALL) continue;

				visit[front.x][front.y] = true;
				q.push({front, dst + 1});

			}

		}

	}

	memset(dsu, -1, sizeof(dsu));
	sort(line.begin(), line.end(),
		 [](const Line& p1, const Line& p2) -> bool {
		return p1.cost < p2.cost;
	});

	int ans = 0, num = 0;

	for (Line w : line) {

		if (merge(w.s, w.e)) {

			ans += w.cost;
			if (++num == m) break;

		}

	}

	if (num == m)
		cout << ans;
	else
		cout << "-1";

	return 0;

}