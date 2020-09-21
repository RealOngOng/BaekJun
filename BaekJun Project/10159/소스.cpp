#include <bits/stdc++.h>

using namespace std;

bool dst[101][101];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		dst[a][b] = true;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dst[i][j] = max(dst[i][j], (dst[i][k] && dst[k][j]));

	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			sum += max(dst[i][j], dst[j][i]);
		}

		cout << n - sum-1 << "\n";
	}
	return 0;
}