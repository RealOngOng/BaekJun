//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//vector<ll> mer;
//
//int jump(int n) {
//
//	int cnt = 0;
//
//	while (n > 0) {
//
//		int idx = lower_bound(mer.begin(), mer.end(), n) - mer.begin();
//
//		if (mer[idx] > n) idx--;
//
//		n -= mer[idx];
//
//		cnt += idx;
//
//	}
//
//	return cnt;
//
//}
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//
//	ll pw = 1;
//
//	while (pw < 1e10) {
//
//		mer.push_back(pw - 1);
//
//		pw *= 2;
//
//	}
//
//	int tc; cin >> tc;
//
//	while (tc--) {
//
//		int x, y; cin >> x >> y;
//
//		int ans = 0;
//
//		for (int p = y; p >= x; p -= (p & -p))
//			for (int q = 0; q <= 30; q++)
//				if(p - q >= x)
//					ans = max(ans, jump(p - q));
//
//		cout << ans << "\n";
//
//	}
//
//	return 0;
//
//}