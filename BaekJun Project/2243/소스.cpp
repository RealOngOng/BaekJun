#include <bits/stdc++.h>

using namespace std;

struct Seg
{
	int n = 1000001;
	vector<int> arr, seg;

	void Init()
	{
		arr.resize(n + 1);
		seg.resize(4 * (n + 1));
	}

	int SetTree(int num, int s, int e)
	{
		if (s == e)
			return seg[num] = arr[s];
		return seg[num] = SetTree(2 * num, s, (s + e) / 2) + SetTree(2 * num + 1, (s + e) / 2 + 1, e);
	}
	void SetTree()
	{
		SetTree(1, 0, n);
	}

	int update(int num, int s, int e, int idx, int diff)
	{
		if (idx < s || e < idx) return seg[num];
		if (s == e)
			return seg[num] += diff;
		return seg[num] = update(2 * num, s, (s + e) / 2, idx, diff) +
			update(2*num+1, (s+e)/2+1, e, idx, diff);
	}
	void update(int idx, int diff)
	{
		update(1, 0, n, idx, diff);
	}

	int query(int num, int s, int e, int k)
	{
		if (s == e)
			return s;

		if (k <= seg[2 * num])
			return query(2 * num, s, (s + e) / 2, k);
		else
			return query(2 * num + 1, (s + e) / 2 + 1, e, k - seg[2 * num]);
	}
	int query(int k)
	{
		return query(1, 0, n, k);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	Seg seg;
	seg.Init();
	seg.SetTree();

	int n; cin >> n;
	while (n--)
	{
		int cmd; cin >> cmd;
		if (cmd == 1)
		{
			int a; cin >> a;
			int f = seg.query(a);
			cout << f + 1 << "\n";
			seg.update(f, -1);
		}
		else
		{
			int a, b; cin >> a >> b;
			seg.update(a - 1, b);
		}
	}

	return 0;
}