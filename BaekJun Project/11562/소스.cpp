#include <bits/stdc++.h>

using namespace std;

int dst[251][251];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dst, 0x3f3f3f3f, sizeof(dst));

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		
		if (w)
			dst[a][b] = dst[b][a] = 0;
		else
		{
			dst[a][b] = 0;
			dst[b][a] = 1;
		}
	}

	for(int k=1; k <= n; k++)
		for(int i=1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);

	for (int i = 1; i <= n; i++)
		dst[i][i] = 0;

	int tc; cin >> tc;

	while (tc--)
	{
		int u, v; cin >> u >> v;

		cout << dst[u][v] << "\n";
	}
	return 0;
}