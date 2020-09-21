#include <bits/stdc++.h>

using namespace std;

int n, c, k;

struct Line
{
	int to, cost, t;
};
struct Q
{
	int pos, cost, t;
};
struct cmp
{
	bool operator()(const Q& q1, const Q& q2)
	{
		return q1.t > q2.t;
	}
};

int dp[101][10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while (tc--)
	{
		cin >> n >> c >> k;
		vector<Line> V[101];
		vector<int> dst(101, 0x3f3f3f3f);
		memset(dp, 0x3f3f3f3f, sizeof(dp));

		for (int i = 0; i < k; i++)
		{
			int from, to, c, d; cin >> from >> to >> c >> d;
			V[from].push_back({to, c, d});
		}

		priority_queue<Q, vector<Q>, cmp> pq;
		pq.push({1, 0, 0});
		dp[1][0] = 0;

		while (!pq.empty())
		{
			Q top = pq.top(); pq.pop();

			if (top.pos == n)
				continue;

			for (Line w : V[top.pos])
			{
				if (top.cost + w.cost > c) continue;
				if (dp[w.to][top.cost + w.cost] > top.t + w.t)
				{
					dp[w.to][top.cost + w.cost] = top.t + w.t;
					pq.push({w.to, top.cost + w.cost, top.t + w.t});
				}
			}
		}

		int ans = 0x3f3f3f3f;
		for (int i = 0; i <= 10000; i++)
			ans = min(ans, dp[n][i]);

		if (ans == 0x3f3f3f3f)
			cout << "Poor KCM\n";
		else
			cout << ans << "\n";
	}
	return 0;
}