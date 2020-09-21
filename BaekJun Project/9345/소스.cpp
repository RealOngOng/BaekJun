#include <bits/stdc++.h>

using namespace std;

struct DATA
{
	int min, max;
	DATA operator+(const DATA& data)
	{
		return { min + data.min, max + data.max };
	}
};

struct SegmentTree
{
	int n;
	vector<int> arr;
	vector<DATA> seg;
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

	DATA SetTree(int num, int s, int e)
	{
		if (s == e)
			return seg[num] = {arr[s], arr[s]};
		DATA left = SetTree(2 * num, s, (s + e) / 2);
		DATA right = SetTree(2 * num + 1, (s + e) / 2 + 1, e);
		return seg[num] = { min(left.min, right.min), max(left.max, right.max) };
	}
	void SetTree()
	{
		SetTree(1,0, n-1);
	}

	DATA update(int num, int s, int e, int idx, int value)
	{
		if (idx < s || e < idx) return seg[num];
		if (s == e)
			return seg[num] = {value, value};
		DATA left = update(2 * num, s, (s + e) / 2, idx, value);
		DATA right = update(2 * num + 1, (s + e) / 2 + 1, e, idx, value);
		return seg[num] = { min(left.min, right.min), max(left.max, right.max) };
 	}
	void update(int idx, int value)
	{
		update(1, 0, n-1, idx, value);
	}

	DATA query(int num, int s, int e, int l, int r)
	{
		if (l > e || r < s) return {0x3f3f3f3f, 0};
		if (l <= s && e <= r)return seg[num];
		DATA left = query(2*num, s, (s+e)/2, l, r);
		DATA right = query(2*num+1, (s + e) / 2 + 1, e, l, r);
		return { min(left.min, right.min), max(left.max, right.max) };
	}
	DATA query(int l, int r)
	{
		return query(1, 0, n-1, l, r);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while (tc--)
	{
		int n, m; cin >> n >> m;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			arr[i] = i;

		SegmentTree st(arr);
		st.SetTree();

		while (m--)
		{
			int cmd, a, b; cin >> cmd >> a >> b;
			if (cmd == 0)
			{
				DATA tempa = st.query(a, a);
				DATA tempb = st.query(b, b);
				st.update(a, tempb.min);
				st.update(b, tempa.min);
			}
			else
			{
				DATA q = st.query(a, b);
				if (q.min == a && q.max == b)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
	}
	return 0;
}