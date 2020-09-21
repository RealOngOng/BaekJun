//#include <bits/stdc++.h>
//
//#define INF 1e7
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//
//	int tc; cin >> tc;
//
//	while (tc--) {
//
//		int n, m; cin >> n >> m;
//
//		vector<vector<ll>> V(n + 1, vector<ll>(n + 1, INF));
//		for (int i = 1; i <= n; i++) V[i][i] = 0;
//		for (int i = 0; i < m; i++) {
//
//			ll a, b, c; cin >> a >> b >> c;
//			V[a][b] = c;
//			V[b][a] = c;
//
//		}
//
//		int k; cin >> k;
//		vector<int> person(k);
//		for (int i = 0; i < k; i++) cin >> person[i];
//
//		for (int k = 1; k <= n; k++)
//			for (int i = 1; i <= n; i++)
//				for (int j = 1; j <= n; j++)
//					if (V[i][j] > V[i][k] + V[k][j]) {
//
//						V[i][j] = V[i][k] + V[k][j];
//						V[j][i] = V[i][j];
//
//					}
//
//		ll cost = INF;
//		int ans = 1;
//
//		for (int i = 1; i <= n; i++) {
//
//			ll dst = 0;
//
//			for (int w : person)
//				dst += V[w][i];
//
//			if (cost > dst) {
//
//				cost = dst;
//				ans = i;
//
//			}
//
//		}
//
//		cout << ans << "\n";
//
//	}
//
//	return 0;
//
//}