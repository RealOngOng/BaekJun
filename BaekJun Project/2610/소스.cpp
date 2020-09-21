#include <bits/stdc++.h>

using namespace std;

int dst[101][101];

int main()
{
	memset(dst, 0x3f3f3f3f, sizeof(dst));
	for (int i = 0; i <= 100; i++)
		dst[i][i] = 0;

	vector<int> V[101];

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		dst[a][b] = dst[b][a] = 1;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);

	int cnt = 0;
	vector<vector<int>> comp;
	bitset<101> visit;
	function<void(int)> dfs = [&](int x) -> void
	{
		comp[cnt].push_back(x);
		visit[x] = true;

		for (int w : V[x])
		{
			if (visit[w]) continue;
			dfs(w);
		}
	};

	for (int i = 1; i <= n; i++)
	{
		if (visit[i]) continue;
		comp.push_back(vector<int>());
		dfs(i);
		cnt++;
	}
	
	vector<int> ans;
	cout << comp.size() << "\n";
	for (vector<int>& arr : comp)
	{
		int ret = -1;
		int v = 0x3f3f3f3f;

		for (int a : arr)
		{
			int d = 0;
			for (int b : arr)
			{
				if (a == b) continue;
				d = max(d, dst[a][b]);
			}

			if (v > d)
			{
				v = d;
				ret = a;
			}
		}

		ans.push_back(ret);
	}

	sort(ans.begin(), ans.end());
	for (int w : ans)
		cout << w << "\n";
	return 0;
}