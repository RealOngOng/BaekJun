#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pd;

typedef struct Line {

	int s, e;
	double cost;

};

int dsu[101];

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

double distance(pd p1, pd p2) {

	double x = p1.first - p2.first;
	double y = p1.second - p2.second;

	return sqrt(x * x + y * y);

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	
	vector<Line> line;
	vector<pd> pos;

	for (int i = 0; i < n; i++) {

		double x, y; cin >> x >> y;
		pos.push_back({x, y});

	}

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			double dst = distance(pos[i], pos[j]);

			line.push_back({i, j, dst});

		}

	}

	double ans = 0;
	int cnt = 0;
	memset(dsu, -1, sizeof(dsu));
	sort(line.begin(), line.end(),
		 [](const Line& l1, const Line& l2) -> bool {return l1.cost < l2.cost; });

	for (Line w : line) {

		if (merge(w.s, w.e)) {

			ans += w.cost;
			if (++cnt == n - 1) break;

		}

	}

	cout.precision(3);
	cout << ans;

	return 0;

}