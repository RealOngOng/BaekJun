#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

vector<pi> arr;
ll tdp[100001], ddp[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;

	vector<int> st, sd;

	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		st.push_back(arr[i].first);
		sd.push_back(arr[i].second);
	}

	sort(arr.begin(), arr.end());
	sort(st.begin(), st.end());
	sort(sd.begin(), sd.end());

	st.erase(unique(st.begin(), st.end()), st.end());
	sd.erase(unique(sd.begin(), sd.end()), sd.end());

	ll ans = 0;
	for (pi& p : arr)
	{
		ll len = abs(p.first - p.second) + m;
		int tidx = lower_bound(st.begin(), st.end(), p.first) - st.begin();
		int didx = lower_bound(sd.begin(), sd.end(), p.second) - sd.begin();

		ll t = tdp[tidx], d = ddp[didx];
		tdp[tidx] = max(t, d + len);
		ddp[didx] = max(d, t + len);

		ans = max({ans, tdp[tidx], ddp[didx]});
	}

	cout << ans;
	return 0;
}