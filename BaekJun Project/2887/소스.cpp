#include <bits/stdc++.h>

using namespace std;

typedef struct Vector3 {

	int x, y, z;
	Vector3() {}
	Vector3(int a, int b, int c) { x = a, y = b, z = c; }

};

typedef pair<int, Vector3> pv;

typedef struct Line {

	int s, e, cost;

};

int distance(Vector3 p1, Vector3 p2) { return min({ abs(p1.x - p2.x), abs(p1.y - p2.y), abs(p1.z - p2.z) }); }

int dsu[100001];

int find(int n) {

	if (dsu[n] < 0) return n;
	else
		return dsu[n] = find(dsu[n]);

}

bool merge(int a, int b) {

	a = find(a);
	b = find(b);

	if (a == b) return false;
	dsu[b] = a;
	return true;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	vector<pv> pos(n);
	for (int i = 0; i < n; i++) {

		int x, y, z; cin >> x >> y >> z;
		pos[i] = { i, {x, y, z} };

	}

	vector<Line> line;

	function<void()> add = [&]() -> void {

		for (int i = 0; i < n; i++) {

			int next = (i + 1) % n;

			int dst = distance(pos[i].second, pos[next].second);
			line.push_back({ pos[i].first, pos[next].first, dst });

		}

	};

	sort(pos.begin(), pos.end(),
		 [=](const pv& p1, const pv& p2) -> bool {

		return p1.second.x < p2.second.x;

	});
	add();

	sort(pos.begin(), pos.end(),
		 [=](const pv& p1, const pv& p2) -> bool {

		return p1.second.y < p2.second.y;

	});
	add();

	sort(pos.begin(), pos.end(),
		 [=](const pv& p1, const pv& p2) -> bool {

		return p1.second.z < p2.second.z;

	});
	add();

	memset(dsu, -1, sizeof(dsu));
	sort(line.begin(), line.end(), 
		 [](const Line& p1, const Line& p2) -> bool {
		return p1.cost < p2.cost;
	});

	int ans = 0, cnt = 0;

	for (Line w : line) {

		if (merge(w.s, w.e)) {

			ans += w.cost;
			if (++cnt == n - 1) break;

		}

	}

	cout << ans;

	return 0;
	
}