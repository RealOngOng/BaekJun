#include <bits/stdc++.h>

using namespace std;

int main()
{

	int n, m; cin >> n >> m;
	
	vector<int> V1[100];
	vector<int> V2[100];
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		V1[u].push_back(v);
		V2[v].push_back(u);
	}

	bitset<101> visit1, visit2;
	function<int(int)> dfs1 = [&](int x) -> int
	{
		visit1[x] = true;
		int ret = 1;
		for (int w : V1[x])
		{
			if (visit1[w]) continue;
			ret += dfs1(w);
		}

		return ret;
	};
	function<int(int)> dfs2 = [&](int x) -> int
	{
		visit2[x] = true;
		int ret = 1;
		for (int w : V2[x])
		{
			if (visit2[w]) continue;
			ret += dfs2(w);
		}

		return ret;
	};
	
	int mid = (n + 1) / 2;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		visit1.reset(); visit2.reset();
		int cnt1 = dfs1(i) - 1;
		int cnt2 = dfs2(i) - 1;
		if (cnt1 >= mid || cnt2 >= mid)
			ans++;
	} 

	cout << ans;

	return 0;

}