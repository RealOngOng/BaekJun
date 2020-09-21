#include <bits/stdc++.h>

using namespace std;

typedef struct Line {

	int s, e, cost;

};

int dsu[200001];

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

	while (true) {

		int n, m; cin >> n >> m;

		if (!n && !m) break;

		int sum = 0;

		vector<Line> line;
		int a, b, c;
		for (int i = 0; i < m; i++) {

			cin >> a >> b >> c;
			line.push_back({ a, b, c });
			sum += c;

		}

		int minimum = 0, maximum = 0;
		int cnt = 0;

		memset(dsu, -1, sizeof(dsu));
		sort(line.begin(), line.end(),
			 [](const Line& l1, const Line& l2) -> bool {return l1.cost < l2.cost; });

		for (Line w : line) {

			if (merge(w.s, w.e)) {

				minimum += w.cost;
				if (++cnt == n - 1) break;

			}

		}

		cout << sum - minimum << "\n";

	}

	return 0;

}