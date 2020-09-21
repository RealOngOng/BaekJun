#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Fenwick
{
	int n;
	vector<ll> tree;
	Fenwick(vector<ll>& vec)
	{
		Init(vec);
	}

	void Init(vector<ll>& vec)
	{
		n = vec.size();
		tree.resize(n+1);
		for (int i = 1; i <= n; i++)
			update(i, vec[i-1]);
	}

	void update(int idx, ll diff)
	{
		while (idx < tree.size())
		{
			tree[idx] += diff;
			idx += (idx & -idx);
		}
	}

	ll query(int idx)
	{
		ll ret = 0;
		while (idx > 0)
		{
			ret += tree[idx];
			idx -= (idx & -idx);
		}
		return ret;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, m, k; cin >> n >> m >> k;
	m += k;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	Fenwick fw(arr);

	while (m--)
	{
		ll cmd, a, b; cin >> cmd>> a >> b;
		if (cmd == 1)
		{
			ll diff = b - arr[a-1];
			arr[a-1] = b;
			fw.update(a, diff);
		}
		else
			cout << fw.query(b) - fw.query(a-1) << "\n";
	}
	return 0;
}