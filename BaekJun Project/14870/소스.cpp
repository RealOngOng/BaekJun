#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1501][1501];
int dp[1501][1501];
int order[1501][1501];

int dx[2] = { -1, 0 };
int dy[2] = { 0, -1 };

bool isOut(int x, int y) { return (x < 0 || y < 0 || x >= n || y >= n); }

int solve(int x, int y)
{
	int &ret = dp[x][y];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < 2; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (isOut(nx, ny)) continue;
		int v = solve(nx, ny) + arr[x][y];
		if (ret < v)
		{
			ret = v;
			order[x][y] = i;
		}
	}

	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	dp[0][0] = arr[0][0];
	solve(n - 1, n - 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << order[i][j] << " ";
		cout << "\n";
	}

	return 0;
}