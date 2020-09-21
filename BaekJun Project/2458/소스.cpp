#include <bits/stdc++.h>

using namespace std;

bool dst[501][501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	while (m--)
	{
		int a, b; cin >> a >> b;
		dst[a][b] = true;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dst[i][j] = max(dst[i][j], (dst[i][k] && dst[k][j]));

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (dst[i][j]) sum += dst[i][j];
			if (dst[j][i]) sum += dst[j][i];
		}

		ans += (sum == n-1);
	}

	cout << ans;
	return 0;
}