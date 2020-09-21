#include <bits/stdc++.h>

using namespace std;

int p[1000001];

int find(int a) {

	if (p[a] < 0) return a;

	return p[a] = find(p[a]);

}

void merge(int a, int b) {

	a = find(a);
	b = find(b);

	if (a != b) p[a] = b;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(p, -1, sizeof(p));

	int n, m; cin >> n >> m;

	while (m--) {

		int a, b, c; cin >> a >> b >> c;

		if (a == 0)
			merge(b, c);
		else
			cout << ((find(b) == find(c)) ? "YES" : "NO") << "\n";

	}

	return 0;

}