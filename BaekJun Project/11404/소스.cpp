#include <bits/stdc++.h>

using namespace std;

int dst[102][102];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dst[i][j] = 0x3f3f3f3f;

	for (int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		dst[a][b] = min(dst[a][b], w);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if(dst[i][k] != 0x3f3f3f3f && dst[k][j] != 0x3f3f3f3f)
					dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << ((dst[i][j] == 0x3f3f3f3f || i == j) ? 0 : dst[i][j]) << " ";
		cout << "\n";
	}
	return 0;
}