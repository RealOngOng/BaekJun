//#include <bits/stdc++.h>
//
//using namespace std;
//
//int solve(int num) {
//
//	int cnt = 0;
//
//	string str = to_string(num);
//	for (char c : str)
//		if ((c - '0') % 3 == 0 && c != '0') cnt++;
//
//	return cnt;
//
//}
//
//int main() {
//
//	int n; cin >> n;
//
//	int ans = 0;
//
//	for (int i = 1; i <= n; i++)
//		ans += solve(i);
//
//	cout << ans;
//
//	return 0;
//
//}