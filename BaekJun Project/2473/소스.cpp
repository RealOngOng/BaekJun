//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//
//	int n; cin >> n;
//	
//	vector<ll> arr(n);
//	for (int i = 0; i < n; i++) cin >> arr[i];
//
//	ll v = LLONG_MAX;
//	ll a = 0, b = 0, c = 0;
//
//	sort(arr.begin(), arr.end());
//
//	for (int i = 0; i < n; i++){
//
//		ll l = arr[i];
//
//		for (int j = i+2; j < n; j++) {
//
//			ll r = arr[j];
//
//			ll sum = l + r;
//
//			int idx = lower_bound(arr.begin() + i + 1, arr.begin() + j - 1, -sum) - arr.begin();
//
//			ll now = abs(sum + arr[idx]);
//
//			if (idx == i + 1) {
//				if (now < v) {
//
//					a = l;
//					b = r;
//					c = arr[idx];
//					v = now;
//
//				}
//			}
//			else {
//
//				ll prev = abs(sum + arr[idx - 1]);
//
//				if (now < prev) {
//					if (now < v) {
//
//						a = l;
//						b = r;
//						c = arr[idx];
//						v = now;
//
//					}
//				}
//				else {
//					if (prev < v) {
//
//						a = l;
//						b = r;
//						c = arr[idx - 1];
//						v = prev;
//
//					}
//				}
//
//			}
//
//		}
//	}
//
//	vector<ll> ans = { a, b, c };
//	sort(ans.begin(), ans.end());
//
//	for (ll w : ans)
//		cout << w << " ";
//
//	return 0;
//
//}