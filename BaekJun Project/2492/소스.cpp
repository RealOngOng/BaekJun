#include <bits/stdc++.h>

using namespace std;

typedef struct Vector2 {

	int x, y;

};

vector<Vector2> pos, candidate;

int n, m, t, k;

bool isOut(Vector2 p) { return (p.x < 0 || p.x > n || p.y < 0 || p.y > m); }

int GetAreaVertex(Vector2 sp) {

	Vector2 ep = { sp.x + k, sp.y + k };

	if (isOut(ep)) return 0;

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
	Vector2 loc = { 0, 0 };

	for (Vector2 p : candidate) {

		if (p.x + k > n) p.x = n - k;
		if (p.y + k > m) p.y = m - k;

		int c = GetAreaVertex(p);

		if (cnt < c) {

			cnt = c;
			loc = {p.x, p.y + k};

		}

	}

	cout << loc.x << " " << loc.y << "\n";
	cout << cnt << "\n";

	return 0;

}