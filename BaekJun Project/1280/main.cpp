#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

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


};

int main()
{
	return 0;
}