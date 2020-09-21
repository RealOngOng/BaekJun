#include <bits/stdc++.h>

using namespace std;

int n;
bool arr[17][17];
int dp[17][17][3];

bool isOut(int x, int y) { return (x < 0 || y < 0 || x >= n || y >= n); }
bool check(int x, int y, int k)
{
	if (k == 0)
	{
		int nx = x, ny = y + 1;
		if (isOut(nx, ny)) return false;
		return arr[nx][ny];
	}
	else if (k == 1)
	{
		int nx = x + 1, ny = y;
		if (isOut(nx, ny)) return false;
		return arr[nx][ny];
	}
	else if (k == 2)
	{
		int dx[3] = { 1, 1, 0 };
		int dy[3] = { 0, 1, 1 };
		
		for (int i = 0; i < 3; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (isOut(nx, ny)) return false;
			if (!arr[nx][ny]) return false;
		}
		return true;
	}

	return true;
}

int solve(int x, int y, int k)
{
	if (x == n-1 && y == n-1) return 1;

	int &ret = dp[x][y][k];
	if (ret != -1) return ret;

	ret = 0;

	if (check(x, y, 2))
		ret += solve(x + 1, y + 1, 2);

	if ((k == 0 || k == 2) && check(x, y, 0))
		ret += solve(x, y + 1, 0);

	if ((k == 1 || k == 2) && check(x, y, 1))
		ret += solve(x + 1, y, 1);

	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for(int i=0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			bool a; cin >> a;
			arr[i][j] = !a;
		}

	cout << solve(0, 1, 0);
	return 0;
}