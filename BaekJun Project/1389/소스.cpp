#include <bits/stdc++.h>

using namespace std;

int dst[101][101];

int main()
{
	memset(dst, 0x3f3f3f3f, sizeof(dst));

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		dst[a][b] = 1;
		dst[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);

	int ans = 0;
	int v = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
			sum += dst[i][j];

		if (sum < v)
		{
			v = sum;
			ans = i;
		}
	}

	cout << ans;

	return 0;
}