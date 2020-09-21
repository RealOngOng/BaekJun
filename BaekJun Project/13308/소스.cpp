//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//typedef pair<int, int> pi;
//
//vector<int> V[2501];
//int liter[2501];
//int len[2501][2501];
//int dst[2501][2501];
////a ~ b로 가는데 최소 비용
//int dp[2501][2501];
//
//int n, m;
//
//void diijkstra(int start) {
//
//	priority_queue<pi> pq;
//
//	pq.push({start, 0});
//	dst[start][start] = 0;
//
//	while (!pq.empty()) {
//
//		pi top = pq.top(); pq.pop();
//
//		for (int w : V[top.first]) {
//
//			if (top.second + len[top.first][w] < dst[start][w]) {
//
//				dst[start][w] = top.second + len[top.first][w];
//				pq.push({w, top.second + len[top.first][w]});
//
//			}
//
//		}
//
//	}
//
//}
//
//int solve(int a, int b) {
//
//	int &ret = dp[a][b];
//
//	if (ret != 0x3f3f3f3f) return ret;
//	if (a == b) return 0;
//
//	for (int i = a; i <= n; i++) {
//
//		if (i == a) continue;
//		ret = min(ret, solve(i, b) + dst[a][i]);
//
//	}
//
//	return ret;
//
//}
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//
//	memset(len, 0x3f3f3f3f, sizeof(len));
//	memset(dp, 0x3f3f3f3f, sizeof(dp));
//	memset(dst, 0x3f3f3f3f, sizeof(dst));
//
//	cin >> n >> m;
//
//	for (int i = 1; i <= n; i++)
//		cin >> liter[i];
//
//	for (int i = 1; i <= m; i++) {
//
//		int a, b, c; cin >> a >> b >> c;
//		
//		len[a][b] = c;
//		len[b][a] = c;
//
//		V[a].push_back(b);
//		V[b].push_back(a);
//
//	}
//
//	for (int i = 1; i <= n; i++)
//		diijkstra(i);
//
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			dst[i][j] *= liter[i];
//
//	cout << solve(1, n);
//
//	return 0;
//
//}