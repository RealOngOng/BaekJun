//#include <bits/stdc++.h>
//
//using namespace std;
//
//int dx[4] = { 1,0 ,-1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//
//	int tc; cin >> tc;
//	while (tc--) {
//
//		int m, n; cin >> m >> n;
//		vector<vector<int>> field(n, vector<int>(m, -1));
//		vector<vector<int>> V(n * m + 1, vector<int>());
//		int idx = 1;
//		for (int i = 0; i < n; i++) {
//
//			string str; cin >> str;
//			for (int j = 0; j < m; j++)
//				if (str[j] == '.')
//					field[i][j] = idx++;
//
//		}
//
//		function<bool(int, int)> isOut = [&](int x, int y) -> bool {
//			return (x < 0 || y < 0 || x >= n || y >= n);
//		};
//
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < m; j++) {
//
//				if (field[i][j] == -1) continue;
//
//				for (int k = 0; k < 4; k++) {
//					int nx = i + dx[k], ny = j + dy[k];
//					if (isOut(nx, ny) || field[nx][ny] == -1) continue;
//					V[field[i][j]].push_back(field[nx][ny]);
//				}
//			}
//
//		vector<bool> visit(n * m + 1);
//		vector<vector<int>> adj(n * m + 1, vector<int>());
//		function<void(int, int)> SetTree = [&](int x, int parent) -> void {
//			visit[x] = true;
//			for (int w : V[x]) {
//				if (visit[w] || w == parent) continue;
//				adj[x].push_back(w);
//				SetTree(w, x);
//			}
//		};
//		SetTree(1, -1);
//
//		int ans = 0;
//
//		vector<vector<int>> cost(n * m + 1, vector<int>());
//		function<int(int)> dfs = [&](int x) -> int {
//
//			int ret = 0;
//
//			for (int w : adj[x]) {
//				int a = dfs(w) + 1;
//				cost[x].push_back(a);
//				ret = max(ret, a);
//			}
//
//			ans = max(ans, ret);
//
//			return ret;
//
//		};
//
//		dfs(1);
//
//		visit.clear();
//		visit.resize(n * m + 1);
//		function<void(int, int)> solve = [&](int x, int sum) -> void {
//
//			visit[x] = true;
//
//			sort(cost[x].begin(), cost[x].end(), greater<int>());
//
//			if (cost[x].size() == 1)
//				ans = max(ans, cost[x][0]);
//			else
//				ans = max({ ans, cost[x][0] + cost[x][1],
//						  sum + cost[x][0], sum + cost[x][1] });
//
//			for (int w : adj[x])
//				solve(w, sum + 1);
//
//		};
//
//		cout << "Maximum rope length is " << ans << ".\n";
//
//	}
//
//	return 0;
//
//}