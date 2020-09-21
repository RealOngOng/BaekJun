#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;
vector<ll> arr;

bool F(ll x) {

	ll cnt = 0;
	for (ll w : arr) {
		cnt += x / w;
		if (cnt >= m) return true;
	}

	return false;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	ll lo = 0, hi = 1e18;

	while (lo <= hi) {

		ll mid = (lo + hi) / 2;

		if (F(mid)) hi = mid - 1;
		else lo = mid + 1;

	}

	cout << lo;;

	return 0;

}