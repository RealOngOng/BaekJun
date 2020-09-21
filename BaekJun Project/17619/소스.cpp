#include <bits/stdc++.h>

using namespace std;

typedef struct Line {

	int idx, sx, ex, y;

};

bool cmp(const Line& l1, const Line& l2) {

	if (l1.sx != l2.sx) return l1.sx < l2.sx;
	if (l1.y != l2.y) return l1.y < l2.y;
	return l1.ex < l2.ex;

}

int p[100001];

int find(int n) {

	if (p[n] < 0) return n;

	return p[n] = find(p[n]);

}

void merge(int x, int y) {

	x = find(x);
	y = find(y);

	if (x != y) p[y] = x;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(p, -1, sizeof(p));

	int n, m; cin >> n >> m;

	vector<Line> arr;

	for (int i = 0; i < n; i++) {

		Line line;
		line.idx = i + 1;
		cin >> line.sx >> line.ex >> line.y;
		arr.push_back(line);

	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {

		Line now = arr[i];

		for (int j = i + 1; j < n; j++) {

			Line next = arr[j];

			if (now.ex < next.sx) break;
			if (now.ex >= next.sx) merge(now.idx, next.idx);

		}

	}

	while (m--) {

		int a, b; cin >> a >> b;
		cout << (find(a) == find(b)) << "\n";

	}

	return 0;

}