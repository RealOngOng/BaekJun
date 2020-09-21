#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Food
{
	ll flavor, spicy;
};

ll n, m;
Food food[100001];

ll maxflavor(ll x)
{
	ll ret = 0;

	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (food[i].spicy <= x)
		{
			sum += food[i].flavor;
			ret = max(ret, sum);
		}
		else
			sum = 0;
	}
	
	return ret;
}

ll binerysearch(ll lo, ll hi)
{
	if (lo >= hi) return hi;

	ll mid = (lo + hi) / 2;
	if (maxflavor(mid) >= m)
		return binerysearch(lo, mid);
	else
		return binerysearch(mid + 1, hi);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> food[i].flavor >> food[i].spicy;

	cout << binerysearch(0, 1e18);
	return 0;
}