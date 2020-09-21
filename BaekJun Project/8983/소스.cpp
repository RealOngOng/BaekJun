#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n, m, l; cin >> n >> m >> l;
	vector<ll> xpos(n);
	for (int i = 0; i < n; i++) cin >> xpos[i];
	sort(xpos.begin(), xpos.end());

	ll ans = 0;
	for (int i = 0; i < m; i++)
	{
		ll x, y; cin >> x >> y;
		ll idx = lower_bound(xpos.begin(), xpos.end(), x) - xpos.begin();

		if (idx > 0)
			if (abs(xpos[idx - 1] - x) < abs(xpos[idx] - x))
				idx--;

		ll dst = abs(xpos[idx] - x) + y;

		if (dst <= l) ans++;
	}

	cout << ans;
	return 0;
}