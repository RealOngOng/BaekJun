#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int k, n, m; cin >> k >> n >> m;
		vector<vector<int>> V(n+1, vector<int>());
		vector<int> indegree(n+1);
		vector<int> result(n + 1);
		vector<vector<bool>> visit(n+1, vector<bool>(n+1, false));

		while (m--)
		{
			int a, b; cin >> a >> b;
			V[a].push_back(b);
			indegree[b]++;
		}

		queue<int> q;
		for (int i = 1; i <= n; i++)
			if (indegree[i] == 0)
			{
				q.push(i);
				result[i] = 1;
			}

		int ans = 0;
		while (!q.empty())
		{
			int top = q.front(); q.pop();

			for (int w : V[top])
			{
				if (visit[w][result[top]])
					result[w] = max(result[w], result[top] + 1);
				else
					result[w] = max(result[w], result[top]);

				visit[w][result[top]] = true;
				ans = max(ans, result[w]);
				if (--indegree[w] == 0) q.push(w);
			}
		}

		cout << k << " " << ans << "\n";
	}
	return 0;
}