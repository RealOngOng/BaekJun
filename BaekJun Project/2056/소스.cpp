#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> V[10001];
int t[10001], result[10001], indegree[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
		int cnt; cin >> cnt;
		while (cnt--)
		{
			int a; cin >> a;
			V[a].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
		{
			q.push(i);
			result[i] = t[i];
		}

	while (!q.empty())
	{
		int top = q.front(); q.pop();

		for (int w : V[top])
		{
			result[w] = max(result[w], result[top] + t[w]);
			if (--indegree[w] == 0) q.push(w);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, result[i]);

	cout << ans;
	return 0;
}