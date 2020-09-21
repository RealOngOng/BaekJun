#include <bits/stdc++.h>

using namespace std;

struct Line
{
	int to, cost;
};

int n, m, k;
vector<Line> V[301];
int dp[301][301];

int solve(int pos, int cnt)
{
	if (cnt > m) return -0x3f3f3f3f;
	if (pos == n) return 0;

	int &ret = dp[pos][cnt];
	if (ret != -1) return ret;

	for (Line w : V[pos])
		ret = max(ret, solve(w.to, cnt + 1) + w.cost);

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int from, to, cost; cin >> from >> to >> cost;
		if (from > to) continue;
		
		V[from].push_back({to, cost});
	}

	cout << solve(1, 1);
	return 0;
}