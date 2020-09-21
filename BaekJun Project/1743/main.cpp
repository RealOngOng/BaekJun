#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool visit[101][101];
bool field[101][101];
vector<pi> vec;

int n, m, k, num;

bool isOut(pi pos) { return (pos.first <= 0 || pos.second <= 0 || pos.first > n || pos.second > m); }

void dfs(pi pos) {

	num++;

	visit[pos.first][pos.second] = true;

	for (int i = 0; i < 4; i++) {

		pi dir = { pos.first + dx[i], pos.second + dy[i] };

		if (isOut(dir) || visit[dir.first][dir.second] || !field[dir.first][dir.second]) continue;

		dfs(dir);

	}

}

int main() {

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {

		int a, b; scanf("%d %d", &a, &b);

		field[a][b] = true;
		vec.push_back({a, b});

	}

	int result = 0;

	for (pi p : vec) {

		if (visit[p.first][p.second]) continue;

		num = 0;

		dfs(p), result = max(result, num);

	}

	printf("%d\n", result);

	return 0;

}