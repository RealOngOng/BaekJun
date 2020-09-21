#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool used[26], visit[20][20];
char field[20][20];
int r, c, cnt;

bool isOut(Vector2 pos) { return (pos.x < 0 || pos.y < 0 || pos.x >= r || pos.y >= c); }

void backtracking(Vector2 pos, int num) {

	cnt = max(cnt, num);

	visit[pos.x][pos.y] = true;
	used[field[pos.x][pos.y] - 'A'] = true;

	for (int i = 0; i < 4; i++) {

		Vector2 dir = { pos.x + dx[i], pos.y + dy[i] };

		if (isOut(dir) || visit[dir.x][dir.y]) continue;
		if(!used[field[dir.x][dir.y] - 'A']) backtracking(dir, num + 1);

	}

	visit[pos.x][pos.y] = false;
	used[field[pos.x][pos.y] - 'A'] = false;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {

		string str; cin >> str;
		for (int j = 0; j < c; j++)
			field[i][j] = str[j];

	}

	backtracking({0, 0}, 1);
	cout << cnt << "\n";

	return 0;

}