//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define MAX 3 * 1e12
//
//typedef long long ll;
//
//typedef struct Building {
//
//	int x, y;
//	ll cost;
//
//};
//
//typedef struct Vertex {
//
//	ll lsum, rsum, tsum, msum;
//
//};
//
//vector<Building> build;
//vector<Building> Y[3001];
//
//vector<ll> arr;
//Vertex seg[4 * 3001];
//
//void Update(ll num, ll pos, ll start, ll end, ll diff) {
//
//	if (end < pos || pos < start) return;
//
//	if (start == end) {
//
//		seg[num].lsum += diff;
//		seg[num].rsum += diff;
//		seg[num].tsum += diff;
//		seg[num].msum += diff;
//		return;
//		
//	}
//
//	Update(2 * num, pos, start, (start + end) / 2, diff);
//	Update(2 * num + 1, pos, (start + end) / 2 + 1, end, diff);
//
//	Vertex &left = seg[2 * num], &right = seg[2 * num + 1];
//
//	seg[num].lsum = max(left.lsum, left.tsum + right.lsum);
//	seg[num].rsum = max(right.rsum, right.tsum + left.rsum);
//	seg[num].tsum = left.tsum + right.tsum;
//	seg[num].msum = max({left.rsum + right.lsum, left.msum, right.msum, seg[num].lsum, seg[num].rsum});
//
//}
//
//ll query(ll num, ll start, ll end, ll l, ll r) {
//
//	if (r < start || l > end) return 0;
//
//	if (l <= start && end <= r) return seg[num].msum;
//
//	return max(query(2 * num, start, (start + end) / 2, l, r),
//			   query(2 * num + 1, (start + end) / 2 + 1, end, l, r));
//
//}
//
//int main() {
//
//	int n; scanf("%d", &n);
//
//	build.resize(n + 1);
//
//	vector<int> sx, sy;
//
//	for (int i = 0; i < n; i++) {
//
//		int x, y; ll cost; 
//		scanf("%d %d %lld", &x, &y, &cost);
//
//		build[i] = { x, y, cost };
//		sx.push_back(x), sy.push_back(y);
//
//	}
//
//	sx.erase(unique(sx.begin(), sx.end()), sx.end());
//	sy.erase(unique(sy.begin(), sy.end()), sy.end());
//	sort(sx.begin(), sx.end()); sort(sy.begin(), sy.end());
//
//	int px = 0, py = 0;
//
//	for (int i = 0; i < n; i++) {
//
//		int xidx = lower_bound(sx.begin(), sx.end(), build[i].x) - sx.begin();
//		int yidx = lower_bound(sy.begin(), sy.end(), build[i].y) - sy.begin();
//
//		build[i].x = xidx, build[i].y = yidx;
//		Y[build[i].y].push_back(build[i]);
//
//	}
//
//	px = sx.size(), py = sy.size();
//
//	arr.resize(px + 1);
//
//	ll ans = -MAX;
//
//	for (int sy = 0; sy < py; sy++) {
//
//		for (int ey = sy; ey < py; ey++) {
//
//			for (Building b : Y[ey])
//				Update(1, b.x, 0, px, b.cost);
//
//			ans = max(ans, query(1, 0, px, 0, px));
//
//		}
//
//		memset(seg, 0, sizeof(seg));
//		fill(arr.begin(), arr.end(), 0);
//
//	}
//
//	printf("%lld", ans);
//
//	return 0;
//	
//}