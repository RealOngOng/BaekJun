#include <bits/stdc++.h>

using namespace std;

int dst[101][101];
int order[101][101];

int main()
{
	memset(dst, 0x3f3f3f3f, sizeof(dst));

	int n, m; cin >> n >> m;

	while (m--)
	{
		int a, b, w; cin >> a >> b >> w;
		dst[a][b] = min(dst[a][b], w);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (dst[i][j] > dst[i][k] + dst[k][j])
				{
					dst[i][j] = dst[i][k] + dst[k][j];
					order[i][j] = k;
				}
			}

	for (int i = 1; i <= n; i++)
		dst[i][i] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << ((dst[i][j] == 0x3f3f3f3f || i == j) ? 0 : dst[i][j]) << " ";
		cout << "\n";
	}

	function<void(vector<int>&, int, int)> solve = [&](vector<int>& vec, int s, int e) -> void
	{
		int k = order[s][e];
		if (k == 0) return;

		solve(vec, s, k);
		vec.push_back(k);
		solve(vec, k, e);
	};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j || dst[i][j] == 0x3f3f3f3f)
			{
				cout << "0\n";
				continue;
			}
			vector<int> ans;
			ans.push_back(i);
			solve(ans, i, j);
			ans.push_back(j);

			cout << ans.size() << " ";
			for (int w : ans)
				cout << w << " ";
			cout << "\n";
		}
	}
	return 0;
}