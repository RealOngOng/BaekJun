#include <bits/stdc++.h>

using namespace std;

int dp[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while (true)
	{
		memset(dp, 0, sizeof(dp));
		int n; double m; cin >> n >> m;
		int cost = int(m * 100 + 0.5);

		if (n == 0 && m == 0.0) break;

		for (int i = 0; i < n; i++)
		{
			int a; double _b; cin >> a >> _b;
			int b = int(_b * 100 + 0.5);

			for (int j = b; j <= cost; j++)
				dp[j] = max(dp[j], dp[j - b] + a);
		}

		cout << dp[cost] << "\n";
	}
	return 0;
}