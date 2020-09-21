#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<ll> arr;

ll f(ll mid)
{
	ll ans = 0;

	for (int i = 0; i < n; i++)
		ans += abs(arr[i] - mid * i);

	return ans;
}

int main()
{
	cin >> n;
	arr.resize(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	ll lo = 0, hi = 1e9;
	while (hi - lo >= 3)
	{
		ll p = (2 * lo + hi) / 3, q = (lo + 2 * hi) / 3;
		if (f(p) <= f(q)) hi = q;
		else lo = p;
	}

	ll ans = 1e18;
	for (ll i = lo; i <= hi; i++)
		ans = min(ans, f(i));

	cout << ans;
	
	return 0;
}