#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool field[101][101], visit[101][101];

int n, m;
int r = 0;

bool isOut(pi pos) { return (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= m); }

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {

		string str; cin >> str;

		for (int j = 0; j < m; j++) field[i][j] = str[j] - '0';

	}

	int r = 0;

	queue<pair<pi, int>> q;

	q.push({ {0, 0}, 0 });

	visit[0][0] = true;

	while (!q.empty()) {

		pair<pi, int> top = q.front(); q.pop();

		if (top.first == make_pair(n - 1, m - 1)) {

			r = top.second;
			break;

		}

		for (int i = 0; i < 4; i++) {

			pi dir = { top.first.first + dx[i], top.first.second + dy[i] };

			if (isOut(dir) || visit[dir.first][dir.second] || !field[dir.first][dir.second]) continue;

			visit[dir.first][dir.second] = true;
			q.push({ dir, top.second + 1 });

		}

	}

	printf("%d\n", r + 1);

	return 0;
	
}