#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

typedef long double ld;

ld chance[4];

ld cnt;
int n;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool visit[32][32];

void backtrack(Vector2 pos, int num, ld sum) {

	if (num == n) {

		cnt += sum;
		return;

	}

	for (int i = 0; i < 4; i++) {

		Vector2 dir = { pos.x + dx[i], pos.y + dy[i] };

		if (visit[dir.x][dir.y]) continue;

		visit[dir.x][dir.y] = true;
		backtrack(dir, num + 1, sum * chance[i]);
		visit[dir.x][dir.y] = false;

	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < 4; i++) {

		int a; cin >> a;
		chance[i] = a * 0.01;

	}

	visit[n][n] = true;
	backtrack({ n, n }, 0, 1);

	cout.precision(11); cout << fixed;

	cout << cnt;

	return 0;

}