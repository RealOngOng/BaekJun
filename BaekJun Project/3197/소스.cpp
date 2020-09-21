#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {
	int x, y;
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int p[1500 * 1500];

int find(int x) {
	if (p[x] == 0) return x;
	else
		return p[x] = find(p[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	p[b] = a;
}

int n, m; 
int field[1501][1501];
bool visit[1501][1501];
bool isOut(Vector2 pos) { return (pos.x < 0 || pos.y < 0 || pos.x > n || pos.y > m); }

int main() {

	cin >> n >> m;
	int idx = 1;
	queue<Vector2> q;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '.') field[i][j] = 3;
			else if (str[j] == 'X') field[i][j] = 0, visit[i][j] = true;
			else if (str[j] == 'L') {
				field[i][j] = idx++;
				visit[i][j] = true;
				q.push({i, j});
			}
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++)
	//		cout << field[i][j] << " ";
	//	cout << "\n";
	//}

	while (!q.empty()) {
		Vector2 top = q.front(); q.pop();
		vector<Vector2> pos;
		for (int i = 0; i < 4; i++) {
			Vector2 front = { top.x + dx[i], top.y + dy[i] };
			if (isOut(front) || visit[front.x][front.y] || field[front.x][front.y] == 0) continue;
			
			visit[front.x][front.y] = true;
			field[front.x][front.y] = field[top.x][top.y];
			q.push(front);
			pos.push_back(front);
		}

		for (Vector2 p : pos) {
			for (int i = 0; i < 4; i++) {
				Vector2 front = { p.x + dx[i], p.y + dy[i] };
				if (isOut(front)) continue;
				int v = field[front.x][front.y];
				if (0 < v && v < 3)
					merge(field[p.x][p.y], v);
			}
		}
	}

	function<void(Vector2, int)> dfs = [&](Vector2 pos, int num) -> void {
		visit[pos.x][pos.y] = true;
		field[pos.x][pos.y] = num;
		for (int i = 0; i < 4; i++) {
			Vector2 front = { pos.x + dx[i], pos.y + dy[i] };
			if (isOut(front) || visit[front.x][front.y] || field[front.x][front.y] == 0) continue;
			dfs(front, num);
		}
	};

	int num = 3;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visit[i][j])
				dfs({i, j}, num++);

	//cout << "\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++)
	//		cout << field[i][j] << " ";
	//	cout << "\n";
	//}

	while (!q.empty()) q.pop();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (field[i][j] > 0)
				q.push({ i, j });
			else
				visit[i][j] = false;

	function<bool()> isOk = [&]() -> bool {
		return find(1) == find(2);
	};

	int ans = 0;

	while (!q.empty()) {
		if (isOk()) break;
		int len = q.size();
		vector<Vector2> pos;
		while (len--) {

			Vector2 top = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				Vector2 front = { top.x + dx[i], top.y + dy[i] };
				if (isOut(front) || visit[front.x][front.y]) continue;
				if (field[front.x][front.y] == 0)
					field[front.x][front.y] = field[top.x][top.y];
				visit[front.x][front.y] = true;
				pos.push_back(front);
				q.push(front);
			}

		}

		for (Vector2 p : pos) {
			for (int i = 0; i < 4; i++) {
				Vector2 front = { p.x + dx[i], p.y + dy[i] };
				if (isOut(front) || field[front.x][front.y] == 0) continue;
				merge(field[p.x][p.y], field[front.x][front.y]);
			}
		}
		ans++;
	}

	cout << ans;

	return 0;

}