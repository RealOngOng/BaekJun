#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

struct Segment
{
	ll n;
	vector<ll> arr;
	vector<ll> seg;

	Segment(vector<ll>& vec)
	{
		Init(vec);
	}

	void Init(vector<ll>& vec)
	{
		n = vec.size();
		arr.resize(n);
		seg.resize(4 * n);

		for (ll i = 0; i < n; i++)
			arr[i] = vec[i];
	}

	ll SetTree(ll num, ll s, ll e)
	{
		if (s == e)
			return seg[num] = arr[s];

		return seg[num] =
			SetTree(2 * num, s, (s + e) / 2) + SetTree(2 * num + 1, (s + e) / 2 + 1, e);
	}
	void SetTree()
	{
		SetTree(1, 0, n - 1);
	}

	ll Update(ll num, ll s, ll e, ll idx, ll diff)
	{
		if (idx < s || e < idx) return seg[num];
		if (s == e)
			return seg[num] = diff;

		return seg[num] =
			Update(2 * num, s, (s + e) / 2, idx, diff) + Update(2 * num + 1, (s + e) / 2 + 1, e, idx, diff);
	}
	void Update(ll idx, ll diff)
	{
		Update(1, 0, n - 1, idx, diff);
	}

	ll Query(ll num, ll s, ll e, ll l, ll r)
	{
		if (r < s || e < l) return 0;
		if (l <= s && e <= r) return seg[num];

		return Query(2 * num, s, (s + e) / 2, l, r) + Query(2 * num + 1, (s + e) / 2 + 1, e, l, r);
	}
	ll Query(ll l, ll r)
	{
		return Query(1, 0, n - 1, l, r);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n; cin >> n;
	vector<ll> A(n);
	unordered_map<ll, ll> B;
	for (ll i = 0; i < n; i++) cin >> A[i];
	for (ll i = 0; i < n; i++)
	{
		ll a; cin >> a;
		B[a] = i;
	}

	for (ll i = 0; i < n; i++) A[i] = B[A[i]];

	vector<ll> arr(n + 1, 0);
	Segment seg(arr);
	seg.SetTree();

	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		seg.Update(A[i] - 1, 1);
		ans += seg.Query(A[i], n + 1);
	}

	cout << ans;
	return 0;
}