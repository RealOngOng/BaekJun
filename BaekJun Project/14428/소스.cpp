#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> value;

int minValue(int a, int b)
{
	if (a == -1) return b;
	if (b == -1) return a;

	if (value[a] == value[b]) return min(a, b);
	return (value[a] <= value[b]) ? a : b;
}

struct Segment
{
	int n;
	vector<int> seg;

	Segment(int _n)
	{
		Init(_n);
	}

	void Init(int _n)
	{
		n = _n;
		seg.resize(4 * n+1);
	}

	int SetTree(int num, int s, int e)
	{
		if (s == e)
			return seg[num] = s;

		return seg[num] = 
			minValue(SetTree(2 * num, s, (s + e) / 2), SetTree(2 * num + 1, (s + e) / 2 + 1, e));
	}
	void SetTree() { SetTree(1, 1, n); }

	int Update(int num, int s, int e, int idx)
	{
		if (idx < s || e < idx) return seg[num];
		if (s == e)
			return seg[num];

		return seg[num] =
			minValue(Update(2 * num, s, (s + e) / 2, idx), 
					 Update(2 * num + 1, (s + e) / 2 + 1, e, idx));
	}
	void Update(int idx, int diff)
	{
		Update(1, 1, n, idx);
	}

	int Query(int num, int s, int e, int l, int r)
	{
		if (e < l || r < s) return -1;
		if (l <= s && e <= r) return seg[num];

		return minValue(Query(2 * num, s, (s + e) / 2, l , r),
					 Query(2 * num + 1, (s + e) / 2 + 1, e, l, r));
	}
	int Query(int l, int r)
	{
		return Query(1, 1, n, l, r);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	value.resize(n+1);
	for (int i = 1; i <= n; i++)
		cin >> value[i];

	Segment seg(n);
	seg.SetTree();

	int m; cin >> m;
	while (m--)
	{
		int cmd, a, b; cin >> cmd >> a >> b;

		if (cmd == 1)
		{
			value[a] = b;
			seg.Update(a, b);
		}
		else
			cout << seg.Query(a, b) << "\n";
	}
	return 0;
}