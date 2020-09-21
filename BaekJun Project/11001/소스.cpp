#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, d;
ll T[100001], V[100001];
ll ans = 0;

ll cost(ll a, ll b) { return (b - a) * T[b] + V[a]; }

void dnc(ll s, ll e, ll l, ll r) {

	if (s > e) return;

	//k < mid
	ll mid = (s + e) / 2;
	ll k = max(l, mid - d);

	for (ll i = k; i <= min(mid, r); i++) {
		ll v = cost(l, i);
		if (cost(k, mid) < cost(i, mid)) k = i;
	}

	ans = max(ans, cost(k, mid));

	dnc(s, mid-1, l, k);
	dnc(mid+1, e, k, r);

}

int main() {

	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> T[i];
	for (int i = 1; i <= n; i++) cin >> V[i];

	dnc(1, n, 1, n);

	cout << ans;

	return 0;

}