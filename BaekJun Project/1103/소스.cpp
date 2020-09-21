#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, m;
vector<pi> V[51][51];
int arr[51][51];
int dp[51][51];

bool visit[51][51];
bool finished[51][51];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isOut(int x, int y) { return (x < 0 || y < 0 || x >= n || y >= m); }

int solve(int x, int y)
{
	if (arr[x][y] == -1) 
		return 0;

	int &ret = dp[x][y];
	if (ret != -1) return ret;

	ret = 1;
	for (pi& w : V[x][y])
		ret = max(ret, solve(w.first, w.second) + 1);

	return ret;
}

bool isCycle(int x, int y)
{
	visit[x][y] = true;

	bool result = false;
	for (pi& p : V[x][y])
	{
		if (visit[p.first][p.second])
		{
			if (!finished[p.first][p.second])
				return true;
		}
		else
			result = max(result, isCycle(p.first, p.second));
	}

	finished[x][y] = true;

	return result;
}

int main()
{
	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		for (int j = 0; j < m; j++)
		{
			if (str[j] == 'H') arr[i][j] = -1;
			else arr[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int d = arr[i][j];
			if (d == -1) continue;
			for (int k = 0; k < 4; k++)
			{
				pi front = { i + dx[k] * d, j + dy[k] * d };
				if (isOut(front.first, front.second)) continue;
				V[i][j].push_back(front);
			}
		}
	}

	if (isCycle(0, 0))
		cout << "-1\n";
	else
		cout << solve(0, 0);

	return 0;
}