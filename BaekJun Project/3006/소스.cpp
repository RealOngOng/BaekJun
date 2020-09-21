#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

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
		return seg[num] = SetTree(2 * num, s, (s + e) / 2) +
			SetTree(2 * num + 1, (s + e) / 2 + 1, e);
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
		return seg[num] = update(2 * num, s, (s + e) / 2, idx, value) +
			update(2 * num + 1, (s + e) / 2 + 1, e, idx, value);
	}
	void update(int idx, int value)
	{
		update(1, 0, n - 1, idx, value);
	}

	int query(int num, int s, int e, int l, int r)
	{
		if (l > e || r < s) return 0;
		if (l <= s && e <= r) return seg[num];
		return query(2 * num, s, (s + e) / 2, l, r) + query(2 * num + 1, (s + e) / 2 + 1, e, l, r);
	}
	int query(int l, int r)
	{
		return query(1, 0, n - 1, l, r);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> arr(n);
	vector<pi> order(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		order[i] = { arr[i], i };
	}

	sort(order.begin(), order.end());
	
	queue<int> q;
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		q.push(order[i].second);
		if(i != n - i - 1)
			q.push(order[n - i - 1].second);
	}

	vector<int> vec(n, 1);
	SegmentTree st(vec);
	st.SetTree();

	int num = 0;
	while (!q.empty())
	{
		int top = q.front(); q.pop();

		if (num % 2 == 0)
		{
			//cout << top << " " << l << "\n";
			cout << st.query(0, top - 1) << "\n";
			st.update(top, 0);
		}
		else
		{
			//cout << top << " " << r << "\n";
			cout << st.query(top + 1, n - 1) << "\n";
			st.update(top, 0);
		}
		num++;
	}

	return 0;
}