#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[751][751];
int dp[2][751][751];

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = dp[0][i][j] = dp[1][i][j] = str[j] - '0';
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (!dp[0][i][j]) continue;
			dp[0][i][j] = dp[0][i - 1][j - 1] + 1;
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = m-2; j >= 0; j--)
		{
			if (!dp[1][i][j]) continue;
			dp[1][i][j] = dp[1][i - 1][j + 1] + 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int radius = min({i+1, j+1, n-i, m-j});
			for (int r = radius; r >= 0; r--)
			{
				if (dp[0][i][j + r - 1] >= r && dp[1][i][j - r + 1] >= r &&
					dp[0][i + r - 1][j] >= r && dp[1][i + r - 1][j] >= r)
				{
					ans = max(ans, r);
					break;
				}
			}
		}
	}

	cout << ans;
	return 0;
}