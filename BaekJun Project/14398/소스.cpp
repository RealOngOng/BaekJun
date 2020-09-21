#include <bits/stdc++.h>

using namespace std;

int item[101];
int dst[101][101];

int main()
{
	memset(dst, 0x3f3f3f3f, sizeof(dst));

	int n, m, r; cin >> n >> m >> r;
	for (int i = 0; i < n; i++) cin >> item[i + 1];
	while (r--)
	{
		int a, b, w; cin >> a >> b >> w;
		dst[a][b] = dst[b][a] = w;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int sum = item[i];
		for (int j = 1; j <= n; j++)
		{
			if (i == j || dst[i][j] > m) continue;
			sum += item[j];
		}

		ans = max(ans, sum);
	}

	cout << ans;
	return 0;
}