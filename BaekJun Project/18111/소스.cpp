#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct Cost {

	ll hole = 0, cut = 0;

};

int field[501][501];

ll n, m, b;

Cost GetCost(int h) {

	Cost cost;

	ll result = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {

			if (field[i][j] < h)
				cost.hole += h - field[i][j];

			if (field[i][j] > h)
				cost.cut += field[i][j] - h;

		}

	cost.cut *= 2;

	return cost;

}

int main() {

	scanf("%d %d %d", &n, &m, &b);

	int hmin = 257, hmax = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {

			int w; scanf("%d", &w);
			field[i][j] = w;

			hmin = min(w, hmin);
			hmax = max(w, hmax);

		}

	ll time = 1e18, height = 0;
	
	for (ll i = hmin; i <= hmax; i++) {

		Cost cost = GetCost(i);

		ll block = b + cost.cut / 2;

		if (block < cost.hole) continue;

		ll t = cost.cut + cost.hole;

		if (time > t) {

			time = t;
			height = i;

		}
		else if (time == t)
			height = max(height, i);

	}

	printf("%lld %lld", time, height);

	return 0;

}