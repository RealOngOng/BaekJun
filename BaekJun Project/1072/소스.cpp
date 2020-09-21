#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	ll x, y; cin >> x >> y;
	ll z = y * 100LL / x + 1LL;

	if (z == 100LL || z == 101LL) {

		cout << "-1\n";
		return 0;

	}

	ll lo = 1, hi = 1e9 + 1;

	ll ans = 0;
	while (lo <= hi) {

		ll mid = (lo + hi) / 2LL;

		ll v = (y + mid) * 100LL / (x + mid);

		if (z <= v) hi = mid - 1, ans = mid;
		else lo = mid + 1;

	}

	cout << ans;

	return 0;

}