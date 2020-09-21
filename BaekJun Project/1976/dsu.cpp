//#include <bits/stdc++.h>
//
//using namespace std;
//
//int p[201];
//
//int find(int a) {
//
//	if (p[a] < 0) return a;
//	return p[a] = find(p[a]);
//
//}
//
//void merge(int a, int b) {
//
//	a = find(a), b = find(b);
//
//	if (a != b) p[a] = b;
//
//}
//
//int main()
//{
//
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//
//	memset(p, -1, sizeof(p));
//
//	int n, m; cin >> n >> m;
//
//	for(int i=0; i < n; i++)
//		for (int j = 0; j < n; j++) {
//
//			int a; cin >> a;
//			if (a)
//				merge(i, j);
//
//		}
//
//	bool ans = true;
//
//	int d; cin >> d;
//
//	int top = find(d - 1);
//
//	for (int i = 0; i < m - 1; i++) {
//
//		cin >> d;
//		if (find(d - 1) != top)
//			ans = false;
//
//	}
//
//	cout << ((ans) ? "YES" : "NO");
//	
//	return 0;
//
//}