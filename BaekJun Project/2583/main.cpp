#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, m, k, num;
bool field[101][101], visit[101][101];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool isOut(pi pos) { return (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= m); }

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

	memset(field, true, sizeof(field));

	scanf("%d %d %d", &n, &m, &k);

	while (k--) {

		int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int i = x1; i < x2 ; i++)
			for (int j = y1; j < y2; j++)
				field[n - j - 1][i] = false;

	}

	int result = 0;
	vector<int> vec;

	for(int i=0; i < n; i++)
		for (int j = 0; j < m; j++) {

			if (visit[i][j] || !field[i][j]) continue;

			num = 0;

			dfs({ i, j }), result++;
			vec.push_back(num);

		}

	printf("%d\n", result);

	sort(vec.begin(), vec.end());

	for (int i : vec) printf("%d ", i);

	return 0;

}