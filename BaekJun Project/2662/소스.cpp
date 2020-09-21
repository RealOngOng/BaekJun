#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, m;
int dp[21][301];
pi order[21][301];
int cost[21][301];

int solve(int pos, int money)
{
	if (pos == m)
	{
		if (money == n) return 0;
		else return -0x3f3f3f3f;
	}

	int &ret = dp[pos][money];
	if (ret != -1) return ret;

	for (int i = 0; money + i <= n; i++)
	{
		int v = solve(pos + 1, money + i) + cost[pos][i];
		if (v > ret)
		{
			ret = v;
			order[pos][money] = { pos + 1, money + i };
		}
	}

	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i <= 20; i++)
		for (int j = 0; j <= 300; j++)
			order[i][j] = { -1, -1 };

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int idx; cin >> idx;
		for (int j = 0; j < m; j++)
			cin >> cost[j][idx];
	}

	cout << solve(0, 0) << "\n";

	pi top = order[0][0];
	int c = 0;
	while (true)
	{
		cout << top.second - c << " ";
		c = top.second;
		top = order[top.first][top.second];
		if (top.first == -1) break;
	}

	return 0;
}