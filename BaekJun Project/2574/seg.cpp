#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

typedef pair<int, int> pi;

const int MAXN = 30005;
const int MAXT = 132000;

int w, h, n;
int x[30005], y[30005];
pi byx[40005];// x, y, i i는 순서

int rmax = 0, rmin = INF;

struct seg {

	vector<pi>  tree[MAXT];
	vector<int> augm[MAXT]; //세그먼트 트리

	int alim[MAXT], lim;

	void build_tree(int nodeNum) {

		augm[nodeNum].resize(alim[nodeNum] * 2 + 1);

		fill(augm[nodeNum].begin(), augm[nodeNum].end(), INF);

		for (int j = 0; j < tree[nodeNum].size(); j++)
			for (int k = j + alim[nodeNum]; k; k >>= 1)
				augm[nodeNum][k] = min(augm[nodeNum][k], tree[nodeNum][j].second);

		//if (nodeNum <= w) {

		//	for (int j = 0; j < tree[nodeNum].size() + alim[nodeNum]; j++)
		//		std::cout << augm[nodeNum][j] << " ";

		//	std::cout << "\n";

		//}

	}

	void init(int n) {

		for (lim = 1; lim <= n; lim <<= 1); //lim n 보다 같거나 작은 2의 제곱

		for (int i = 0; i < n; i++) 
			for (int j = i + lim; j; j >>= 1)
				tree[j].push_back(byx[i]);

		//for (int j = 0; j < lim + n; j++) {

		//	for (int i = 0; i < tree[j].size(); i++)
		//		std::cout << tree[j][i].first << ", " << tree[j][i].second << " ";

		//	std::cout << "\n";

		//}
		//std::cout << "\n";

		for (int j = 0; j < MAXT; j++) {

			sort(tree[j].begin(), tree[j].end());

			for (alim[j] = 1; alim[j] <= tree[j].size(); alim[j] <<= 1); //트리 사이즈 보다 같거나 작은 2의 제곱 만들기

			build_tree(j);

		}

	}

	int newQuery(int nodeNum, int l, int r) {

		int lidx = lower_bound(tree[nodeNum].begin(), tree[nodeNum].end(), pi(l, -1e9)) - tree[nodeNum].begin();
		int ridx = upper_bound(tree[nodeNum].begin(), tree[nodeNum].end(), pi(r, 1e9)) - tree[nodeNum].begin();

		ridx--;
		lidx += alim[nodeNum];
		ridx += alim[nodeNum];

		int ret = 1e9;
		while (lidx < ridx) {
			if (lidx % 2 == 1) ret = min(ret, augm[nodeNum][lidx++]);
			if (ridx % 2 == 0) ret = min(ret, augm[nodeNum][ridx--]);
			lidx >>= 1;
			ridx >>= 1;
		}
		if (lidx == ridx) ret = min(ret, augm[nodeNum][lidx]);
		return ret;
	}

	int query(int sx, int ex, int sy, int ey) {
		int minv = 1e9;
		sx += lim;
		ex += lim;
		while (sx < ex) {
			if (sx % 2 == 1) minv = min(minv, newQuery(sx++, sy, ey));
			if (ex % 2 == 0) minv = min(minv, newQuery(ex--, sy, ey));
			sx >>= 1;
			ex >>= 1;
		}
		if (sx == ex) minv = min(minv, newQuery(sx, sy, ey));
		return minv;
	}

}seg;

// worst case nlg^2n -> use 2d segment tree
int query(int sx, int ex, int sy, int ey) {

	int minv = seg.query(sx + 1, ex - 1, sy + 1, ey - 1);
	if (minv > 1e8) return -1;
	return minv;

}

void solve(int sx, int ex, int sy, int ey, int col, int divider) {
	if (divider == -1) {
		rmax = max(rmax, (ex - sx) * (ey - sy));
		rmin = min(rmin, (ex - sx) * (ey - sy));
		return;
	}
	if (col == 0) {
		solve(sx, x[divider], sy, ey, 1, query(sx, x[divider], sy, ey));
		solve(x[divider], ex, sy, ey, 1, query(x[divider], ex, sy, ey));
	}
	else {
		solve(sx, ex, sy, y[divider], 0, query(sx, ex, sy, y[divider]));
		solve(sx, ex, y[divider], ey, 0, query(sx, ex, y[divider], ey));
	}
}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> w >> h >> n;
	fill(byx, byx + w, pi(-1, INF));

	for (int i = 0; i < n; i++) {

		std::cin >> x[i] >> y[i];
		byx[x[i]] = pi(y[i], i);

	}

	seg.init(w);

	solve(0, w, 0, h, 1, 0);

	printf("%d %d", rmax, rmin);

}
