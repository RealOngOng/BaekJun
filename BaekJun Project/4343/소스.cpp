#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pd;
typedef struct Line {

	int s, e;
	double cost;

};

double distance(pd p1, pd p2) {

	double x = p1.first - p2.first;
	double y = p1.second - p2.second;

	return sqrt(x * x + y * y);

}

int dsu[501];

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

	int tc; cin >> tc;

	while (tc--) {

		int n, m; cin >> n >> m;

		vector<pd> pos(m);
		for (int i = 0; i < m; i++)
			cin >> pos[i].first >> pos[i].second;

		vector<Line> line;

		for (int i = 0; i < m; i++) {

			for (int j = i + 1; j < m; j++) {

				double dst = distance(pos[i], pos[j]);
				line.push_back({i, j, dst});

			}

		}

		double ans = 0;
		int cnt = 0;

		sort(line.begin(), line.end(), 
			 [](const Line& p1, const Line& p2) -> bool {return p1.cost < p2.cost; });
		memset(dsu, -1, sizeof(dsu));

		for (Line w : line) {

			if (merge(w.s, w.e)) {

				ans = max(ans, w.cost);
				if (++cnt == m - n) break;

			}

		}

		cout << fixed;
		cout.precision(2);

		cout << ans << "\n";

	}

	return 0;

}