#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

vector<Vector2> pos, candidate;

int n, m, t, k;

int GetAreaVertex(Vector2 sp) {

	Vector2 ep = { sp.x + k, sp.y + k };

	int count = 0;

	for (Vector2 p : pos)
		if (sp.x <= p.x && p.x <= ep.x && sp.y <= p.y && p.y <= ep.y) count++;

	return count;

}

int main() {

	cin >> n >> m >> t >> k;

	vector<int> sx, sy;

	for (int i = 0; i < t; i++) {

		int a, b; cin >> a >> b;

		pos.push_back({ a + b, a - b });

		sx.push_back(a + b);
		sy.push_back(a - b);

	}

	sx.push_back(0);
	sy.push_back(0);

	for (auto x = sx.begin(); x != sx.end(); x++)
		for (auto y = sy.begin(); y != sy.end(); y++)
			candidate.push_back({ *x, *y });

	int cnt = 0;
	Vector2 loc = { 0, 0 };

	for (Vector2 p : candidate) {

		int c = GetAreaVertex(p);

		if (cnt < c) {

			cnt = c;
			loc = { p.x, p.y };

		}

	}

	int x = (loc.x - loc.y) / 2;
	int y = (loc.x + loc.y) / 2;

	cout << x << " " << y << "\n";
	cout << cnt << "\n";

	return 0;

}