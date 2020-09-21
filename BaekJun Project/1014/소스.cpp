#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[11][1 << 10];
bool field[11][11];

void dfs(int, int, int, int, int);

int solve(int line, int state)
{
	if (line == n) return 0;

	int &ret = dp[line][state];
	if (ret != -1) return ret;

	ret = 0;
	dfs(line, state, 0, 0, 0);

	return ret;
}

void dfs(int line, int prevState, int pos, int cnt, int state)
{
	if (pos >= m) return;

	int &ret = dp[line][prevState];
	if (!field[line][pos])
	{
		ret = max(ret, solve(line + 1, state) + cnt);
		dfs(line, prevState, pos + 1, cnt, state);
		return;
	}

	ret = max(ret, solve(line + 1, state) + cnt);
	dfs(line, prevState, pos + 1, cnt, state);

	int l = max(0, pos - 1);
	int r = min(m - 1, pos + 1);

	bool isOk = true;
	if (pos != l)
		if (prevState & (1 << l))
			isOk = false;

	if (pos != r)
		if (prevState & (1 << r))
			isOk = false;

	if (!isOk) return;

	cnt++;
	state |= (1 << pos);
	ret = max(ret, solve(line + 1, state) + cnt);
	dfs(line, prevState, pos + 2, cnt, state);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while (tc--)
	{
		memset(dp, -1, sizeof(dp));
		memset(field, false, sizeof(field));
		cin >> n >> m;

		for(int i=0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				char a; cin >> a;
				field[i][j] = (a == '.');
			}

		cout << solve(0, 0) << "\n";
	}
	return 0;
}