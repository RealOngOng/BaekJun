#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;

	while (tc--)
	{
		int n, m; cin >> n >> m;
		vector<vector<int>> V(n+1, vector<int>());
		vector<int> indegree(n+1);

		vector<int> t(n+1);
		vector<int> result(n+1);

		for (int i = 1; i <= n; i++)
			cin >> t[i];
		while (m--)
		{
			int a, b; cin >> a >> b;

			V[a].push_back(b);
			indegree[b]++;
		}
		int end; cin >> end;

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

			if (indegree[end] == 0) break;

			for (int w : V[top])
			{
				result[w] = max(result[w], result[top] + t[w]);
				if (--indegree[w] == 0) q.push(w);
			}
		}

		cout << result[end] << "\n";
	}
	return 0;
}