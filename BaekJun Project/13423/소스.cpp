//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//
//	int tc; cin >> tc;
//
//	while (tc--) {
//
//		int n; cin >> n;
//
//		vector<int> arr(n);
//		set<int> pos;
//		
//		for (int i = 0; i < n; i++) {
//
//			cin >> arr[i];
//			pos.insert(arr[i]);
//
//		}
//
//		sort(arr.begin(), arr.end());
//
//		int ans = 0;
//
//		for (int i = 0; i < n; i++) {
//
//			for (int j = i + 1; j < n; j++) {
//
//				int sub = arr[j] - arr[i];
//
//				if (pos.find(arr[j] + sub) != pos.end()) ans++;
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