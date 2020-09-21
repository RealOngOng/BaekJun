#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

vector<Vector2> pos, candidate;

int n, l, m;

bool isOut(Vector2 p) { return (p.x < 1 || p.x > n || p.y < 1 || p.y > n); }

int GetAreaVertex(Vector2 sp, Vector2 ep) {

	if (isOut(ep)) return 0;

	int count = 0;

	for (Vector2 p : pos)
		if (sp.x <= p.x && p.x <= ep.x && sp.y <= p.y && p.y <= ep.y) count++;

	return count;

}

int main() {

	cin >> n >> l >> m;

	vector<int> sx, sy;

	for (int i = 0; i < m; i++) {

		int a, b; cin >> a >> b;

		pos.push_back({ a, b });

		sx.push_back(a);
		sy.push_back(b);

	}

	sx.push_back(0);
	sy.push_back(0);

	for (auto x = sx.begin(); x != sx.end(); x++)
		for (auto y = sy.begin(); y != sy.end(); y++)
			candidate.push_back({ *x, *y });

	int cnt = 0;

	int len = l / 2;

	for (Vector2 p : candidate) {

		for (int i = 1; i < len; i++) {

			int nx = i, ny = len - i;

			if (p.x + nx > n) p.x = n - nx;
			if (p.y + ny > m) p.y = m - ny;

			int c = GetAreaVertex(p, {p.x + nx, p.y + ny});

			cnt = max(cnt, c);

		}

	}

	cout << cnt << "\n";

	return 0;

}