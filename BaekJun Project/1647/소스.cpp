#include <bits/stdc++.h>

using namespace std;

typedef struct Line {

	int s, e, cost;

};

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

	int n, m; cin >> n >> m;

	vector<Line> line;
	for (int i = 0; i < m; i++) {

		int a, b, c; cin >> a >> b >> c;
		line.push_back({a, b, c});

	}

	int ans = 0, cnt = 0;;
	
	sort(line.begin(), line.end(), 
		 [](const Line& l1, const Line& l2) -> bool {return l1.cost < l2.cost; });
	memset(dsu, -1, sizeof(dsu));

	vector<int> load;

	for (Line w : line) {

		if (merge(w.s, w.e)) {

			ans += w.cost;
			load.push_back(w.cost);
			if (++cnt == n - 1) break;

		}

	}

	cout << ans - *max_element(load.begin(), load.end());

	return 0;

}