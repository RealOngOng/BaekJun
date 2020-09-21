//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n;
//
//bool adj[101][101], visit[101];
//bool result[101][101];
//
//bool dfs(int start, int end, int num) {
//
//	if (start == end && num > 0) return true;
//
//	bool ok = false;
//
//	for (int i = 1; i <= n; i++) {
//
//		if (adj[start][i] && !visit[i]) {
//
//			visit[i] = true;
//			ok = max(ok, dfs(i, end, ++num));
//
//		}
//
//	}
//
//	return ok;
//
//}
//
//int main() {
//
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			scanf("%d", &adj[i][j]);
//
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++) {
//
//			memset(visit, false, sizeof(visit));
//			result[i][j] = dfs(i, j, 0);
//
//		}
//
//	for (int i = 1; i <= n; i++) {
//
//		for (int j = 1; j <= n; j++)
//			printf("%d ", result[i][j]);
//
//		printf("\n");
//
//	}
//
//	return 0;
//
//}