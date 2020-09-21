#include <bits/stdc++.h>

using namespace std;

struct SegmentTree
{
	int n;
	vector<int> arr, seg;
	SegmentTree(vector<int>& vec)
	{
		Init(vec);
	}

	void Init(vector<int>& vec)
	{
		n = vec.size();
		arr.resize(n);
		seg.resize(4 * n);
		for (int i = 0; i < n; i++)
			arr[i] = vec[i];
	}

	int SetTree(int num, int s, int e)
	{
		if (s == e)
			return seg[num] = arr[s];
		return seg[num] = min(SetTree(2 * num, s, (s + e) / 2), SetTree(2 * num + 1, (s + e) / 2 + 1, e));
	}
	void SetTree()
	{
		SetTree(1, 0, n - 1);
	}

	int update(int num, int s, int e, int idx, int value)
	{
		if (idx < s || e < idx) return seg[num];
		if (s == e)
			return seg[num] = value;
		return seg[num] = min(update(2 * num, s, (s + e) / 2, idx, value), 
							  update(2 * num + 1, (s + e) / 2 + 1, e, idx, value));
	}
	void update(int idx, int value)
	{
		update(1, 0, n - 1, idx, value);
	}

	int query(int num, int s, int e, int l, int r)
	{
		if (l > e || r < s) return 0x3f3f3f3f;
		if (l <= s && e <= r)
			return seg[num];
		return min(query(2*num, s, (s+e)/2, l, r), query(2*num+1, (s+e)/2+1, e, l, r));
	}
	int query(int l, int r)
	{
		return query(1, 0, n-1, l, r);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	SegmentTree st(arr);
	st.SetTree();

	int m; cin >> m;
	while (m--)
	{
		int cmd, a, b; cin >> cmd >> a >> b;
		if (cmd == 1)
			st.update(a - 1, b);
		else
			cout << st.query(a - 1, b - 1) << "\n";
	}
	return 0;
}