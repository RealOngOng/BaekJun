#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

bool field[26][26], visit[26][26];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int n, num;

bool isOut(pi p) { return (p.first < 0 || p.second < 0 || p.first >= n || p.second >= n); }

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

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		string str; cin >> str;

		for (int j = 0; j < n; j++) field[i][j] = str[j] - '0';

	}

	int result = 0;
	vector<int> vec;

	for(int i=0; i < n; i++)
		for (int j = 0; j < n; j++) {

			if (visit[i][j] || !field[i][j]) continue;

			num = 0;

			dfs({ i, j }), result++;
			vec.push_back(num);

		}

	sort(vec.begin(), vec.end());

	printf("%d\n", result);

	for (int i : vec) printf("%d\n", i);

	return 0;

}