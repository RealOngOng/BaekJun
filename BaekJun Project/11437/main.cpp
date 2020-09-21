//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <utility>
//#include <math.h>
//#include <cstring>
//
//#define MAX 110000
//#define LOG_MAX 22
//
//typedef std::pair<int, int> Vector2;
//typedef struct Node {
//
//	std::vector<int> adjust;
//
//};
//
//int n;
//
//Node node[MAX + 1];
//
//int euler[2 * MAX + 1], depth[MAX + 1];
//std::vector<int> idx[2 * MAX + 1];
//
//int power2[LOG_MAX + 1], lg2[MAX * 2 + 2];
//
//int w = 0;
//
//void dfs(int x, int pa, int l) {
//
//	depth[x] = l; euler[++w] = x;
//	idx[x].push_back(w);
//
//	for (int e : node[x].adjust)
//		if (e != pa) {
//
//			dfs(e, x, l + 1);
//			euler[++w] = x;
//			idx[x].push_back(w);
//
//		}
//
//}
//
//Vector2 table[LOG_MAX + 1][MAX * 2 + 1];
//
//void SetMathTable() {
//
//	power2[0] = 1;
//	for (int i = 1; i < LOG_MAX; i++) power2[i] = power2[i - 1] * 2;
//
//	memset(lg2, -1, sizeof lg2);
//	for (int k = 0; k < LOG_MAX; k++) if (power2[k] < MAX * 2) lg2[power2[k]] = k;
//	for (int i = 1; i <= MAX * 2 + 1; i++) if (lg2[i] == -1) lg2[i] = lg2[i - 1];
//
//}
//
//void SetTable() {
//
//	int size = 2 * n - 1;
//	int lg = lg2[size];
//
//	for (int i = 1; i <= size; i++) table[0][i] = { depth[euler[i]], euler[i] };
//
//	for (int j = 1; j < LOG_MAX; j++)
//		for (int i = 1; i <= size - power2[j]; i++)
//			table[j][i] = std::min(table[j - 1][i], table[j - 1][i + power2[j - 1]]);
//
//}
//
//int LCA(int l, int r) {
//
//	l = idx[l][0], r = idx[r][0];
//
//	if (l > r) std::swap(l, r);
//
//	int j = lg2[r - l + 1];
//
//	return std::min(table[j][l], table[j][r - power2[j] + 1]).second;
//
//}
//
//int main() {
//
//	std::ios::sync_with_stdio(false);
//	std::cout.tie(NULL), std::cin.tie(NULL);
//
//	std::cin >> n;
//	for (int i = 1; i <= n - 1; i++) {
//
//		int a, b; std::cin >> a >> b;
//
//		node[a].adjust.push_back(b);
//		node[b].adjust.push_back(a);
//
//	}
//
//	dfs(1, -1, 0);
//
//	//PrintEuler();
//
//	SetMathTable();
//
//	SetTable();
//
//	int m; std::cin >> m;
//
//	while (m--) {
//
//		int a, b; std::cin >> a >> b;
//
//		std::cout << LCA(a, b) << "\n";
//
//	}
//
//	return 0;
//
//}
