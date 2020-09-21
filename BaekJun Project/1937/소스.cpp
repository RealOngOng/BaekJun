//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef pair<int, int> pi;
//
//int n;
//
//int arr[250001];
//int dp[250001];
//
//int dx[4] = { 0, 1, 0, -1 };
//int dy[4] = { 1, 0, -1, 0 };
//
//bool isOut(pi p) { return (p.first < 0 || p.second < 0 || p.first >= n || p.second >= n); }
//
//pi IdxToPi(int idx) { return {idx / n, idx % n}; }
//
//int PiToIdx(pi p) { return p.first * n + p.second; }
//
//vector<int> nearIdx(int idx) {
//
//	pi center = IdxToPi(idx);
//
//	vector<int> result;
//
//	for (int i = 0; i < 4; i++) {
//
//		pi front = { center.first + dx[i], center.second + dy[i] };
//		
//		if (isOut(front)) continue;
//
//		result.push_back(PiToIdx(front));
//		
//	}
//
//	return result;
//
//}
//
//int solve(int i) {
//
//	vector<int> near = nearIdx(i);
//
//	int &ret = dp[i];
//
//	if (ret > 1) return ret;
//
//	ret = 1;
//
//	for (int w : near) {
//
//		if (arr[w] > arr[i])
//			ret = max(ret, solve(w) + 1);
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
//	cin >> n;
//
//	for (int i = 0; i < n * n; i++)
//		cin >> arr[i];
//
//	int ans = 0;
//
//	for (int i = 0; i < n * n; i++)
//		ans = max(ans, solve(i));
//
//	cout << ans;
//
//	return 0;
//
//}