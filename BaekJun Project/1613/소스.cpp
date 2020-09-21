#include <bits/stdc++.h>

using namespace std;

bool dst[401][401];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b; cin >> a >> b;
		dst[a][b] = true;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dst[i][k] && dst[k][j])
					dst[i][j] = true;

	int s; cin >> s;
	while (s--)
	{
		int a, b; cin >> a >> b;
		if (dst[a][b]) cout << "-1\n";
		else if (dst[b][a]) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}