#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
int arr[1001][1001];
int dp[1001][1001][3];

bool isOut(int x, int y) { return (x < 0 || y < 0 || x >= n || y >= m); }

int solve(int x, int y, int k)
{
	if (x == n - 1 && y == m - 1) 
		return arr[n - 1][m - 1];

	if (isOut(x, y)) 
		return -INF;

	int &ret = dp[x][y][k];
	if (ret != -INF) return ret;

	ret = max(ret, solve(x + 1, y, 0) + arr[x][y]);

	if(k == 0 || k == 1)
		ret = max(ret, solve(x, y - 1, 1) + arr[x][y]);
	if(k == 0 || k == 2)
		ret = max(ret, solve(x, y + 1, 2) + arr[x][y]);

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			for (int k = 0; k < 3; k++)
				dp[i][j][k] = -INF;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	cout << solve(0, 0, 0);
	return 0;
}