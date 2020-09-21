#include <bits/stdc++.h>

using namespace std;

int dst[401][401];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dst, 0x3f3f3f3f, sizeof(dst));

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		dst[a][b] = min(dst[a][b], w);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);

	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
		ans = min(ans, dst[i][i]);

	if (ans == 0x3f3f3f3f) cout << "-1";
	else cout << ans;

	return 0;
}