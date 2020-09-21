#include <bits/stdc++.h>

using namespace std;

typedef struct Line {

	int sv, ev;
	int cost;
	bool operator<(const Line& l) { return cost < l.cost; }

};

int dsu[1001];

int find(int n) {

	if (dsu[n] < 0) return n;
	else 
		return dsu[n] = find(dsu[n]);

}

void merge(int a, int b) {

	a = find(a);
	b = find(b);

	if (a != b) 
		dsu[b] = a;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dsu, -1, sizeof(dsu));

	int n, k; cin >> n >> k;
	vector<Line> line;
	for (int i = 0; i < k; i++) {

		int a, b, c; cin >> a >> b >> c;
		line.push_back({a, b, c});

	}

	sort(line.begin(), line.end());

	int ans = 0;
	int cnt = 0;

	for (Line w : line) {

		int a = find(w.sv), b = find(w.ev);

		if (a == b) continue;

		merge(w.sv, w.ev);
		ans += w.cost;

		if (++cnt == n - 1) break;

	}

	cout << ans;

	return 0;

}