#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct SegmentTree
{
	int n;
	vector<ll> arr, seg;
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
		return seg[num] = SetTree(2 * num, s, (s + e) / 2) +
			SetTree(2 * num + 1, (s + e) / 2 + 1, e);
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
		return seg[num] = update(2 * num, s, (s + e) / 2, idx, value) +
			update(2 * num + 1, (s + e) / 2 + 1, e, idx, value);
	}
	void update(int idx, ll value)
	{
		update(1, 0, n - 1, idx, value);
	}

	ll query(int num, int s, int e, int l, int r)
	{
		if (l > e || r < s) return 0;
		if (l <= s && e <= r)
			return seg[num];
		return query(2 * num, s, (s + e) / 2, l, r)
			+ query(2 * num + 1, (s + e) / 2 + 1,e , l, r);
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

	int n, m; cin >> n >> m;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	SegmentTree st(arr);
	st.SetTree();

	for (int i = 0; i < m; i++)
	{
		int x, y, a; ll b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);

		cout << st.query(x - 1, y - 1) << "\n";
		st.update(a - 1, b);
	}

	return 0;
}