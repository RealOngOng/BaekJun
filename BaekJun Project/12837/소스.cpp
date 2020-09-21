#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct SegmentTree
{
	int n;
	vector<ll> arr;
	vector<ll> seg;
	SegmentTree(vector<ll>& vec)
	{
		Init(vec);
	}

	void Init(vector<ll>& vec)
	{
		n = vec.size();
		arr.resize(n);
		seg.resize(4 * n);
		for (int i = 0; i < n; i++)
			arr[i] = vec[i];
	}

	ll SetTree(int num, int s, int e)
	{
		if (s == e)
			return seg[num] = arr[s];
		return seg[num] = SetTree(2 * num, s, (s + e) / 2)
			+ SetTree(2 * num + 1, (s + e) / 2 + 1, e);
	}
	void SetTree()
	{
		SetTree(1, 0, n - 1);
	}

	ll update(int num, int s, int e, int idx, ll value)
	{
		if (idx < s || e < idx) return seg[num];
		if (s == e)
			return seg[num] = value;
		return seg[num] = update(2 * num, s, (s + e) / 2, idx, value)
			+ update(2 * num + 1, (s + e) / 2 + 1, e, idx, value);
	}
	ll update(int idx, ll value)
	{
		return update(1, 0, n - 1, idx, value);
	}

	ll query(int num, int s, int e, int l, int r)
	{
		if (l > e || r < s) return 0;
		if (l <= s && e <= r)
			return seg[num];
		return query(2 * num, s, (s + e) / 2, l, r) +
			query(2 * num + 1, (s + e) / 2 + 1, e, l, r);
	}
	ll query(int l, int r)
	{
		return query(1, 0, n - 1, l, r);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, m; cin >> n >> m;
	vector<ll> arr(n + 1);

	SegmentTree st(arr);
	st.SetTree();

	for (int i = 0; i < m; i++)
	{
		int cmd, a, b; cin >> cmd >> a >> b;
		if (cmd == 1)
			st.update(a, st.query(a, a) + b);
		else
			cout << st.query(a, b) << "\n";
	}

	return 0;
}