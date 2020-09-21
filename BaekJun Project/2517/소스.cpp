#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct Segment
{
	int n;
	vector<int> seg;

	Segment(int _n)
	{
		n = _n;
		seg.resize(4 * n);
	}
	
	int Update(int num, int s, int e, int idx, int diff)
	{
		if (idx < s || e < idx) return seg[num];
		if (s == e)
			return seg[num] = diff;

		return seg[num] = 
			Update(2 * num, s, (s + e) / 2, idx, diff) + Update(2*num+1, (s+e)/2+1, e, idx, diff);
	}
	void Update(int idx, int diff)
	{
		Update(1, 0, n-1, idx, diff);
	}

	int Query(int num, int s, int e, int l, int r)
	{
		if (e < l || s > r) return 0;
		if (l <= s && e <= r)return seg[num];

		return Query(2 * num, s, (s + e) / 2, l, r) + Query(2*num+1, (s+e)/2+1, e, l, r);
	}
	int Query(int l, int r)
	{
		return Query(1, 0, n-1, l, r);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)cin >> arr[i];

	vector<int> temp(arr);
	sort(temp.begin(), temp.end());

	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
		m[temp[i]] = i;

	Segment seg(n);

	for (int i = 0; i < n; i++)
	{
		int pos = seg.Query(m[arr[i]] + 1, n) + 1;
		cout << pos << "\n";
		seg.Update(m[arr[i]], 1);
	}
	return 0;
}